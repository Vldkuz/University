#include "SparsedMatrix.h"


SparsedMatrix::SparsedMatrix() {
	List = new LinkedList();
	Rows = Columns = 0;
}

SparsedMatrix::SparsedMatrix(const SparsedMatrix& Matrix)
{
	List = new LinkedList(*Matrix.List);
	Rows = Matrix.Rows;
	Columns = Matrix.Columns;
}

SparsedMatrix::SparsedMatrix(double** const Matrix,const size_t n, const size_t m)
{
	List = new LinkedList();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (Matrix[i][j] != 0)
			{
				MatrixScalar Scalar;
				Scalar.value = Matrix[i][j];Scalar.i = i;Scalar.j = j;
				List->Add(Scalar);
			}
		}
	}

	Rows = n;Columns = m;
}

SparsedMatrix::SparsedMatrix(const LinkedList& List,const size_t Rows, const size_t Columns)
{
	this->List = new LinkedList(List);
	this->Rows = Rows;
	this->Columns = Columns;
}


SparsedMatrix SparsedMatrix::operator+(const SparsedMatrix& Matrix)
{
	SparsedMatrix Tmp(*this);
	Node* pList = Matrix.List->pStart;

	if (Rows != Matrix.Rows || Columns != Matrix.Columns)
		exit(-1);

	while (pList != nullptr)
	{
		bool bflag = false;
		Node* TmpList = Tmp.List->pStart;
		while (TmpList != nullptr)
		{
			if (pList->Scalar.i == TmpList->Scalar.i && pList->Scalar.j == TmpList->Scalar.j)
			{
				TmpList->Scalar.value += pList->Scalar.value;
				bflag = true;
				break;
			}

			TmpList = TmpList->pNext;
		}

		if (!bflag) {
			Tmp.List->Add(pList->Scalar);
		}

		pList = pList->pNext;
	}

	return Tmp;
}

SparsedMatrix SparsedMatrix::operator-(const SparsedMatrix& Matrix)
{
	SparsedMatrix Tmp(*this);
	Node* pList = Matrix.List->pStart;

	if (Rows != Matrix.Rows || Columns != Matrix.Columns)
		exit(-1);

	while (pList != nullptr)
	{
		bool bflag = false;
		Node* TmpList = Tmp.List->pStart;
		while (TmpList != nullptr)
		{
			if (pList->Scalar.i == TmpList->Scalar.i && pList->Scalar.j == TmpList->Scalar.j)
			{
				TmpList->Scalar.value -= pList->Scalar.value;
				bflag = true;
				break;
			}

			TmpList = TmpList->pNext;
		}

		if (!bflag) {
			Tmp.List->Add(pList->Scalar);
		}

		pList = pList->pNext;
	}

	return Tmp;
}

SparsedMatrix SparsedMatrix::operator*(const double& Scalar)
{
	SparsedMatrix Matrix(*this);
	Node* pList = Matrix.List->pStart;

	while (pList != nullptr)
	{
		pList->Scalar.value *= Scalar;
		pList = pList->pNext;
	}

	return Matrix;
}

SparsedMatrix SparsedMatrix::operator*(const SparsedMatrix& Matrix)
{
	if (Columns != Matrix.Rows)
		exit(-1);

	SparsedMatrix Tmp;
	Node* pList1 = List->pStart;
	while (pList1 != nullptr)
	{
		Node* pList2 = Matrix.List->pStart;
		size_t IdxCol, IdxRow;
		while (pList2 != nullptr)
		{
			if (pList1->Scalar.j == pList2->Scalar.i)
			{
				double Summary = pList1->Scalar.value * pList2->Scalar.value;
				IdxCol = pList2->Scalar.j;
				IdxRow = pList1->Scalar.i;

				Node* pList3 = Tmp.List->pStart;
				bool bflag = false;
				while (pList3 != nullptr)
				{
					if (pList3->Scalar.i == IdxRow && pList3->Scalar.j == IdxCol)
					{
						pList3->Scalar.value += Summary;
						bflag = true;
						break;
					}
					pList3 = pList3->pNext;
				}

				if (!bflag)
				{
					MatrixScalar Scal;
					Scal.i = IdxRow;
					Scal.j = IdxCol;
					Scal.value = Summary;
					Tmp.List->Add(Scal);
				}
			}
			pList2 = pList2->pNext;
		}

		pList1 = pList1->pNext;
	}

	return Tmp;
}

SparsedMatrix::~SparsedMatrix()
{
	Rows = Columns = 0;
}

std::istream& operator>>(std::istream& in, SparsedMatrix& Matrix)
{
	std::string Input = " ";
	size_t Counter = 0;
	MatrixScalar Tmp;

	do
	{
		Input.clear();
		std::getline(in, Input, ':');

		if (Input == "\n")
			break;

		if (Counter % 3 == 0) {
			Tmp.value = std::stoi(Input);
		}
		else if (Counter % 3 == 1)
		{
			Tmp.i = std::stoi(Input);
			Matrix.Rows = std::max(Tmp.i, Matrix.Rows);
		}
		else
		{
			Tmp.j = std::stoi(Input);
			Matrix.List->Add(Tmp);
			Matrix.Columns = std::max(Tmp.j, Matrix.Columns);
		}

		++Counter;

	} while (Input != "\n");


	return in;
}

std::ostream& operator<<(std::ostream& out, SparsedMatrix& Matrix)
{
	Node* pList = Matrix.List->getStart();
	while (pList != nullptr)
	{
		out << pList->Scalar.value << ':' << pList->Scalar.i << ':' << pList->Scalar.j << ":" << std::endl;
		pList = pList->pNext;
	}

	return out;
}
