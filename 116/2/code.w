



PSEUDOCODE


// create house class




// obtain user input on number of house to create
// obtain plot coordinates of house_object1 & house_object2

// create object1 of class house
// create object2 of class house

// interpolate intermediate house_objectx

// draw all house_object




#include <iostream>

class Street
{
   public:
      

};


class Coord
{
   public:
      int x_coor = 0 ;
      int y_coor = 0 ; 
};



class House
{
public:
   int x = 0 ;		// use Coord class instead?
   int y = 0 ;

   // Below are plot points for the house

   Point house_ul(x-5, y+3) ;
   Point house_ur(x+5, y+3) ;
   Point house_ll(x-5, y-3) ;
   Point house_lr(x+5, y-3) ;

   Point roof_l(x-3, y+5) ;
   Point roof_r(x+3, y+5) ;

   // Point window(x+3, y+1.5) ;
   Point window_l(x + 2.25, y + 1.25) ;
   Point window_r(x + 3.75, y + 1.25) ;
   Point window_t(x + 3, y + 2.25) ;

   Point door_handle(-0.5, y - 1.25) ;

   Point door_ul(x-2.5, y+1) ;
   Point door_ur(x, y+1) ;
   Point door_ll(x-2.5, y-3) ;


   // Below are the lines for the house

   Line house_top(house_ul, house_ur) ;
   Line house_left(house_ul, house_ll) ;
   Line house_right(house_ur, house_lr) ;
   Line house_bottom(house_ll, house_lr) ;

   Line roof_top(roof_l, roof_r) ;
   Line roof_left(roof_l, house_ul) ;
   Line roof_right(roof_r, house_ur) ;

   Line door_top(door_ul, door_ur) ;
   Line door_side(door_ul, door_ll) ;

   Line window_left(window_l, window_t) ;
   Line window_right(window_r, window_t) ;


   void Plot{};		// plots the house


};


void House:Plot()	// member function definition
{
   cwin << house_top << house_left << house_right << house_bottom ;
   cwin << roof_top << roof_left << roof_right ;
   cwin << Circle(door_handle, 0.25) ;
   cwin << door_top << door_side ;
   cwin << window_left << window_right ;

   door_side.move(2.5, 0) ;
   window_left.move(0.75, -1) ; 
   window_right.move(-0.75, -1) ; 

   cwin << door_side << window_left << window_right ;

}




int main()
{
   House house1 ;
   House house2 ;

   Coord coord1 ;
   Coord coord2 ;

   int house_number = 0 ;


   cout << "How many houses (1-5) are to be plotted? " ;
   cin << house_number ;

   cout << "Enter x coordinates of first house: " ;
   cin << coord1::x_coor ;
   cout << "Enter y coordinates of first house: " ;
   cin << Coord1::y_coor ; 

   cout << "Enter x coordinates of last house: " ;
   cin << coord2::x_coor ;
   cout << "Enter y coordinates of last house: " ;
   cin << Coord2::y_coor ; 













}








\\ g++ -mwindows -Isource_code\cccfiles lab2.cpp source_code\cccfiles\ccc.msw.cpp source_code\cccfiles\ccc_shap.cpp -lgdi32











