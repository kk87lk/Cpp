#include <iostream>
#include <memory>

int  main(int argc,char argc[])
{
    typedef int *g1;
    g1 a;
    using g2 = int *;
    g2 b;

    return 0;
}