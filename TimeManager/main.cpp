#include<iostream>
#include"Date.h"
using std::cout;

int main()
{
	Date a(2000, 9, 21);
	a.print(cout);
	a = a + 30;
	a.print(cout);
	system("pause");
}