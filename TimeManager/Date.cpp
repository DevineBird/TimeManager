#include "Date.h"
#include <iostream>

Date::Date(int Days, const Date & Genesis)
{
	int rest = Genesis.restofyear();
	int y = Genesis.yy;
	int m = Genesis.mm;
	int d = Genesis.dd;
	if (Days > rest)
	{
		Days -= rest;
		y += 1;
		while (Days > yeardays(y))
		{
			Days -= yeardays(y);
			y++;
		}
		m = 1;
	}

	
	if (Days > restofmonth())
	{
		Days -= restofmonth();
		m += 1;
		while (Days > MonthDays(m, isRun(y)))
		{
			Days -= MonthDays(m, y);
			m++;
		}
		d = 0;
	}
	this->yy = y;
	this->mm = m;
	this->dd = d + Days;
}

int Date::CountDays() const
{
	int All = 0;
	for (int y = 2000; y < yy; y++)
	{
		if (isRun(y))All += 366;
		else All += 365;
	}

	for (int m = 1; m < mm; m++)
	{
		All += MonthDays(m, IsRun());
	}

	All += dd;
	return All;
}

int Date::thisyear() const
{
	int All = 0;
	for (int m = 1; m < mm; m++)
	{
		All += MonthDays(m, IsRun());
	}

	All += dd;
	return All;
}

int Date::restofyear() const
{
	if (IsRun()) return 366 - thisyear();
	return 365 - thisyear();
}

bool Date::IsRun() const
{
	return isRun(yy);
}

void Date::print(std::ostream & out) const
{
	std::cout << "yy:" << yy << "mm:" << mm << "dd:" << dd << std::endl;
}

int Date::operator-(const Date & obj) const
{
	return this->CountDays() - obj.CountDays();
}

Date Date::operator+(const int Days) const//灵光一闪，这段代码写得还不错
{
	return Date(Days,*this);
}

inline int MonthDays(int mm, int yy)
{
	switch (mm)
	{

	case 1:return 31;
	case 2:if (isRun(yy)) return 28; else return 29;
	case 3:return 31;
	case 4:return 30;
	case 5:return 31;
	case 6:return 30;
	case 7:return 31;
	case 8:return 31;
	case 9:return 30;
	case 10:return 31;
	case 11:return 30;
	case 12:return 31;
	default:
		std::cerr << "Month out of range";
		return 0;
		break;
	}
}