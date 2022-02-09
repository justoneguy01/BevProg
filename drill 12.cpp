#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>


using namespace  Graph_lib;
//g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -o a2.out
int main(){
	
	try {
	
	Point t1 {100, 100}; //pont létrehozása
	Simple_Window win {t1, 600, 400, My Window};
	win.wait_for_button();
	Axis x {Axis::x, Point{20, 300},280 , 10, "x axis"}; //x tengely
	win.attach(x);
	Axis x {Axis::y, Point{20, 300},280 , 10, "y axis"}; //y tengely 280 hosszu 10 részre van osztva
	y.set_color(Color::cyan);
	y.label.set_color(Color::dark_red);
	win.attach(y);
	
	Function sine (sin, 0, 100, Point{20, 150},1000 ,50 ,50};
	win.attach(sine);
	win.wait_for_button();
	} catch(exception& e){
		cerr<<"exception: " << e.what() << '/n';
		return 1;
	}catch(...) {
		cerr<< "error/n";
		return 2;
	
	}
		
