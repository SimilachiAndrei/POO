#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <cstring>
#pragma warning (disable : 4996)
using namespace std;
int  Math::Add(int a, int b)
{
    return a + b;
}
int  Math::Add(int a, int b, int c)
{
    return a + b + c;
}

double Math::Add(double a, double b)
{
    return a + b;
}
double Math::Add(double a, double b,double c)
{
    return a + b + c;
}
int  Math::Mul (int a, int b)
{
    return a * b;
}

int  Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

double Math::Mul(double a, double b)
{
    return a * b;
}
double Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    int* p = &count;
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += *(++p);
    }
    return sum;
}

char* Math::Add(const char* p1, const char* p2)
{
    if (p1 == nullptr || p2 == nullptr)
    {
        return nullptr;
    }
    char* p=new char[strlen(p1)+strlen(p2)+1];
    strcpy(p, p1);
    strcat(p, p2);
    return p;
}




