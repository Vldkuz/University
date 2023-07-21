#pragma once

class SortedArr
{
public:
	SortedArr();
	SortedArr(double* tmp, size_t s_tmp);
	SortedArr(const SortedArr& tmp);
	void Append(double elem);
	bool TryGet(size_t idx, double& elem) const;
	double operator[](size_t idx) const;
	SortedArr operator=(const SortedArr& tmp);
	void ShowArray();
	SortedArr operator+(const SortedArr& d1) const;
	~SortedArr();
private:
	void resize();
	void copy(double* dst, double* src, size_t Size);
	void sort() const;
	void appendWS(double elem);

	double* arr;
	size_t size;
	size_t LastIdx = 0;
};


//–азработать класс упор€доченных массивов произвольного размера.
//¬ классе должна быть закрыта€ функци€ - член сортировки массива,
//которую следует вызывать в конструкторе при создании массива.
//ѕерегрузить функцию - оператор + дл€ создани€ нового
//упор€доченного массива по двум существующим, в которой новый
//упор€доченный массив создавать сли€нием двух исходных без
//использовани€ сортировки.Ќаписать тестирующую программу.
