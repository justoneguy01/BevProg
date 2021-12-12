#include "../std_lib_facilities.h"

int ga [10] = {1,2,4,8,16,32,64,128,256,512}; //1.

void f(const int name[], int elements)	  //2,3.
{
	int la [10];
	for (int i = 0; i < elements; ++i)
		la [i] = ga [i];

	for (int i = 0; i < elements; ++i)
		cout << la[i] << ", ";
		cout << endl;

	int* p = new int[elements];

	for (int i = 0; i < elements; ++i)
		p[i] = name[i];
	for (int i = 0; i < elements; ++i)
		cout << p[i] << ", ";
		cout << endl;
	
	delete[] p;
}

int factorial(int n)
{
	if (n > 1 )
		return n * factorial(n-1);
	else 
		return 1; 
}

int main()	//4.
{
	f(ga, 10);
	int aa[10];
	for (int i = 0; i < 10; ++i)
		aa[i] = factorial(i+1);
	f(aa,10); 


	return 0;
}