#include "Car3.h"


int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    Car gau88;
    gau88.InitMembers("gau88", 50);
    gau88.Accel();
    gau88.Accel();
    gau88.Break();
    gau88.ShowCarState();

    return 0;
}