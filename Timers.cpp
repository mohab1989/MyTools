#include"Timers.h"
#include<Windows.h>
Timers::Timers()
{
	scaling =0;
	num_timers=0;
	start_times.clear();
	pc_frequencies.clear();
}
int Timers::start_timer(Timers::time_unit tu)
{
	switch (tu)
	{
	case Timers::seconds:
		scaling = 1.0;
		break;
	case Timers::milliseconds:
		scaling = 1000.0;
		break;
	case Timers::microseconds:
		scaling = 1000000.0;
		break;
	default:
		break;
	}

	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
	{
		printf("QueryPerformanceFrequency failed!\n");
		return -1;
	};//cout << "QueryPerformanceFrequency failed!\n";

	pc_frequencies.push_back(double(li.QuadPart)/ scaling);
	QueryPerformanceCounter(&li);
	start_times.push_back(li.QuadPart);
	return (int)(start_times.size()-1);
}
double Timers::get_time(int timer_id)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart-start_times[timer_id])/pc_frequencies[timer_id];
}