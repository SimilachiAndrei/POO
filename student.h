#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;
class student
{
private:
    char name[20];
    float math,eng,hist;

public:
    void setname(char *c);
    char * getname();
    void setmath(float x);
    float getmath();
    void seteng(float x);
    float geteng();
    void seth(float x);
    float geth();
    float avg();
};


#endif // STUDENT_H_INCLUDED
