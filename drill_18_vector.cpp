#include "../std_lib_facilities.h"

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(const vector<int> v)
{
	vector<int> lv(v.size());

	for (int i = 0; i < lv.size(); ++i)
		lv[i] = gv[i];

	for (auto el:lv)
		cout << el << ", ";
	cout << endl;

	vector<int> lv2 = v;

	for (auto el:lv2)
		cout << el << ", ";
	cout  << endl;
}

int factorial(int n)
{
	if (n > 1 )
		return n * factorial(n-1);
	else 
		return 1; 
}

int main()
{
	f(gv);
	vector<int> vv(10);
	for (int i = 0; i < vv.size(); ++i)
		vv[i] = factorial(i+1);
	f(vv);

	return 0;
}