#pragma once

# include <iostream>
# include <string>
# include <math.h>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <cstdio>

using namespace std;

class Time
{

public:
	Time();
	Time(int hour, int min, int sec);
	~Time();

	void SetTime();
	int GetHour();
	int GetMin();
	int GetSec();

	static Time ConvertSecToTime(int& secNum);
	static int ConvertTimeToSec(Time& t);

	int operator - (Time& subTime);
	int operator + (Time& subTime);

private:
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};
