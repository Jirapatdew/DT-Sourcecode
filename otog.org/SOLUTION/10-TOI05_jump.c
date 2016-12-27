#include <stdio.h>
#include <stdlib.h>

int line[30001]={0};
int n;
int binarysearch(int key)
{
    int high=n-1,low=0,mid=(n-1)/2;
    while(low<=high)
    {
        mid = ( low + high ) / 2;
        if(line[mid]==key) return mid;
        else if(line[mid]>key) high=mid-1;
        else if(line[mid]<key) low=mid+1;
    }
    if(line[mid]>key) return mid-1;
    else return mid;
}
int main()
{
    int k,a,max=0;
    int i,st=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&line[i]);
    for(i=0;i<n;i++)
    {
        a=binarysearch(line[i]+k);
        if(max<a-i) max=a-i;
    }
    printf("%d",max);
    return 0;
}
