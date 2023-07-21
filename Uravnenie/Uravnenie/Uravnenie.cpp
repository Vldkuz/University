#include "Uravnenie.h"
#include <iostream>

double dfx(func f, double x, double epsilon)
{
	double dt = f(x + epsilon) - f(x);
	return dt / epsilon;
}

RootWrapper MethodTangent(func Function, Segment YourSegment, double Epsilon)
{
	double LeftOp = YourSegment.Left();
	double RightOp = YourSegment.Right();
	double LeftImage = Function(LeftOp);
	double RightImage = Function(RightOp);

	RootWrapper Root;

	if (LeftImage == 0) {
		Root.bflag = true;
		Root.Root = LeftOp;
		return Root;
	}

	if (RightImage == 0)
	{
		Root.bflag = true;
		Root.Root = RightOp;
		return Root;
	}

	if (LeftImage * RightImage < 0)
	{
		double Diff = Function(RightOp) / dfx(Function, RightOp, Epsilon);
		double X = RightOp - Diff;

		while (abs(Diff) >= Epsilon)
		{
			Diff = Function(X) / dfx(Function, X, Epsilon);
			X -= Diff;
		}

		Root.Root = X;
		Root.bflag = true;
		return Root;
	}

	return Root;
}


Uravnenie::Uravnenie(func Function, Segment YourSegment, double Epsilon)
{
	f = Function;
	CurrentSegment = YourSegment;
	this->Epsilon = Epsilon;
	Root = MethodTangent(f, CurrentSegment, Epsilon);
}


bool Uravnenie::TryChangeCurrentSegment(Segment NewSegment)
{
	CurrentSegment = NewSegment;
	Root = MethodTangent(f, CurrentSegment, Epsilon);
	if (!Root.bflag)
		return false;
}

void Uravnenie::ShowRoot(std::ostream& out)
{
	if (!Root.bflag){
		out << "No Roots at the Current Segment " << std::endl;
		return;
	}

	out << Root.Root << std::endl;
}


Uravnenie::~Uravnenie() {
	f = nullptr;
	CurrentSegment.~Segment();
	Root.~RootWrapper();
	Epsilon = 0;
};

Segment::Segment(double left, double right) {a = std::min(left, right);b = std::max(left, right);}
Segment::Segment(){a = b = 0;}
double Segment::Left(){return a;}
double Segment::Right(){return b;}
Segment::~Segment() {};
RootWrapper::~RootWrapper() {};
