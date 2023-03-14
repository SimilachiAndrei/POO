#include "Sort.h"
#include <cstdarg>
#include <cstring>
#pragma warning (disable : 4996)
Sort::Sort(int count, int mini, int maxi):l(nullptr),nr(count)//1
{
    srand(time(0));
    l = new int[count];
    for (int i = 0; i < count; i++)
    {
        l[i] = rand() % (maxi-mini) + mini;
    }
}
Sort::Sort(initializer_list<int> elements) :l(nullptr), nr(elements.size())
{
    l = new int[elements.size()]; int lung = 0;
    for (int element : elements)
    {
        l[lung++] = element;
    }
}
Sort::Sort(const int v[],int count) :l(nullptr), nr(count)
{
    l = new int[count];
    for (int i = 0; i < count; i++)
        l[i] = v[i];
}
Sort::Sort(int count, ...) :l(nullptr), nr(count)
{
    va_list args;
    va_start(args, count);
    l = new int[count];
    for (int i = 0; i < count; i++)
        l[i] = va_arg(args, int);
    va_end(args);
}
Sort::Sort(const char* p) : l(nullptr), nr(0)
{
    if (p == nullptr || strlen(p) == 0) {
        return;
    }
    nr = 1;
    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] == ',')nr++;
    }
    l = new int[nr];
    char* sep;
    char* cpy = strdup(p);
    sep = strtok(cpy, ",");
    int i = 0;
    while (sep != NULL)
    {
        l[i++] = atoi(sep);
        sep=strtok(NULL,",");
    }
}
int Sort::GetElementsCount()
{
    return this->nr;
}
void Sort::Print()
{
    for (int i = 0; i < nr; i++)
        cout << l[i] << " ";
    cout << '\n';
}
int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < nr)
        return l[index];
}
void Sort::InsertSort(bool ascendent) {
    int i, j, tmp;
    for (i = 1; i < nr; i++) {
        tmp = l[i];
        j = i - 1;
        while (j >= 0 && ((ascendent && l[j] > tmp) || (!ascendent && l[j] < tmp))) {
            l[j + 1] = l[j];
            j--;
        }
        l[j + 1] = tmp;
    }
}
void Sort::BubbleSort(bool ascendent) {
    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < nr - j; i++) {
            if ((ascendent && l[i] > l[i + 1]) || (!ascendent && l[i] < l[i + 1])) {
                tmp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}
void Sort::quickSort(int low, int high, bool ascendent)
{
    int i = low;
    int j = high;
    int pivot = l[(low + high) / 2];
    while (i <= j) {
        if (ascendent) {
            while (l[i] < pivot) i++;
            while (l[j] > pivot) j--;
        }
        else {
            while (l[i] > pivot) i++;
            while (l[j] < pivot) j--;
        }
        if (i <= j) {
            swap(l[i], l[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(low, j, ascendent);
    if (i < high)
        quickSort(i, high, ascendent);
}

void Sort::QuickSort(bool ascendent)
{
    quickSort(0, nr - 1, ascendent);
}