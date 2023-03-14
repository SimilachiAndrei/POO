#pragma once
#include <iostream>
using namespace std;
class Sort
{
    int* l;
    int nr;
    void quickSort(int low, int high, bool ascendent);
public:
    Sort(int count, int mini, int maxi);
    Sort(initializer_list<int> elements);
    Sort(const int v[],int count);
    Sort(int count, ...);
    Sort(const char* p);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
