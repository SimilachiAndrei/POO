#include "student.h"

void student ::setname(char * c)
{
    strcpy(name,c);
}
char * student :: getname()
{
    return name;
}
void student :: setmath(float x)
{
    if(x>0&&x<=10)math=x;
}
void student :: seteng(float x)
{
    if(x>0&&x<=10)eng=x;
}
void student :: seth(float x)
{
    if(x>0&&x<=10)hist=x;
}
float student :: getmath()
{
    return math;
}
float student :: geteng()
{
    return eng;
}
float student :: geth()
{
    return hist;
}
float student :: avg()
{   if(math!=0&&hist!=0&&eng!=0)
       return (math+hist+eng)/3;
}
