#include <iostream>
#include <exception>
using namespace std;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<typename T>
class MyComparator : public Compare
{
public:
    int CompareElements(void* e1, void* e2) override
    {
        return *(T*)e1 > *(T*)e2;
    }
};
class out_of_r : public exception
{
    virtual const char* what() const throw()
    {
        return "Out of range!";
    }
};

class overfl : public exception
{
    virtual const char* what() const throw()
    {
        return "Array is full";
    }
};

class compnotset : public exception
{
    virtual const char* what() const throw()
    {
        return "Comparator not set";
    }
};
template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;

public:
    ArrayIterator(T** list, int current) : List(list), Current(current) {}
    ArrayIterator& operator ++ () { ++Current; return *this; }
    ArrayIterator& operator -- () { --Current; return *this; }
    bool operator= (const ArrayIterator<T>& other) { return List == other.List && Current == other.Current; }
    bool operator!=(const ArrayIterator<T>& other) { return !(*this = other); }
    T* operator->() { return List[Current]; }
    T& operator*() { return *List[Current]; }
    T* GetElement()
    {
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;
    Compare* Comparator;

public:
    Array() : List(nullptr), Capacity(0), Size(0), Comparator(nullptr) {}

    ~Array()
    {
        for (int i = 0; i < Capacity; i++)
            delete List[i];
        delete[] List;
    }

    Array(int capacity) : List(new T* [capacity]), Capacity(capacity), Size(0), Comparator(nullptr)
    {

    }

    Array(const Array<T>& otherArray) : List(new T* [otherArray.Capacity]), Capacity(otherArray.Capacity), Size(otherArray.Size), Comparator(otherArray.Comparator)
    {
        for (int i = 0; i < otherArray.Size; i++)
            List[i] = new T(*otherArray.List[i]);
        for (int i = otherArray.Size; i < otherArray.Capacity; i++)
            List[i] = nullptr;
    }

    T& operator[] (int index)
    {
        out_of_r ex;
        try {
            if (index < 0 || index >= Size)
                throw ex;
            return *List[index];
        }
        catch (exception &ex)        //aici ii zici sa ti prinda exceptia ex 
        {
            cout << ex.what() << endl;
        }
    }

    const Array<T>& operator+=(const T& newElem)
    {
        overfl ex;
        try {
            if (Size == Capacity)
                throw ex;
            List[Size++] = new T(newElem);
            return *this;
        }
        catch (exception& ex)
        {
            cout << ex.what() << endl;
        }
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        overfl ex1;
        out_of_r ex2;
        try {
            if (index < 0 || index > Size)
                throw ex1;
            if (Size == Capacity)
                throw ex2;
            for (int i = Size - 1; i >= index; i--)
                List[i + 1] = List[i];
            List[index] = new T(newElem);
            Size++;
            return *this;
        }
        catch (exception &ex)
        {
            cout << ex.what() << endl;
        }

    }

    const Array<T>& Insert(int index, const Array<T>& otherArray)
    {
        overfl ex1;
        out_of_r ex2;
        try {
            if (index < 0 || index > Size)
                throw ex1;
        if (Size + otherArray.Size > Capacity)
            throw ex2;
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
        }
        catch (exception& ex)
        {
            cout << ex.what() << endl;
        }
    }

    const Array<T>& Delete(int index)
    {
        out_of_r ex;
        try {
            if (index < 0 || index >= Size)
                throw ex;
            delete List[index];
            for (int i = index + 1; i < Size; i++)
                List[i - 1] = List[i];
            List[--Size] = nullptr;
            return *this;
        }
        catch (exception& ex)
        {
            cout << ex.what() << endl;
        }
    }
    const Array<T>& Delete(int startIndex, int endIndex)
    {
        out_of_r ex;
        try {
            if (startIndex < 0 || startIndex >= Size || endIndex < 0 || endIndex >= Size || startIndex > endIndex)
                throw ex;
            for (int i = startIndex; i <= endIndex; i++)
                delete List[i];

            int elementsToRemove = endIndex - startIndex + 1;
            for (int i = startIndex + elementsToRemove; i < Size; i++)
                List[i - elementsToRemove] = List[i];
            for (int i = Size - elementsToRemove; i < Size; i++)
                List[i] = nullptr;
            Size -= elementsToRemove;
            return *this;
        }
        catch (exception& ex)
        {
            cout << ex.what() << endl;
        }
    }

    void SetComparator(Compare* comparator)
    {
        Comparator = comparator;
    }

    ArrayIterator<T> Begin() const
    {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> End() const
    {
        return ArrayIterator<T>(List, Size);
    }

    void Sort()
    {
        compnotset ex;
        try {
            if (Comparator == nullptr)
                throw ex;

            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size - i - 1; j++)
                {
                    if (Comparator->CompareElements(List[j], List[j + 1]) > 0)
                    {
                        T* temp = List[j];
                        List[j] = List[j + 1];
                        List[j + 1] = temp;
                    }
                }
            }
        }
        catch (exception& ex)
        {
            cout << ex.what() << endl;
        }
    }
    void Sort(int (*compare)(const T&, const T&))
    {
        int sorted = 0;
        while (!sorted)
        {
            sorted = 1;
            for (int i = 0; i < Size - 1; i++)
                if (compare(*List[i], *List[i + 1]))
                {
                    T* aux;
                    aux = List[i];
                    List[i] = List[i + 1];
                    List[i + 1] = aux;
                    sorted = 0;
                }
        }
    }
    void Sort(Compare* comparator)
    {
        bool sorted = false;
        while (!sorted)
        {
            sorted = true;
            for (int i = 0; i < Size - 1; i++)
                if (comparator->CompareElements(List[i], List[i + 1]))
                {
                    T* aux;
                    aux = List[i];
                    List[i] = List[i + 1];
                    List[i + 1] = aux;
                    sorted = false;
                }
        }
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {

        int left = 0;
        int right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
            {
                return mid;
            }
            else if (elem<*List[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int low = 0, high = Size - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cmp = compare(elem, *List[mid]);
            if (cmp < 0)
                high = mid - 1;
            else if (cmp > 0)
                low = mid + 1;
            else
                return mid;
        }

        return -1; // element not found
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int low = 0, high = Size - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cmp = comparator->CompareElements((void*) & elem, List[mid]);
            if (cmp < 0)
                high = mid - 1;
            else if (cmp > 0)
                low = mid + 1;
            else
                return mid;
        }
        return -1; // element not found
    }
    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) {
                return i;
            }
        }
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0) {
                return i;
            }
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(T[i], elem) == 0) {
                return i;
            }
        }
        return -1;
    }
    int GetSize() const { return Size; }
    int GetCapacity() const { return Capacity; }
};

int compareInts(const int& a, const int& b)
{
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
int main()
{
    Array<int> arr(5);
    arr += 1;
    arr += 3;
    arr += 2;
    MyComparator<int> cmp;
    arr.SetComparator(&cmp);
    Array<int> arr2(2);
    arr2 += 4;
    arr2 += 5;
    arr.Insert(1, arr2);
   int f= arr.BinarySearch(5);
   arr.Delete(2);
   int c = arr.Find(2);
   cout << c << endl;
   cout << f << endl;
   int f1 = arr.BinarySearch(4, compareInts);
   cout << f1 << endl;
   int f2 = arr.BinarySearch(4, &cmp);
   cout << f2;
   Compare* comp;
   comp = new MyComparator<int>;
   arr.Sort(comp);
   for (ArrayIterator<int> it = arr.Begin(); it != arr.End(); ++it)
        cout << *it << " ";

    return 0;
}