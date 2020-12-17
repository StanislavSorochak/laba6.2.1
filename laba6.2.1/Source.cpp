// Lab_06_2_1.cpp
// < Сорочак Станіслав >
// Лабораторна робота №6.2.1
// Опрацювання одновимірних масивів рекурсивним способом
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int Inverse(int* a, const int n, int i)
{
    int tmp = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = tmp;
    {
        if (i < n / 2 - 1)
            Inverse(a, n, i + 1);
    }
    return i;
}


int main()
{
    srand((unsigned)time(NULL));

    int const n = 6;
    int Low = -4;
    int High = 18;
    int a[n];

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    Inverse(a, n, 0);
    Print(a, n, 0);

    return 0;
}
