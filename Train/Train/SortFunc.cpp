#include "SortFunc.h"

bool CmpTimeLater(const Time& t1, const Time& t2)
{
    if (t1.hour != t2.hour)
        return t1.hour > t2.hour;
    return t1.minute > t2.minute;
}

void qsort(Train* arr, int left, int right, size_t* indexs)
{
    int l = left;
    int r = right;
    
    std::string mid = arr[indexs[(l + r) / 2]].GetPoint();

    while (l <= r)
    {
        while (arr[indexs[l]].GetPoint() < mid)
            ++l;
        while (arr[indexs[r]].GetPoint() > mid)
            --r;

        if (l <= r)
            std::swap(indexs[l++], indexs[r--]);
    }

    if (left < r)
        qsort(arr, left, r, indexs);
    if (right > l)
        qsort(arr, l, right, indexs);
}


Train* Sort(Train* arr, size_t size)
{
    Train* temp = new Train[size];
    size_t* indexs = new size_t[size];

    for (size_t i = 0; i < size; ++i)
        indexs[i] = i;

    qsort(arr, 0, size - 1, indexs);
    for (size_t i = 0; i < size - 1; ++i)
        if (CmpTimeLater(arr[indexs[i]].GetTime(), arr[indexs[i + 1]].GetTime()) && arr[indexs[i]].GetPoint() == arr[indexs[i+1]].GetPoint())
            std::swap(indexs[i], indexs[i + 1]);


    for (size_t i = 0; i < size; ++i)
        temp[i] = arr[indexs[i]];

    delete[] arr;

    return temp;
}