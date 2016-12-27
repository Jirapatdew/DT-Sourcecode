#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,a[50100],sum=0,max;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    max=a[0];
    for(i=0;i<n;i++)
    {
       sum=0;
       for(j=i;j<n;j++)
       {
           sum+=a[j];
           if(sum>max) max=sum;
           if(sum<0) break;
       }
    }
    printf("%d",max);

    return 0;
}
