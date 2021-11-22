#include "../../std_lib_facilities.h"

struct Token {
	char kind; //Létrehozzuk a token struktúrát, 3 változóval, a típussal, értékkel, és névvel
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { } //Token a karaktereknek mint: ;,(, stb.
	Token(char ch, double val) :kind(ch), value(val) { } //Token a számoknak
	Token(char ch, string s): kind(ch), name(s) {}  //Token a váltizók deklarálásához
	//Első compile hiba, enélkül a sor nélkül nem tudunk string-es tokeneket feldolgozni

};

class Token_stream 
{
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer=t; full=true; } 
	void ignore(char);
};
//Token stream osztály függvényeinek definiálása


const char set ='S';
const char let = 'L';
const char quit = 'q'; 
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqr='r';
const char power='P';
const string close = "exit";
const string declarkey = "#";
const string redeclar ="set";
const string squareroot="sqrt";
const string powerof="pow";
//Konstantsok tokenek kezeléséhez

Token Token_stream::get()  //Egy karakter bekérése az input streamből, majd abból Token készítése
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case quit: //Első logikai hiba, kell a 'q' a kilépéshez
	case '=':
	case ',':
		return Token(ch); //Ez az első típusó Token
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget(); // Mivel egy szám karaktert találtunk, azt vissza kell raknunk az input streambe, hogy ki tudjuk kérni a szám egészét
		double val;
		cin >> val; //A szám egészének bekérése val változóba
		return Token(number,val); //Szám típusó Token visszaadása
	}
	default:
		if ((isalpha(ch)) || (ch=='#'))  //Változók kezelése
		{
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch; // Második logikai hiba, alapból mindig felülírja az s karaktert, hozzá kell fűzni.
			cin.unget();
			if (s == declarkey) return Token(let);
			if (s == redeclar) return Token(set);
			if (s == squareroot) return Token(sqr);
			if (s == powerof) return Token(power);
			if (s == close) return Token(quit);
			return Token(name,s);
			//Különféle föggvényekhez tartozó kulcsszólhoz Token rendelése
		}
		cin.putback(';');
		error("Bad token");
		
	}
	return 0; //Második hiba, bár enélkül is lefordul a program, vissza kell térnünk az error után is valamivel.
}

void Token_stream::ignore(char c) //Error kezelés utáni további számolás lehetővé tétele
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;  //Amíg eljut a c karakterig folyamatosan kéri be az input streamből a változókat
}

struct Variable { //Változókhoz szükséges struktúra elkészítése, melynek van neve, és értéke.
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { } //Példa változó elkészítése
};

vector<Variable>names;	//A változók eltárolására egy vektor deifiniálása

double get_value(string s)
{
	for (auto& v : names ) //Második logikai hiba, a változók megadásakor
		if (v.name == s) return v.value;
	cin.putback(';');
	error("get: undefined name ",s);
	
	return 0; //Harmadik hiba, bár enélkül is lefordul a program, vissza kell térnünk az error után is valamivel.
	//Ha kaptunk egy változót, megnézzük az benne van-e a változó táblában, ha igen visszaadjuk értéket, ha nem errort adunk.
}

void set_value(string s, double d) //Változók újradeklarása
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	cin.putback(';');
	error("set: undefined name ",s);
	
}

bool is_declared(string s)  //Függvény arra, hogy ne tudjunk kétszer deklarálni egy változót.
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; //Egy deklaráció a Token_stream-ből, hogy tudjuk használni.

double expression(); //Egy deklaráció az expression-ből, hogy tudjuk használni.

double primary()
{
	Token t = ts.get();
	switch (t.kind) 
	{
		case '(':
		{	
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d; // Harmadik logika hiba, vissza kell térni a d-vel, hogy működjön a zárójel.
		}
		case number:
			return t.value;
		case '-':
			return - primary(); //Negatív számok kezelése
		case name:
			return get_value(t.name); //Változó értékének bekérése
		default:
			cin.putback(';');
			error("primary expected");
	}
	return -1; //Negyedik hiba, bár enélkül is lefordul a program, vissza kell térnünk az error után is valamivel.
}

double term()  //Szorzás és osztás kezelése, errorkezelés
{
	double left = primary();
	Token t = ts.get();  
	while(true) {
		
		switch(t.kind) {
			case '*':
				left *= primary();
				t=ts.get();
				break;
			case '/':
			{	double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t=ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
			}
			default:
				ts.unget(t);
				return left;
		}
	}
}

double expression() //Összeadás és kivonás kezelése
{
	double left = term();
	Token t = ts.get(); //
	while(true) {
		switch(t.kind) 
		{
			case '+':
				left += term();
				t=ts.get();
				break;
			case '-':
				left -= term();
				t=ts.get();
				break;
			default:
				ts.unget(t);
				return left;
		}
	}
}

double declaration()  //Változó deklarálása
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

double powerx() //Hatványozás megvalósítása
{
	Token t1=ts.get();
	if (t1.kind!='(') error("'(' expected at the beginning of pow ");
	double base=expression();
	Token t2=ts.get();
	if (t2.kind!=',') error("',' expected at between the two numbers in pow");
	double tmpexp=expression();
	int exp = narrow_cast<int>(tmpexp);
	Token t3=ts.get();
	if (t3.kind!=')') error("')' expected at the end of pow ");
	if (exp==0) return 1;
	else if (exp ==1 ) return base;
	double result=base;
	for (int i=1; i<exp;i++)
	{
		result*=base;
	}
	return result;
}

double fsqrt() //Gyökvönás megvalósítása
{
	double d=expression();
	if (d <0) error("Can't take the squareroot of a negative number in the domain of real numbers");
	else
		{
		return sqrt(d);
		}
	return 0;
}	


double statement() //Eldöntjük mit kaptunk, egy számot, változó deklarálást, gyökvonást vagy hatványozást
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case sqr:
		return fsqrt();
	case power:
		return powerx();
	case set: //Nemtudom ez vehető-e harmadik logikai hibának, de meg volt írva a set_value függvény, és nem volt használva, ezért megcsináltam, hogy működjön.
		{
		Token t1=ts.get();
		if (is_declared(t1.name))
		{
			Token t2 = ts.get();
			if (t2.kind != '=') error("= missing in redeclaration of " ,name);
			double d=expression();
			set_value(t1.name, d);
		}
		
		else (error("Can't redeclar a variable if it wasn't declared in the first place."));

		}
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()  //Error utáni számolás lehetővé tétele
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();  //Megnézzük a kulcskaraktereket, mint q és ;
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
	try {
		names.push_back(Variable("k",1000)); //Változó előre definiálása
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
