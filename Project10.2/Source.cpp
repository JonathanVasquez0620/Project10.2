#include<iostream>
#include <ctime>
#include <string>

using namespace std;

class Clock
{
public:
	Clock();
	string get_time();
	int get_hours();
	int get_minutes();
	void alarm(int hrs, int mins);

private:
	int hours;
	int minutes;
};

Clock::Clock()
{
	int hours = 0;
	int minutes = 0;
}

string Clock::get_time()
{
	string time = get_hours() + " : " + get_minutes();
	return time;
}

int Clock::get_hours()
{
	time_t current_time = time(0);
	tm* local_time = localtime(&current_time);
	int hours = local_time->tm_hour;
	return hours;
}

int Clock::get_minutes()
{
	time_t current_time = time(0);
	tm* local_time = localtime(&current_time);
	int minutes = local_time->tm_min;
	return minutes;
}

void Clock::alarm(int hrs, int mins)
{
	if ((get_hours() >= hrs) && (get_minutes() >= mins))
	{
		cout << "Alarm";
	}
	return;
}

class WorldClock : public Clock
{
public:
	WorldClock(int zone_offset);
	int get_hours();

private:
	int zone;

};

WorldClock::WorldClock(int zone_offset)
{
	zone = zone_offset;
}

int WorldClock::get_hours()
{
	time_t current_time = time(0);
	tm* local_time = localtime(&current_time);
	int hours = local_time->tm_hour;
	return hours + zone;
	return 0;
}

int WorldClock::get_hours()
{
	time_t current_time = time(0);
	tm* local_time = localtime(&current_time);
	int hours = local_time->tm_hour;
	return hours + zone;
}

int main()
{
	Clock clock1;
	WorldClock wClock1(3);
	cout << clock1.get_time() << endl;
	cout << wClock1.get_time() << endl;

	return 0;
}