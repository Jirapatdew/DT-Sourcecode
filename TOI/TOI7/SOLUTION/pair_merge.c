#include <stdio.h>
#include <stdlib.h>

int d[100005][2]={0};
int t[100005][2]={0};
double total=0;
int merge(int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k;
    double sum=0,dt=0;
    for(k=left;k<=right;k++)
    {
        if(i>mid) {t[k][1]=d[j][1];t[k][0]=d[j][0];j++;continue;}
        if(j>right||d[i][1]<=d[j][1])
        {
            t[k][1]=d[i][1];
            t[k][0]=d[i][0];
            total+=sum+(d[i][0]*dt);
            i++;
        }
        else if(d[i][1]>d[j][1])
        {
            t[k][1]=d[j][1];
            t[k][0]=d[j][0];
            sum+=d[j][0];
            dt++;
            j++;
        }
    }
    for(k=left;k<=right;k++) {d[k][0]=t[k][0];d[k][1]=t[k][1];}
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
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&d[i][0],&d[i][1]);
    qsort(d,n,sizeof(d[0]),cmp);
    mergesort(0,n-1);
    printf("%.0f",total);
    return 0;
}
