#pragma once
#include<iostream>
#include<stdexcept>


inline int MonthDays(int mm, int yy);
class Date//Available forever.
{
public:
	Date() :yy(2000), mm(1), dd(1) {}
	Date(int y, int m, int d) :yy(y), mm(m), dd(d)//Basic construct
	{ 
		if (dd > MonthDays(m, y))	
			throw std::runtime_error("This is a wrong Month Days!"); 
	}
	Date(int Days,const Date &Genesis);//Construct from the starting date
	int CountDays() const;
	int thisyear() const;
	int restofyear() const;
	int restofmonth() const { return MonthDays(mm, yy) - dd; }
	inline bool IsRun() const;
	void print(std::ostream &out) const;
	int operator-(const Date &obj) const;
	Date operator+(const int Days) const;
private:
	int yy;
	int mm;
	int dd;
};

inline bool isRun(int yy) { if (!yy % 4 &&(yy%100)|| !(yy % 400)) return true; return false; }
inline int yeardays(int yy) { if (isRun(yy)) return 366; return 365; }
