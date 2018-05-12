#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Date.h"


class Job
{
public:
	Job();
	Job(std::istream &in);
	~Job();
	Job &work();
	Job &adjust(std::istream &in);
	void print(std::ostream &out) const;

private:
	const Date Setday;//The day to set the Job && Starting day!
	std::string name;//name of the job
	double TimePD;//Time spent per day
	int Concequence;
	std::string places = "West";
	int Total_Times = 1;//the total times
	std::vector<Date> Distribute;//Distribute the Jobs to Dates and save
	std::string Connotation = 0;
};
