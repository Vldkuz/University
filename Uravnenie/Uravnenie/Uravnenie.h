#pragma once
#include <iostream>
typedef double(*func) (double);

struct Segment
{
	Segment(double left, double right);
	Segment();
	double Left();
	double Right();
	~Segment();

	double a;double b;
};

struct RootWrapper
{
	bool bflag = false;
	double Root;
	~RootWrapper();
};

class Uravnenie
{
public:

	Uravnenie(func Function,Segment YourSegment, double Epsilon);
	bool TryChangeCurrentSegment(Segment NewSegment);
	void ShowRoot(std::ostream& out);
	~Uravnenie();

private:
	friend RootWrapper MethodTangent(func Function, Segment YourSegment, double Epsilon);

	func f;
	Segment CurrentSegment;
	RootWrapper Root;
	double Epsilon;
};

