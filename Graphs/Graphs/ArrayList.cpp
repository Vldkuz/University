#include "ArrayList.h"
#include <iostream>

int constexpr growfactor = 2;

void Qsort(double* arr, int left, int right)
{
	int l = left;
	int r = right;
	double mid = arr[(l + r) / 2];

	while (l <= r)
	{
		while (arr[l] < mid)
			++l;

		while (arr[r] > mid)
			--r;

		if (l <= r)
			std::swap(arr[l++], arr[r--]);
	}

	if (l < right)
		Qsort(arr, l, right);
	if (r > left)
		Qsort(arr, left, r);
}


SortedArr::SortedArr() {
	size = 10;
	arr = new double[size];
};

SortedArr::SortedArr(double* tmp, size_t s_tmp)
{
	size = s_tmp;
	LastIdx = size;
	arr = new double[size];
	copy(arr, tmp, size);
	sort();
}

SortedArr::SortedArr(const SortedArr& tmp)
{
	size = tmp.size;
	LastIdx = tmp.LastIdx;
	arr = new double[size];
	copy(arr, tmp.arr, size);
}

void SortedArr::Append(double elem)
{
	if (LastIdx >= size)
		resize();
	arr[LastIdx++] = elem;
	sort();
}

void SortedArr::appendWS(double elem)
{
	if (LastIdx >= size)
		resize();
	arr[LastIdx++] = elem;
}

bool SortedArr::TryGet(size_t idx, double& elem) const
{
	if (idx >= LastIdx)
		return false;

	elem = arr[idx]; return true;
}

double SortedArr::operator[](size_t idx) const
{
	double elem;
	if (TryGet(idx, elem))
		return elem;
	exit(-1);
}

SortedArr SortedArr::operator=(const SortedArr& tmp)
{
	delete[] arr;
	arr = new double[tmp.size];
	copy(arr, tmp.arr, tmp.size);
	size = tmp.size;
	LastIdx = tmp.LastIdx;

	return *this;
}

SortedArr::~SortedArr()
{
	delete[] arr;
	size = 0;
	LastIdx = 0;
}


void SortedArr::resize()
{
	double* tmp = new double[size * growfactor];
	copy(tmp, arr, size);
	size *= growfactor;

	delete[] arr;
	arr = tmp;
}

void SortedArr::copy(double* dst, double* src, size_t Size)
{
	size_t SizeInBytes = Size * sizeof(double);
	memcpy_s(dst, SizeInBytes, src, SizeInBytes);
}

void SortedArr::sort() const
{
	Qsort(arr, 0, LastIdx - 1);
}


void SortedArr::ShowArray()
{
	for (size_t i = 0; i < LastIdx; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

SortedArr SortedArr::operator+(const SortedArr& d1) const
{
	size_t tsize = LastIdx + d1.LastIdx;

	SortedArr tmp;

	size_t i = 0;
	size_t j = 0;
	while (i + j < tsize) {

		if (i >= LastIdx) {
			while (j < d1.LastIdx) {
				tmp.appendWS(d1[j]); ++j;
			}
			break;
		}

		if (j >= d1.LastIdx)
		{
			while (i < LastIdx) {
				tmp.appendWS(arr[i]); ++i;
			}
			break;
		}

		if (arr[i] < d1[j]) {
			tmp.appendWS(arr[i]); ++i;
		}
		else {
			tmp.appendWS(d1[j]); ++j;
		}
	}

	return tmp;
}
