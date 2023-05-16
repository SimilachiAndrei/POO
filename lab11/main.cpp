#include <iostream>
using namespace std;

template<class T>
class Sortare 
{
private:
    T v[100] = {0}; //era T v[100] = {-1}
    int n = 0; // era int n = 5;
public:
    Sortare();
    ~Sortare();
    void Insert(T a[], int);
    void Sort();
    void Print();
};

template<class T>
void Sortare<T>::Print()
{
    cout << "Elementele din vector sunt: ";
    for (int i = 0; i < this->n; i++)//aici era <=
      {  
        cout << v[i];
        if(i!=this->n-1)//se afisa o virgula in plus
            cout<<",";
        }
    cout << endl;
}

template<class T>
void Sortare<T>::Insert(T a[], int n)
{
    int O = 0;this->n = n;// O=1
    for (int i = O; i < n; i++)
    {
        v[i] = a[i];
    }
}

template<class T>
Sortare<T>::Sortare()
{
    // v[0] = 0;
}
template<class T>
Sortare<T>::~Sortare()
{
    this->n = 0;
}

template<class T>
void Sortare<T>::Sort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
            {
                T aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}
int main()
{
    Sortare<int> obj;
    int nr;
    cin >> nr;
    int a[100];
    for (int i = 0; i < nr; i++)
        cin >> a[i];
    obj.Insert(a, nr);
    /* obj.Print();
    obj.Sort();
    */
    obj.Sort();
    obj.Print();
}