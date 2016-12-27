#include <stdio.h>
#include <stdlib.h>

int d[10000]={0};
int t[10000]={0};
int merge(int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k;
    for(k=left;k<=right;k++)
    {
        if(i>mid) {t[k]=d[j++];continue;}
        if(j>right) {t[k]=d[i++];continue;}
        t[k]=(d[i]<d[j])?d[i++]:d[j++];
    }
    for(k=left;k<=right;k++) d[k]=t[k];
}
int mergesort(int left,int right)
{
    int mid;
    if(left>=right) return 0;
    mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid+1,right);
    merge(left,mid,right);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    mergesort(0,n-1);
    for(i=0;i<n;i++) printf("%d ",d[i]);
    return 0;
}
