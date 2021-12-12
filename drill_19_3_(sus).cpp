#include "../std_lib_facilities.h"

void suspicious(int size, int x){
	int* p = new int[size];
	if(x==0) throw exception();
	delete[] p;
}

int main()
{
	try{
		suspicious(5,0);
		return 0;
	}catch(exception& e){
		cerr << "Error" << endl;
		return 1;
	}
}