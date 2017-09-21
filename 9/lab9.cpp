#include "ccc_win.h"
#include <iostream>
#include <vector>

using namespace std;

class Chart			// abstract class, cannot be instantiated due to pure virtual function
{
	public:
		Chart(vector <int> chart_data):data(chart_data){}
		virtual void draw(Point& p) = 0;	// pure virtual member function

	protected:
		vector <int> data;
};


class PieChart:public Chart
{
	public:
		PieChart(vector <int> pie_data):Chart(pie_data){}
		virtual void draw(Point& p)
		{
			double x = p.get_x();
			double y = p.get_y();

			Point center (x, y);

			cwin << Circle(p, 4);

			Point rim1(x - 4, y);
			Point rim2(x - 3, y + 2.65);
			Point rim3(x + 1, y + 3.85);
			Point rim4(x + 3, y - 2.65);

			Line slice1(center, rim1);
			Line slice2(center, rim2);
			Line slice3(center, rim3);
			Line slice4(center, rim4);

			Point msg1(x - 3, y + 1.25);
			Point msg2(x - 1, y + 2.75);
			Point msg3(x + 2, y + 0.5);
			Point msg4(x - 1, y - 2);

			cwin << slice1 << slice2 << slice3 << slice4;
			cwin << Message (msg1, "10%");
			cwin << Message (msg2, "20%");
			cwin << Message (msg3, "30%");
			cwin << Message (msg4, "40%");
		}
};


class BarChart:public Chart
{
	public:
		BarChart(vector <int> bar_data):Chart(bar_data){}

		virtual void draw(Point& p)
		{
			double x = p.get_x();
			double y = p.get_y();
			int bar_num = data.size();

			for (int i = 0; i < bar_num; i++)
			{
				Point ll((x - 0.25) + (1.5*i), y);
				Point lr((x + 0.25) + (1.5*i), y);
				Point ul((x - 0.25) + (1.5*i), y + (data[i]/10));
				Point ur((x + 0.25) + (1.5*i), y + (data[i]/10));
				Point msg((x - 0.25) + (1.5*i), y - 0.25);

				Line left(ll, ul);
				Line right(lr, ur);
				Line top(ul, ur);
				Line bottom(ll, lr);

				cwin << left << right << top << bottom ;
				cwin << Message (msg, data[i]);
			}
		}
};

int ccc_win_main()
{
	vector <int> chart_data;

	chart_data.push_back(10);
	chart_data.push_back(20);
	chart_data.push_back(30);
	chart_data.push_back(40);

	Point p_center (-5, 3), b_center (2, -6);
	PieChart Pie(chart_data);
	BarChart Bar(chart_data);

	Pie.draw(p_center);
	Bar.draw(b_center);
}












