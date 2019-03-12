# include <iostream>
# include <string>
# include <math.h>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <cstdio>
#include <conio.h>
#include <time.h>
#include <stdio.h>

#include "Time.h"

// Время задается в формате час, минута, секунда. Реализовать:
// 1) вычитание из времени указанного пользователем количества секунд;
// 2) подсчёт числа секунд между двумя моментами времени, лежащими в пределах одних суток.

using namespace std;

int main()
{	
	setlocale(LC_ALL, "en");

	time_t currentTime;
	int menu, difference = 0, sum = 0, currentTimeSec;
	Time t,ts,t1,t2;

	currentTimeSec = time(&currentTime);
	t = Time::ConvertSecToTime(currentTimeSec);
	#pragma warning(suppress : 4996)
	cout << "Current system time and date:	" << ctime(&currentTime);
	cout << "Which is " << t.GetHour() <<" hour(s) "<< t.GetMin() << " minute(s) " << t.GetSec() << " seconds(s) ";
	cout << " from 01.01.1970" << endl;
	cout << "========================================================================" << endl;


menu_start:
	cout << "\n\nPress '1' to reset current time " << endl 
		<< "Press '2' to subtract time from current time" << endl 
		<< "Press '3' to calculate the difference between two time moments wihin one day" << endl
		<< "Press '4' to add time to current time" << endl
		<<"Press '0' to exit"<<endl << endl;
	cin >> menu;

	switch (menu)
	{
		case 1:
		{
			t.SetTime();
			cout << t.GetHour() << " hour(s) " << t.GetMin() << " minute(s) " << t.GetSec() << " seconds(s) ";
			t.GetHour();
			t.GetMin();
			t.GetSec();

			goto menu_start;
			break;
		}
		case 2:
		{	
			int subTimeSec = 0;
			cout << "Please, enter number of second to subtract: " << endl;
			cin >> subTimeSec;

			while (subTimeSec < 0)
			{
				cout << "Number of seconds is worng! Please, enter another number: " << endl;
				cin >> subTimeSec;
			}

			ts = Time::ConvertSecToTime(subTimeSec);
			if (subTimeSec <= Time::ConvertTimeToSec(t))
			{
				difference = t - ts;
				ts = Time::ConvertSecToTime(difference);
				t = ts;
			}
			else
			{
				cout << "Error! Entered time is greater than initial time!" << endl;
				goto menu_start;
			}

			cout << "Resulting time: ";
			cout << ts.GetHour() << " hour(s) " << ts.GetMin() << " minute(s) " << ts.GetSec() << " seconds(s) "; 
			goto menu_start;
			break;	
	}
		case 3:
		{	cout << "----------------------" << endl;
			cout << "Minuend time setting: " <<endl;
			cout << "----------------------" << endl;
			t1.SetTime();
			cout << "----------------------" << endl;
			cout << "Subtrahend time: " << endl;
			cout << "----------------------" << endl;
			t2.SetTime();

			if (Time::ConvertTimeToSec(t1) > 86400 or Time::ConvertTimeToSec(t2) > 86400)
			{
				cout << "Error! Minuend or subtrahend time is a period of time greater than one day!";
				goto menu_start;
			}

			difference = abs(Time::ConvertTimeToSec(t2) - Time::ConvertTimeToSec(t1));
			t2 = Time::ConvertSecToTime(difference);

			cout << "Difference between minuend and subtrhend time is " << difference << " second(s) " << endl;
			cout << difference << " second(s) = " << t2.GetHour() << " hour(s) " << t2.GetMin() << " minute(s) " << t2.GetSec() << " second(s) "; 
			goto menu_start;
			break;
	}
		case 4:
		{
			int subTimeSec = 0;
			cout << "Please, enter number of second to add: " << endl;
			cin >> subTimeSec;

			while (subTimeSec < 0)
			{
				cout << "Number of seconds is worng! Please, enter another number: " << endl;
				cin >> subTimeSec;
			}

			ts = Time::ConvertSecToTime(subTimeSec);
			
				sum = t + ts;
				ts = Time::ConvertSecToTime(sum);
				t = ts;

			cout << "Resulting time: ";
			cout << ts.GetHour() << " hour(s) " << ts.GetMin() << " minute(s) " << ts.GetSec() << " seconds(s) ";
			goto menu_start;
			break;
		}
		case 0:
		{
			break;
		}
	default:
		cout << "Wrong action!" << endl;
		goto menu_start;
		break;
	}
	system("pause");
	return 0;
}