#include "Number.h"
#include <cstring>
Number::Number(const char* value, int base):b(base),n(nullptr)
{
	n = new char[strlen(value)+1];
	strcpy(n, value);
}
Number::Number(const Number& other)
{
    this->n = new char[strlen(other.n) + 1];
    strcpy(this->n, other.n);
    this->b = other.b;
}
Number::Number(Number&& other)
{
    this->b = other.b;
    this->n = other.n;

    other.b = NULL; 
    other.n = nullptr;
}
Number::~Number()
{
	delete n;
	b = NULL;
};

Number& Number::operator=( Number&& other)
{
    if (this != &other) {
        delete[] n;
        this->b = other.b;
        this->n = other.n;
        other.b = NULL;
        other.n = nullptr;
    }
    return *this;
}
Number& Number:: operator--()
{
    this->n[strlen(this->n)-1] = NULL;
    return *this;
}
Number& Number::operator--(int a)
{
    char p[20];
    strcpy(p, this->n);
    strcpy(this->n, p + 1);
    return *this;
}
void Number :: Print()
{
	for (int i = 0; i < strlen(n); i++)
		cout << n[i];
	cout << endl;
}
int Number ::  GetDigitsCount() const
{
	return strlen(n);
}
int Number ::  GetBase() const
{
	return b;
}
void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16)
    {
        cout << "Error: Invalid base\n";
        return;
    }

    int decimalValue = 0;
    int power = 1;
    int len = strlen(n);
    for (int i = len - 1; i >= 0; i--)
    {
        int digitValue;
        if (n[i] >= '0' && n[i] <= '9')
            digitValue = n[i] - '0';
        else if (n[i] >= 'A' && n[i] <= 'F')
            digitValue = n[i] - 'A' + 10;
        else if (n[i] >= 'a' && n[i] <= 'f')
            digitValue = n[i] - 'a' + 10;
        else
        {
            cout << "Error: Invalid digit in number\n";
            return;
        }

        decimalValue += digitValue * power;
        power *= b;
    }

    int index = 0;
    char* newN = new char[100];
    while (decimalValue > 0)
    {
        int digitValue = decimalValue % newBase;
        if (digitValue >= 0 && digitValue <= 9)
            newN[index] = digitValue + '0';
        else
            newN[index] = digitValue - 10 + 'A';
        index++;
        decimalValue /= newBase;
    }
    newN[index] = '\0';

    int start = 0, end = index - 1;
    while (start < end)
    {
        char temp = newN[start];
        newN[start] = newN[end];
        newN[end] = temp;
        start++;
        end--;
    }

    delete[] n;
    n = newN;
    b = newBase;
}



bool Number::operator>(const Number& other)
{
        Number left = *this;
        Number right = other;
        left.SwitchBase(10);
        right.SwitchBase(10);
        if (atoi(left.n)>atoi(right.n))
        {
            return 1;
        }
        return 0;
}

bool Number::operator>=(const Number& other)
{
    Number left = *this;
    Number right = other;
    left.SwitchBase(10);
    right.SwitchBase(10);
    if (atoi(left.n) >= atoi(right.n))
    {
        return 1;
    }
    return 0;
}
bool Number::operator<(const Number& other)
{
    Number left = *this;
    Number right = other;
    left.SwitchBase(10);
    right.SwitchBase(10);
    if (atoi(left.n) < atoi(right.n))
    {
        return 1;
    }
    return 0;
}
bool Number::operator<=(const Number& other)
{
    Number left = *this;
    Number right = other;
    left.SwitchBase(10);
    right.SwitchBase(10);
    if (atoi(left.n) <= atoi(right.n))
    {
        return 1;
    }
    return 0;
}
bool Number::operator==(const Number& other)
{
    Number left = *this;
    Number right = other;
    left.SwitchBase(10);
    right.SwitchBase(10);
    if (atoi(left.n) == atoi(right.n))
    {
        return 1;
    }
    return 0;
}
bool Number::operator!=(const Number& other)
{
    Number left = *this;
    Number right = other;
    left.SwitchBase(10);
    right.SwitchBase(10);
    if (atoi(left.n) != atoi(right.n))
    {
        return 1;
    }
    return 0;
}
Number operator+(const Number& l, const Number& r)
{
    int maxbase = max(l.b, r.b);
    Number result = l;
    Number var = r;
    result.SwitchBase(10);
    var.SwitchBase(10);
    result.b = maxbase;
    int res = atoi(result.n) + atoi(var.n);
    itoa(res,result.n,maxbase);
    return result;
}
Number operator-(const Number& l, const Number& r)
{
    int maxbase = max(l.b, r.b);
    Number result = l;
    Number var = r;
    result.SwitchBase(10);
    var.SwitchBase(10);
    result.b = maxbase;
    int res = atoi(result.n) - atoi(var.n);
    itoa(res, result.n, maxbase);
    return result;
}
Number Number :: operator-=(const Number& r)
{
    int maxbase = max(this->b, r.b);
    Number result = *this;
    Number var = r;
    result.SwitchBase(10);
    var.SwitchBase(10);
    result.b = maxbase;
    int res = atoi(result.n) - atoi(var.n);
    char car[50];
    itoa(res, car, maxbase);
    delete[] this->n;
    this->n = new char[strlen(car) + 1];
    itoa(res, this->n, maxbase);
    return *this;
}
Number Number :: operator+=(const Number& r)
{
    int maxbase = max(this->b, r.b);
    Number result = *this;
    Number var = r;
    result.SwitchBase(10);
    var.SwitchBase(10);
    result.b = maxbase;
    int res = atoi(result.n) + atoi(var.n);
    char car[50];
    itoa(res, car, maxbase);
    delete[] this->n;
    this->n = new char[strlen(car) + 1];
    itoa(res, this->n, maxbase);
    return *this;
}
char Number:: operator[](const int i)
{
    return this->n[i];
}
Number& Number :: operator=(const int x)
{
    this->b = 10;
    char * res= itoa(x, this->n, 10);
    delete[] this->n;
    this->n = new char[strlen(res) + 1];
    itoa(x, this->n, 10);
    return *(this);
}

Number& Number:: operator=(const char* x)
{
    delete[] this->n;
    this->b = 10;
    this->n = new char[strlen(x) + 1];
    strcpy(this->n, x);
    return *(this);
}
Number::Number(const int x)
{
    this->b = 10;
    char res[20]; 
    itoa(x, res, 10);
    this->n = new char[strlen(res) + 1];
    strcpy(this->n, res);
}
