#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[9],i,z=0,k,m,j;
    for (i=0; i<9; i++)
    {
        scanf("%d",&a[i]);
        z=z+a[i];
    }
    j=z-100;
    for (i=0; i<9; i++)
    {
        for (k=i+1; k<9; k++)
        {
            if (j==a[i]+a[k])
            {
                a[i]=0;
                a[k]=0;
            }
        }
    }
    for (m=0; m<9; m++)
    {
        if(a[m]!=0) printf("%d\n",a[m]);
    }
    return 0;
}
