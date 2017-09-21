/** Lab #2 by Henry Hsu
*/

#include "ccc_win.h"

using namespace std;

class House
{
   public:
      House();

      void plot(Point h);

   private:
};

class Street
{
   public:
      Street();

      void plot(Point h1, Point h2, int housenum);
   private:
};


House::House() {}

void House::plot(Point h)
{
   double x = h.get_x();
   double y = h.get_y();

   // Below are plot points for the house

   Point house_ul(x-.7, y+.3) ;
   Point house_ur(x+.7, y+.3) ;
   Point house_ll(x-.7, y-.3) ;
   Point house_lr(x+.7, y-.3) ;

   Point roof_l(x-.2, y+.6) ;
   Point roof_r(x+.2, y+.6) ;

   Point window(x+.35, y+.1) ;
   Point window_l(x + .2, y + .1) ;
   Point window_r(x + .5, y + .1) ;
   Point window_t(x + .35, y + .25) ;

   Point door_handle(x-0.2, y - .125) ;

   Point door_ul(x-.5, y+.125) ;
   Point door_ur(x-.1, y+.125) ;
   Point door_ll(x-.5, y-.3) ;

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


   // Displays the house
   cwin << house_top << house_left << house_right << house_bottom ;
   cwin << roof_top << roof_left << roof_right ;
   cwin << Circle(door_handle, 0.075) ;
   cwin << door_top << door_side ;
   cwin << window_left << window_right ;

   door_side.move(.4, 0) ;
   window_left.move(0.15, -.15) ;
   window_right.move(-0.15, -.15) ;

   cwin << door_side << window_left << window_right ;
}


Street::Street () {}


void Street::plot(Point h1, Point h2, int housenum)
{
   int interpolated = housenum - 1;
   double h1x = h1.get_x();
   double h1y = h1.get_y();
   double h2x = h2.get_x();
   double h2y = h2.get_y();
   double init_x = h1x;
   double init_y = h1y;
   double slope_x = (h2x - h1x) / interpolated;
   double slope_y = (h2y - h1y) / interpolated;

   int i = 0;
   for (i=1; i < interpolated; i++)
   {
      init_x = init_x + slope_x;
      init_y = init_y + slope_y;
      House housei;
      Point p1 (init_x, init_y);
      housei.plot(p1);
   }
}


int ccc_win_main()
{
   int h1x = 0, h1y = 0, h2x = 0, h2y = 0, housenum = 2;
   cwin.coord (-10, 10, 10, -10);

   do
   {
      housenum = cwin.get_int("How many houses (from 3 to 10) are to be plotted? ");
   } while (housenum < 3 or housenum > 10);

   House house1;
   House house2;

   Point h1 = cwin.get_mouse("Please click on coordinate for the first house.");
   Point h2 = cwin.get_mouse("Please click on coordinate for the last house.");

   house1.plot(h1);
   house2.plot(h2);

   Street street1;

   street1.plot(h1, h2, housenum);

   int i = 0;
   for (i=1; i < housenum; i++)
   {
      int mailingi = cwin.get_int("Enter a house number.");
      Point pi = cwin.get_mouse("Click on the house to append this number to.");
      cwin << Message (pi, mailingi);
   }

return 0;
}
