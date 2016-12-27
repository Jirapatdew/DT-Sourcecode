#include <stdio.h>
#include <stdlib.h>

int pow(int x,int y)
{
    int i,d=1;
    for(i=0; i<y; i++) d*=x;
    return d;
}
int main()
{
    int a[1005]= {0},queue[10][1005]= {0},p[15]= {0};
    int n,i,j,max,d=10,x=1,c,u=0,k;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    max=a[0];
    for(i=1; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(max<a[i]) max=a[i];
    }
    while(max/d>0)
    {
        d*=10;
        x++;
    }
    for(i=1; i<=x; i++)
    {
        for(j=0; j<n; j++)
        {
            c=(a[j]%pow(10,i))/pow(10,i-1);
            queue[c][p[c]]=a[j];
            p[c]++;
        }
        for(j=0; j<10; j++)
        {
            if(p[j]>0)
            {
                k=0;
                while(p[j]>k)
                {
                    a[u++]=queue[j][k];
                    k++;
                }
                p[j]=0;
            }
        }
        u=0;
        //for(k=0;k<n;k++) printf("%6d ",a[k]);printf("\n");
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
