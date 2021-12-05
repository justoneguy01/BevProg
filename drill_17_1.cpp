#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a){
	for (int i = 0; i < 10; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
	delete[] a;
}

void print_array(ostream& os, int* a, int n){
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
	delete[] a;
}

void print_vector(vector<int>& a, int n){
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	//array
	int* x = new int[10];
	print_array10(cout, x);
	int* y = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		y[i] = 100 + i;

	}
	print_array10(cout, y);
	int* z = new int[11];
	for (int i = 0; i < 11; ++i)
	{
		z[i] = 100 + i;

	}
	print_array(cout, z, 11);
	int* q = new int[20];
	for (int i = 0; i < 20; ++i)
	{
		q[i] = 100 + i;

	}
	print_array(cout, q, 20);
	//vector
	vector <int> a;
	for (int i = 0; i < 10; ++i){
		a.push_back(100+i);
	}
	print_vector(a, 10);
	vector<int> b;
	for (int i = 0; i < 11; ++i){
		b.push_back(100+i);
	}
	print_vector(b, 11);
	vector <int> c;
	for (int i = 0; i < 20; ++i){
		c.push_back(100+i);
	}
	print_vector(c,20);
	return 0;

}
