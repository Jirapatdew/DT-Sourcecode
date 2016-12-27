#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[100],y[100],a,b,i,j,n=0,k;
    scanf("%d%d",&a,&b);
    for(i=1; i<=a; i++)
    {
        if(a%i==0)
        {
            x[n]=i;
            ++n;
        }
    }
    n=0;
    for(i=1; i<=b; i++)
    {
        if(b%i==0)
        {
            y[n]=i;
            ++n;
        }
    }
    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            if(x[i]==y[j])
            {
                k=x[i];
            }
        }
    }
    printf("%d",k);
    return 0;
}
