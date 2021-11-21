#include "std_lib_facilities.h"

class Year{
    static constexpr int min = 1800;
    static constexpr int max = 2200;
public:
    class Invalid{};
    Year(int x): y{x} {if (x < min || x > max ) throw Invalid{};}
    int year() {return y;} //get függvény
    int increment() {y++;}
private:
    int y;

};

Year operator++(Year& year){ //lépteti az évet
    year.increment();
    return year;
}

ostream& operator<<(ostream& os, Year year){ //kiíratás
    return os << year.year();
}


const vector<string> months = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

enum class Month {
    jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec
};

Month operator++(Month& m){ //Monthal térünk vissza
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

//kiiratás:
ostream& operator<<(ostream& os, Month m){
    return os << months[int(m)];
}

class Date{
private: //ezeket kívülről nem tudjuk majd elérni
    Year year;
    Month month;
    int day; //3 tag a structnak
public:   //ezeket igen
    class Invalid{};
    //default constructor létrehozása vektor miatt
    Date(): year(Year{2001}), month(Month::jan), day(1) {}
    Date(Year y, Month m, int d): year(y), month(m), day(d){ if(!is_valid()) throw Invalid{}; } //Konstruktor: segítségével megtudjuk határozni hogyan jöjjön létre az objektum
    void add_day(int n); //nap hozzáadása

    //Dátum ellenörzése, hogy érvényes-e
    bool is_valid();

    //getter függvény: eltudjuk kérni a tagnak az értékét -> kiíratás
    Year get_year() const {return year;}
    Month get_month() const  {return month;}
    int get_day() const  {return day;}

    

    //setter függvények: betudjuk állítani az értéket
    void set_year(Year y){

        year = y;
        
    }
    void set_month(Month m){

        month = m;

    }
    void set_day(int d){
        if (d > 0 && d <=31){
            day = d;
        }
        else{
            error("Invalid day in set_day().");
        }
    }

};

bool Date::is_valid(){
    if (day <1 || day > 31) return false;
    return true;
}

void Date::add_day(int n)
{ //Hozzáad valamennyi napot egy paraméterül adott naphoz.

    day += n;
    while (day > 31)
    {
        ++month;
        day -= 31;
        if (month == Month::jan)
        {
            ++year;
        }
    }
}
ostream& operator<<(ostream& os,  Date& d){
    return os << d.get_year() << ". " << d.get_month() << " " <<d.get_day() << ".\n";
}
int main()

    try
    {

        Date today {Year{2021}, Month::dec, 23}; //Példány készítése
        std::cout << "Date: " << today;
        
        today.add_day(1); 
        std::cout << "Tomorrow: " << today;


        return 0;
    }
    catch (exception &e){
        cerr << e.what();
        return 1;
    }catch (Date::Invalid){
        cerr << "Exception: Invalid date.";
        return 2;
    }catch (Year::Invalid){
        cerr << "Exception: Invalid year.";
        return 3;
    }