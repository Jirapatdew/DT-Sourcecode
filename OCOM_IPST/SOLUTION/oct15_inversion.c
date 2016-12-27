#include <stdio.h>
#include <stdlib.h>

int a[100010]={0};
int t[100010]={0};
long long sum=0;
int merge(int left,int mid,int right)
{
    int i=left,j=mid+1,k;
    for(k=left;k<=right;k++)
    {
        if(i>mid) {t[k]=a[j++];continue;}
        if(j>right) {t[k]=a[i++];continue;}
        if(a[j]<=a[i])//
        {
            sum+=mid-i+1;
            if(a[j]==a[i]) sum--;
            t[k]=a[j++];
        }
        else t[k]=a[i++];
    }
    for(k=left;k<=right;k++) a[k]=t[k];
    return 0;
}
int merge_sort(int left,int right)
{
    int mid=(left+right)/2;
    if(left>=right) return 0;//Less than equal to 0.
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    merge(left,mid,right);
    return 0;
}
int main()
{
    int n;
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    merge_sort(0,n-1);
    printf("%lld",sum);
    //for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
