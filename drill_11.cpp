#include "std_lib_facilities.h"
int main ()
{
    int birth_year = 2003;
    cout << "Decimal:\t" << birth_year << "\n";
    cout << "Hexadecimal:\t" << hex << birth_year << "\n";
    cout << "Octal:\t\t" << oct << birth_year << "\n";

    cout << "Age:";
    cout << dec << 18 << "\t(Decimal)\n";
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d; // dec(a) oct(b) hex(c,d)

    cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;
    cout << defaultfloat << 1234567.89 << "\t" << fixed << 1234567.89 << "\t" << scientific << 1234567.89 << "\n";

    cout << "|" << setw(2) << "Last_name"<< "\t|"<< setw(8) << "First_name" << "\t|" << setw(16) << "Telephone number" << "\t|" << setw(25) << "Email_address" << "|\n";
    cout << "|" << setw(2) << "Kolompár"<< "\t|" << setw(8) << "Géza"  << "\t|" << setw(16) << "06 20 2234 367" << "\t|" << setw(25) << "kolompargeza@gmail.com"      << "|\n";
    cout << "|" << setw(2) << "Mészáros"<< "\t|" << setw(8) << "Bence" << "\t|" << setw(16) << "06 20 7234 568" << "\t|" << setw(25) << "meszarosbence@gmail.com"    << "|\n";
    cout << "|" << setw(2) << "Szilágyi"<< "\t|" << setw(8) << "Béla"  << "\t|" << setw(16) << "06 70 6334 569" << "\t|" << setw(25) << "szilagyibela@gmail.com"   << "|\n";
    cout << "|" << setw(2) << "Lakatos" << "\t|" << setw(8) << "Dezső" << "\t|" << setw(16) << "06 30 3234 987" << "\t|" << setw(25) << "lakatosdezso@gmail.com" << "|\n";
    cout << "|" << setw(2) << "Rézműves"<< "\t|" << setw(8) << "György"<< "\t|" << setw(16) << "06 30 1234 587" << "\t|" << setw(25) << "rezmuvesgyorgy@gmail.com"   << "|\n";
    cout << "|" << setw(2) << "Horváth" << "\t|" << setw(8) << "Sándor"<< "\t|" << setw(16) << "06 70 5234 877" << "\t|" << setw(25) << "horvathsandor@gmail.com"<< "|\n";
    
    return 0;
}