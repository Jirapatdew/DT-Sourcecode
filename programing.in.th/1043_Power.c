#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pw(int dt,int a)
{
    int i,y=1;
    for(i=0;i<a;i++) y*=dt;
    return y;
}
int main()
{
    int n,x;
    int i,dt=2,a,rt=0,s,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        dt=a=2;rt=0;
        while(dt>1)
        {
            dt=pow(x,1.0/a);
            s=pw(dt,a);
            d=pw(dt+1,a);
            if((s==x)||(d==x)) rt=a;
            a++;
        }
        if(rt==0) printf("NO\n");
        else printf("%d\n",rt);
    }
    return 0;
}
