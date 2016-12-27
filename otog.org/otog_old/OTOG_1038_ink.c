#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//อย่าทำ breadth-first search ถ้าทำโง่มากๆๆๆ


int main()
{
    long long int s,n;
    long long int i,x,y;
    double r;
    scanf("%lld%lld",&s,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        r=(x*x+y*y)*M_PI/s;
        if(x==0&&y==0) printf("%lld\n",(long long int)r);
        else printf("%lld\n",(long long int)r+1);
    }
    return 0;
}
