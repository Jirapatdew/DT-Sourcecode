#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,min,index,a;
    //int chk[15]={0};
    int t;
    int data[15]={0};
    scanf("%d",&n);
    scanf("%d",&data[1]);
    index=1;
    min=data[1];
    for(i=2;i<=9;i++)
    {
        scanf("%d",&data[i]);
        if(min>=data[i]) {min=data[i];index=i;}
    }
    t=n/min;
    a=n%min;
    for(i=index+1;i<=9;i++) data[i]-=data[index];
    for(i=9;i>index;i--)
    {
        if(a/data[i]>=1)
        {
            for(j=1;j<=a/data[i]&&t>0;j++) {printf("%d",i);t--;}
            a-=(a/data[i])*data[i];
        }
    }
    for(i=1;i<=t;i++) printf("%d",index);
    return 0;
}
