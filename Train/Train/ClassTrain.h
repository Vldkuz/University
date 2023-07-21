#pragma once
#include <string>

struct Time
{
	size_t hour;
	size_t minute;
	~Time();
};


class Train
{
public:
	Train();
	Train(size_t number, std::string Point, Time time);
	~Train();
	friend std::ifstream& operator>>(std::ifstream& in, Train& train);
	friend std::ofstream& operator<<(std::ofstream& out, Train& train);
	std::string GetPoint();
	Time GetTime();
private:
	size_t number;
	std::string PointB;
	Time time;
};
 
