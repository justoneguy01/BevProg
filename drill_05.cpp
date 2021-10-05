  #include "std_lib_facilities.h"
int main()
{
	try 
    {
		 //<<your code here>>
     
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) 
    {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
	return 0;
  
        /*Delete this if you want to to test it.("/*")*/
           //  |  //
           //  |  //
           //  V  //
           //     //<<Fixed>>           //<<Original>>

        /*1.*/ /* cout << "Success!\n"; //Cout << "Success!\n"; */

        /*2.*/ /* cout << "Success!\n"; //cout << "Success!\n; */

        /*3.*/ /* cout << "Success" << "!\n"; // cout << "Success" << !\n" */

        /*4.*/ /* cout << "Success!" << "\n"; //cout << success << '\n'; */

        /*5.*/ /* string res = "7"; vector<int> v(10); res = v[5];  cout << "Success!\n"; // string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; */

        /*6.*/ /* vector<int> v(10); v[5] = 7; if (v[5]==7) cout << "Success!\n"; // vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n"; */

        /*7.*/ /* if (true) cout << "Success!\n"; else cout << "Fail!\n";  // if (cond) cout << "Success!\n"; else cout << "Fail!\n"; */
      
        /*8.*/ /* bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n"; // bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; */

        /*9.*/ /* string s = "ape"; bool c = "a"<s; if (c) cout << "Success!\n"; << "Success!\n"; // string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n"; */
      
       /*10.*/ /* string s = "ape"; if (s!="fool") cout << "Success!\n"; // string s = "ape"; if (s=="fool") cout << "Success!\n"; */

       /*11.*/ /* string s = "ape"; if (s!="fool") cout << "Success!\n"; // string s = "ape"; if (s=="fool") cout < "Success!\n"; */
       
       /*12.*/ /* string s = "ape"; if (s!="fool") cout << "Success!\n"; // string s = "ape"; if (s+"fool") cout < "Success!\n";*/

       /*13.*/ /* vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n"; // vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n"; */

       /*14.*/ /* vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; // vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";*/

       /*15.*/ /* string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i]; // string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];*/

       /*16.*/ /* if (true) cout << "Success!\n"; else cout << "Fail!\n"; // if (true) then cout << "Success!\n"; else cout << "Fail!\n";*/

       /*17.*/ /* int x = 2000; int c = x; if (c==2000) cout << "Success!\n"; // int x = 2000; char c = x; if (c==2000) cout << "Success!\n"; */
       
       /*18.*/ /* string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i]; // string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i]; */

       /*19.*/ /* vector<int> v(5); for (int i=1; i<=v.size(); ++i) ; cout << "Success!\n"; // vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";*/
       
       /*20.*/ /* int i=0; int j = 9; while (i<10) i++; if (j<i) cout << "Success!\n"; // int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n"; */

       /*21.*/ /* double x = 2; double d = (5+(x-2.5)); if (d==2*x+0.5) cout << "Success!\n"; // int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";*/

       /*22.*/ /* string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i]; // string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]; */

       /*23.*/ /* int i=0; int j=5;while(i<10) ++i; if (j<i) cout << "Success!\n"; // int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n"; */

       /*24.*/ /* double x = 4; double d = (5/(x-2)); if (d==2*(x-2.75)) cout << "Success!\n"; // int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";*/

       /*25.*/ /* cout << "Success!\n";   // cin << "Success!\n";; */
}