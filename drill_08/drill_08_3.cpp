# include "../std_lib_facilities.h"

namespace X 
{
 	int var = 0;
        void print()
        {
            cout << var << '\n';
        }

}
namespace Y 
{
	int var = 0;
        void print()
        {
            cout << var << '\n';
        }
}

namespace Z 
{
 	int var = 0;
        void print()
        {
            cout << var << '\n';
        }
}

int main(){
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
        print();
        {
            using Z::var;
            using Z::print;
            var = 11;
            print();
        }
	print();
	X::print();
}