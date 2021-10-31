#include "../std_lib_facilities.h"
   
    void swap_v(int a, int b)
    {
        int tmp = a;
        a = b;
        b = tmp;

    }
    void swap_r(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    //void swap_cr(const int& a, const int& b)     //can't swap constant values
    //{              
    //    int temp = a;
    //    a = b;
    //    b = temp;
    //}
    int main()
    {
        int x = 7 ;
        int y = 9 ;

        swap_v(x,y);
        cout << "the value of x = " << x << endl;
        cout << "the value of y = " << y << endl;   
        cout << endl;
        swap_r(x,y);                              // replace ? by v, r, or cr
        cout << "the value of x = " << x << endl;  
        cout << "the value of y = " << y << endl;   
        cout << endl;
        swap_v(7,9);
        cout << "the value of x = " << x << endl;  
        cout << "the value of y = " << y << endl;  

        //const int cx = 7;
        //const int cy = 9;
        //swap_cr(cx,cy);
        //cout << "the value of cx = " << cx << endl; 
        //cout << "the value of cy = " << cy << endl; 
        //swap_?(cx,cy);                                
        //swap_?(7.7,9.9); 
        //double dx = 7.7;                           //Can't swap because its double                      
        //double dy = 9.9;                           //Can't swap because its double   
        //swap_?(dx,dy);
        //swap_?(7.7,9.9);
        return 0;
    }

