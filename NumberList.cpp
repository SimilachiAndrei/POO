#include "NumberList.h"

void NumberList::Init()
{
    this->count = 0;
    numbers = new int[10];
}
bool NumberList::Add(int x)
{
    if (count < size)
    {
        numbers[count++] = x;
        return true;
    }
    else
    {
        int* tmp = new int[count];              
        memcpy(tmp, numbers , count * sizeof * tmp);       
        delete[] numbers;                             

        numbers = tmp;                                
        numbers[count] = x;

    }
}

void NumberList::Sort()
{
    int i, j;
    for (i = 0; i < count - 1; i++)
        for (j = 0; j < count - i - 1; j++)
            if (numbers[j] > numbers[j + 1])
                swap(numbers[j], numbers[j + 1]);
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
    {
        cout << numbers[i] << " ";
    }cout << endl;
}

