#include "globale.h"
using namespace std;

int main()
{
    student s;
    student s2;
    s.setname("Andrei");
    cout<<s.getname()<<endl;
    s.setmath(5.16);
    s.seteng(6.25);
    s.seth(7.15);
    cout<<s.getmath()<<endl;
    cout<<s.avg()<<endl;
    s2.setmath(7);
    cout<<s2.getmath()<<endl;
    cout<<math(s2,s);
}
