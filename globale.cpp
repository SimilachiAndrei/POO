#include "student.h"

int names(student p1,student p2)
{
    if(strcmp(p1.getname(),p2.getname())==0)
        return 0;
    else if(strcmp(p1.getname(),p2.getname())>0)
        return 1;
    else return -1;
}

int math(student p1,student p2)
{
    if(p1.getmath()==p2.getmath())return 0;
    else if(p1.getmath()>p2.getmath())return 1;
    else return -1;
}
int eng(student p1,student p2)
{
    if(p1.geteng()==p2.geteng())return 0;
    else if(p1.geteng()>p2.geteng())return 1;
    else return -1;
}
int hist(student p1,student p2)
{
    if(p1.geth()==p2.geth())return 0;
    else if(p1.geth()>p2.geth())return 1;
    else return -1;
}
int avg(student p1,student p2)
{
 if(p1.avg()==p2.avg())return 0;
 else if(p1.avg()>p2.avg())return 1;
 else return -1;
}
