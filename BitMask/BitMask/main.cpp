#include <iostream>

bool IsInArray(int* arr, int SizeOfArray, int val)
{
    for (int i = 0; arr[i] != -1; ++i)
    {
        if (arr[i] == val)
            return true;
    }

    return false;
}

bool HasSameDigital(int number)
{
    int arr[10];
    std::memset(arr, -1, sizeof(int) * 10);
    size_t k = 0;

     while (number > 0)
    {
        int digit = number % 10;
        if (IsInArray(arr, 10, digit))
        {
            return true;
        }

        arr[k++] = digit;
        number /= 10;
    }
    return false;
}

void GetSubSet(int mask, int* Array, int SizeOfArray, std::ostream& out)
{
    int* arr = new int[SizeOfArray];
    std::memset(arr, -1, sizeof(int) * SizeOfArray);

    bool bflag = false;
    size_t k = 0;
    for (int i = SizeOfArray - 1; i >= 0; --i)
    {
        if (mask & 1)
        {
            if (HasSameDigital(Array[i])) {
                arr[k++] = Array[i];
            }
            else
            {
                return;
            }
        }

        mask >>= 1;
    }



    for (int i = 0; arr[i] != -1; ++i)
    {
        out << arr[i] << " ";
    }
    out << std::endl;
}

int main()
{
    int n;int k;
    std::cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i){
        std::cin >> arr[i];}


    for (int mask = (1 << k) - 1; mask < (1 << n); )
    {
        GetSubSet(mask, arr, n, std::cout);
        int t = (mask | (mask - 1)) + 1;
        mask = t | ((((t & -t) / (mask & -mask)) >> 1) - 1);
    }
}
