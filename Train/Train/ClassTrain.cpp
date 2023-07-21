#include "ClassTrain.h"
#include <fstream>

Train::Train() {
	this->number = 0;
	this->PointB = "";
	this->time.hour = -1;
	this->time.minute = -1;
};

Train::Train(size_t number, std::string Point, Time time)
{
	this->number = number;
	PointB = Point;
	this->time = time;
}

Train::~Train() {};

std::string Train::GetPoint()
{
	return PointB;
}

Time Train::GetTime()
{
	return time;
}


Time::~Time() {};

std::ifstream& operator>>(std::ifstream& in, Train& train)
{
	in >> train.number >> train.PointB >> train.time.hour >> train.time.minute;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, Train& train)
{
	out << train.number <<" "<< train.PointB <<" "<< train.time.hour <<" "<< train.time.minute << std::endl;
	return out;
}

