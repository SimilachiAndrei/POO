#include "Canvas.h"

int main()
{
    Canvas c(20,20);
    // 11 13  // 11 61  // 11 54 // cerc
    c.DrawLine(1, 1, 1, 3, '*');
    c.DrawLine(1, 1, 6, 1, 'a');
    c.DrawLine(1, 1, 5, 4, 'b');
    c.DrawCircle(13, 13, 5, 'c');
    c.Print();
}   

