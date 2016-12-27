#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a[100001]={0},max,am=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(i<3) a[i]=0;
        else if(i>3)
        {
            max=a[i-3];
            if(i>4&&a[i-4]>max) max=a[i-4];
            if(i>5&&a[i-5]>max) max=a[i-5];
            a[i]+=max;
            if(a[i]>am) am=a[i];
        }
    }
    printf("%d",am);
    return 0;
}
