#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,n,x,a,i,j,s,data[3001]= {0},o=0,o1=0;
    scanf("%d%d%d",&w,&h,&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&a);
        s=x+a;
        if(s>w) s=w;
        for(j=x+1;j<=s; j++) ++data[j];
    }
    for(i=1; i<=w; i++)
    {
        if(data[i]==0) ++o;
        else if(data[i]==1) ++o1;
    }
    printf("%d %d",h*o,h*o1);
    return 0;
}
