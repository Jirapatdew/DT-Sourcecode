#include <stdio.h>
#include <stdlib.h>

int data[100010]={0},p=2;

int binary(int low,int high,int key)
{
    int mid=(low+high)/2;
    if(low<high)
    {
        if(data[mid]==key) return 0;
        if(data[mid]<key) return binary(mid+1,high,key);
        if(data[mid]>key) return binary(low,mid-1,key);
    }
    else
    {
        if(data[mid]==key) return 0;
        if(data[mid]<key) return mid+1;
        if(data[mid]>key) return mid;
    }
}
int main()
{
    int n;
    int i,key,idx;
    scanf("%d",&n);
    scanf("%d",&data[1]);
    for(i=1;i<n;i++)
    {
        scanf("%d",&key);
        idx=binary(1,p-1,key);
        if(idx!=0) data[idx]=key;
        if(idx==p) p++;
    }
    printf("%d",p-1);
    return 0;
}
