#include <algorithm>
#include <sstream>
#include <string>
#include <numeric>
#include <iterator>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);

public:
	bool operator<(const Date& d) { return yyyymmdd < d.yyyymmdd;}

private:
	int year, month, day;
	string yyyymmdd;

};

ostream& operator<<(ostream& out, const Date& d)
{
	out << (d.month < 10 ? "0" : "") << d.month << '/' << (d.month < 10 ? "0" : "") << d.day << '/' << d.year;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	getline(in, d.yyyymmdd, ',');   // 1st param is stream, 2nd is where to read to, 3rd is delimiter
//	istringstream(d.yyyymmdd.substr(0,4) >> d.year);
//	istringstream(d.yyyymmdd.substr(4,2) >> d.month);
//	istringstream(d.yyyymmdd.substr(6,2) >> d.day);
	return in;
}


class Expense
{
	friend istream& operator>>(istream&,Expense& );
	friend ostream& operator<<(ostream&, const Expense& );
public:
	bool operator<(const Expense& e) { return dateofPurchase < e.dateofPurchase; }
	operator double() {return amtofPurchase;}

private:
	Date dateofPurchase;
	double amtofPurchase;
	string description;
	string vendor;
};


ostream& operator<<(ostream& out, const Expense& e)
{
	out << e.dateofPurchase;
	return out;
}

istream& operator>>(istream& in, Expense& e)
{
	char comma;
	in >> e.dateofPurchase >> e.amtofPurchase >> comma;
	getline(in, e.description, ',');
	getline(in, e.vendor);	// using newline as delimiter
	return in;
}

class FileException
{
	public:
		FileException(string s) : msg(s){}
		string what() {return msg;}
	private:
		string msg;
};

struct comma_facet : public numpunct<char>
{
	protected:
	string do_grouping() const {return "\003";}
};

string dollarFormat(double amt)
{
	ostringstream oss;
	oss.imbue(locale (oss.getloc(),new comma_facet));
	oss << amt;
	return oss.str();
}


int main()
{
string fname;
try{
	list<Expense> expenses;
	cout << "Enter filename: "; cin >> fname;
	ifstream ifs;
	ifs.open(fname.c_str());	// get c-string from string
	if (not ifs) throw FileException("Error opening input file") ;

	copy(istream_iterator<Expense>(ifs), istream_iterator<Expense>(),back_inserter(expenses));

	expenses.sort();
	cout << dollarFormat(accumulate(expenses.begin(), expenses.end(), 0.0)) << endl;
	copy(expenses.begin(),expenses.end(),ostream_iterator<Expense>(cout,"\n"));
	ofstream ofs("ExpenseReport.txt");	// declare, define, and open filestream object
	copy(expenses.begin(),expenses.end(),ostream_iterator<Expense>(ofs,"\n"));
}
catch(FileException e)
{
	cerr << e.what() << endl;
}
catch(...)
{
	cerr << "Error occured" << endl;
}
}


