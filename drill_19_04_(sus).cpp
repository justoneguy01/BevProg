#include "../std_lib_facilities.h"

vector<int>* suspicious(){
	vector<int>* p = new vector<int>;
	for (int i; cin >> i;)
	{
		if(i) p->push_back(i);
		else throw exception();
	}
	return p;
}

int main(){
	try{
		vector<int>* p = suspicious();
			for (int i = 0; i < p->size(); ++i){
				cout << p->at(i)<< " ";
			
			cout << endl;

			delete p;

			return 0;	
			}
	}catch(exception& e){
		cerr << "Error" << endl;
		return 1;
	}
}