#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[100001];
    int n,i,max=0,min1=100001,min2=100001,x;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&data[i]);
        if(data[i]>max)max=data[i];
        if(data[i]<min1) {min1=data[i];x=i;}
    }
    data[x]=100001;
    for(i=0; i<n; i++) if(data[i]<min2) min2=data[i];
    if(min1+min2>max) printf("no");
    else printf("yes");

    return 0;
}
