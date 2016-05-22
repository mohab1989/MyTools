#include<vector>
class Timers
{
public:
	enum time_unit
	{
		seconds, milliseconds, microseconds
	};
	Timers();
	int start_timer(time_unit tu = time_unit::microseconds);
	double get_time(int timer_id);

private:
	double scaling;
	unsigned int num_timers;
	std::vector<__int64> start_times;
	std::vector<double> pc_frequencies;
};