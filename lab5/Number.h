#pragma once
#pragma warning(disable : 4996)
#include <iostream>

using namespace std;
class Number
{
	int b;
	char* n;
public:
	Number(const char* value, int base);  
	Number(const int x);
	~Number();
	Number(const Number& other); 
	Number(Number&& other);
	Number& operator=(Number&& other);
	Number& operator=(const int x);
	Number& operator=(const char* x);
	Number& operator--(); 
	Number& operator--(int); 
	bool operator<(const Number& other);
	bool operator<=(const Number& other);
	bool operator>(const Number& other);
	bool operator>=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	char operator[](const int i);
	friend Number operator+(const Number& l,const Number& r);
    Number operator-=(const Number& r);
    Number operator+=(const Number& r);
	friend Number operator-(const Number& l, const Number& r);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount()const; 
	int  GetBase()const; 
};
