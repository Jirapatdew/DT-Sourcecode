#include <stdio.h>
#include <stdlib.h>

int data[1010]={0},p=2;
int index[1010]={0};
int parent[1010]={0};
int input[1010]={0};
int ans[1010]={0};
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
    int i,key,idx,pt,d;
    scanf("%d",&n);
    scanf("%d",&input[1]);
    data[1]=input[1];
    index[1]=1;
    parent[1]=0;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&input[i]);
        key=input[i];
        idx=binary(1,p-1,key);
        if(idx!=0) {data[idx]=key;index[idx]=i;parent[i]=index[idx-1];}
        if(idx==p) p++;
    }
    printf("%d\n",p-1);
    pt=index[p-1];
    d=p-1;
    while(pt>0)
    {
        ans[d--]=input[pt];
        pt=parent[pt];
    }
    for(i=1;i<p;i++) printf("%d ",ans[i]);
    return 0;
}
