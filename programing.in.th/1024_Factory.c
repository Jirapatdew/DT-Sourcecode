#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int delta=1000001;

int main()
{
    int n,i,j,k,x,y;
    int data[1005]={0},a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    for(i=2;i<=n;i++) data[i]+=data[i-1];
    for(i=2;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            a=data[i-1];
            b=data[j-1]-data[i-1];
            c=data[n]-data[j-1];
            if(a>=b&&a>=c)
            {
                if(b>=c) k=a-c;
                else k=a-b;
            }
            else if(b>=c&&b>=a)
            {
                if(a>=c) k=b-c;
                else k=b-a;
            }
            else if(c>a&&c>b)
            {
                if(b>=a) k=c-a;
                else k=c-b;
            }
            if(k<delta)
            {
                delta=k;
                x=i;
                y=j;
            }
        }
    }
    printf("%d %d",x,y);
    return 0;
}
