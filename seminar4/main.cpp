#include "Sort.h"
using namespace std;
int main()
{
    Sort s("10,40,100,5,70");
    s.BubbleSort();
    s.Print();
    Sort p(5, 5, 4, 4, 1, 2);
    p.InsertSort(true);
    p.Print();
    Sort f = { 6,7,8,9,3 };
    f.QuickSort();
    f.Print();
    int v[] = { 51,23,54,18 };
    Sort h(v, 4);
    h.Print();
    Sort g (4, 2, 8);
    g.Print();
}
