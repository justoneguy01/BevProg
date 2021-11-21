#include "std_lib_facilities.h"

class Date{
private: //ezeket kívülről nem tudjuk majd elérni
    int year, month, day; //3 privát tag a Classnak
public:   //ezeket eltudjuk érni.
    Date(int y, int m, int d); //Konstruktor: segítségével megtudjuk határozni hogyan jöjjön létre az objektum
    void add_day(int n);
    //getter függvény: eltudjuk kérni a tagnak az értékét -> kiíratás
    int get_year() {return year;}
    int get_month() {return month;}
    int get_day() {return day;}

    //setter függvények: betudjuk állítani az értéket
    void set_year(int y){
        if (y > 0){
            year = y;
        }
        else{
            error("Invalid year in set_year().");
        }
    }
    void set_month(int m){
        if (m > 0 && m <=12){
            month = m;
        }
        else{
            error("Invalid month in set_month().");
        }
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

Date::Date(int y, int m, int d)
{
    if (y > 0)
    {
        year = y;
    }
    else
    {
        error("Invalid year.");
    }
    if (m <= 12 && m > 0)
    {
        month = m;
    }
    else
    {
        error("Invalid month.");
    }
    if (d <= 31 && d > 0)
    {
        day = d;
    }
    else
    {
        error("Invalid day.");
    }
}

void Date::add_day(int n)
{ //Hozzáad valamennyi napot egy paraméterül adott naphoz.

    day += n;
    while (day > 31)
    {
        month++;
        day -= 31;
        if (month > 12)
        {
            year++;
            month -= 12;
        }
    }
}

int main()
{
    try
    {

        Date today {2021, 12, 31}; //Példány készítése

        std::cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";
        today.add_day(4);
        std::cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";

        
        today.set_year(2021);
        today.set_month(12);
        today.set_day(31);
        std::cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";
       


        return 0;
    }
    catch (exception &e)
    {
        cerr << e.what();
        return 1;
    }
}