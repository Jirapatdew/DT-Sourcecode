#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[1010]={0};
    int a,b,j,i,n;
    int min=1000001,idx=0,sum,c,max=0;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
        if(data[i]>max) max=data[i];
    }
    if(a<max) a=max;
    for(i=a;i<=b;i++)
    {
        sum=0;c=0;
        for(j=0;j<n;j++)
        {
            if(c+data[j]>i) {sum+=i-c;c=data[j];}
            else c+=data[j];
        }
        sum+=i-c;
        if(min>sum) {min=sum;idx=i;}
    }
    printf("%d",idx);
    return 0;
}
