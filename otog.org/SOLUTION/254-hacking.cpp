#include <stdio.h>
#include <math.h>
#include "hacking.h"

using namespace std;

int main()
{
    int n,sq,a;
    n=GetN();
    sq=sqrtl(n);
    a=sq+1;
    while(!CheckF(a))
    {
        a+=sq;
        if(a>n) a=n;
    }
    for(int i=a-sq;i<=n;i++)
    {
        if(CheckF(i)) {printf("%d",i-1);return 0;}
    }
    return 0;
}
