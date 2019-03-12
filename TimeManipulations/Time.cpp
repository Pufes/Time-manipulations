#pragma once

# include "Time.h"

using namespace std;

Time::Time()
{
	this->hour = this->min = this->sec = 0;
}

Time::Time(int hour, int min, int sec)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

Time::~Time()
{

}

void Time::SetTime()
{
	bool cor = true;
	int hour, min, sec;

link:
	cout << "Please, set the time: " << endl;
	cout << "Set hours: ";
	cin >> hour; //cout << endl;
	cout << "Set minutes: ";
	cin >> min; //cout << endl;
	cout << "Set seconds: ";
	cin >> sec; //cout << endl;

	if (sec < 0 or min < 0 or hour < 0)
	{
		cout << "All Time fields must be positive numbers!" << endl << endl;
		goto link;
	}
	else if (sec < 60)
	{
		this->sec = sec;
	}
	else
	{
		this->sec = sec % 60;
	}

	this->min = min + (sec - (sec % 60)) / 60;

	if (this->min >= 60)
	{
		min = this->min;
		this->min = this->min % 60;
	}

	this->hour = hour + (min - (min % 60)) / 60;
}

int Time::GetHour()
{
	return this->hour;
}

int Time::GetMin()
{
	return this->min;
}

int Time::GetSec()
{
	return this->sec;
}

Time Time::ConvertSecToTime(int& secNum)
{
	Time resTime(0, 0, 0);

	if (secNum < 60)
	{
		resTime.sec = secNum;
		return resTime;
	}
	else
	{
		resTime.sec = secNum % 60;
		resTime.min = (secNum - resTime.sec) / 60;
		if (resTime.min <= 60)
		{
			return resTime;
		}
		else
		{
			resTime.hour = (resTime.min - resTime.min % 60) / 60;
			resTime.min = resTime.min % 60;
			return resTime;
		}
	}
}

int Time::ConvertTimeToSec(Time & t)
{
	return t.sec + t.min*60 + t.hour*3600;
}

int Time::operator-(Time & subTime)
{	
	int m = Time::ConvertTimeToSec(*this), 
		s = Time::ConvertTimeToSec(subTime),
		resSec = 0;

	if (m >= s)
	{	
		resSec = m - s;
		return resSec;
	}
	else
	{
		resSec = s - m;
		return resSec;
	}
};

int Time::operator+(Time & subTime)
{
	int a1 = Time::ConvertTimeToSec(*this),
		a2 = Time::ConvertTimeToSec(subTime),
		resSec = 0;

		resSec = a1 + a2;
		return resSec;
	
};



