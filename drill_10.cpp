#include "std_lib_facilities.h"
struct Point{
    double x;
    double y;
};
void is_equal(vector<Point> original_points, vector<Point> processed_points)
{
    if (original_points.size() != processed_points.size())
    {
        cout << "Something's wrong!";
    }
    for (int i = 0; i < original_points.size(); i++){
        if (original_points[i].x != processed_points[i].x){
            cout << "Something's wrong!\n";
            cout << original_points[i].x << " The two vector x value is not equal " << processed_points[i].x << endl;

        }
        if (original_points[i].y != processed_points[i].y){
            cout << "Something's wrong!\n";
            cout << original_points[i].y << " The two vector y value is not equal " << processed_points[i].y << endl;
        }
    }
};
int main ()
{
   double x;
   double y;
   vector<Point> original_points; 

    //Part 1 Felhasználó álltali begépelt értékek

    int value = 0;
    cout << "Enter values like this: x y";
    while(value != 7){
       cin >> x >> y;
       original_points.push_back(Point{x,y});
       value++;
    }

    //Part 1 Fájlból

    /*cout << "Please enter input file name: "; 
    string ifname;
    cin >> ifname; 
    ifstream ist {ifname}; 
    if(!ist) error("Can't open ifile,", ifname);
    while(ist >> x >> y){
        original_points.push_back(Point{x,y});
    }
    ist.close();*/ 
    
    for(const auto& point:original_points)
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}

    string ofname = "mydata.txt";
    ofstream ost {ofname};
    if(!ost) error("Can't open ofile,", ofname);
    for(const auto& point: original_points){
        ost << point.x << " " << point.y << endl;
    }
    ost.close(); 

    // Part 2 második vektor létrehozása

    vector<Point> processed_points; 
    string ifnamee = "mydata.txt";
	ifstream istt {ifnamee};
	if (!istt) error("Can't open input file ", ifnamee);
    while(istt >> x >> y){
    processed_points.push_back(Point{x,y});
    }
    istt.close(); 

    cout << "Original_points: \n";
    for(const auto& point:original_points )
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}

    cout << "Processed_points: \n";
    for(const auto& point:processed_points )
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}
    is_equal(original_points, processed_points);
    return 0;
}