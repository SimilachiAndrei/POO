#include "NumberList.h"

void NumberList::Init()
{
    this->count = 0;
}
bool NumberList::Add(int x)
{
    if (count < 10)
    {
        numbers[count++] = x;
        return true;
    }
    return false;
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

