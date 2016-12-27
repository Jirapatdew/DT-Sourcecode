#include <stdio.h>
#include <stdlib.h>
//you can use LCS or LIS for solve this problem
//In this program I will use LIS for solve
//because LCS use space 3000 x 3000
//but you can implement array 2 x 3000
//And LIS use array 1D 3000
int N[3005]={0};
int S[3005]={0};
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
    int n,a;
    int key,idx;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        N[a]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        S[i]=N[a];
    }
    data[1]=S[1];
    for(i=2;i<=n;i++)
    {
        key=S[i];
        idx=binary(1,p-1,key);
        if(idx!=0) data[idx]=key;
        if(idx==p) p++;
    }
    printf("%d",p-1);
    return 0;
}
