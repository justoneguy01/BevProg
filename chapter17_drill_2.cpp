#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n){
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

void print_vector(vector<int>& a, int n){
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	cout << "1.-9. feladat" << endl;
	int a = 7;
	int* p1 = &a;
	cout << "p1 == " << p1 << '\n' << "*p1 == " << *p1 << endl;
	int* b = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		b[i] = pow(2,i);
	}
	int* p2 = b;
	cout << "p2 == " << p2 << endl;
	print_array(cout, b, 7);
	int* p3 = p2;
	p1 = p2;
	p3 = p2;
	cout << "p1 == " << p1 << endl;
	print_array(cout, b, 7);
	cout << "p2 == " << p2 << endl;
	print_array(cout, b, 7);
	delete[] b;
	//array
	cout << endl;
	cout << "10.-12. feladat" << endl;
	int* c = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		c[i] = pow(2,i);
	}
	print_array(cout, c, 10);
	p1 = c;
	int* d = new int[10];
	p2 = d;
	print_array(cout, d, 10);
	for (int i = 0; i < 10; ++i){
		d[i] = c[i];
	}
	cout << "copied array" << endl;
	print_array(cout, d, 10);
	//vector
	cout << endl;
	cout << "13. feladat" << endl;
	vector<int> x;
	for (int i = 0; i < 10; ++i){
		x.push_back(pow(2,i));
	}
	print_vector(x, 10);
	vector<int> y(10);
	print_vector(y, 10);
	for (int i = 0; i < 10; ++i){
		y[i] = x[i];
	}
	cout << "copied vector" << endl;
	print_vector(y, 10);
	return 0;
}