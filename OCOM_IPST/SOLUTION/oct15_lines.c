#include <stdio.h>
#include <stdlib.h>


typedef struct point
{
    double y0;
    double y1;
    //int idx;
}point;
point p[100010],t[100010];
long long sum=0;
int cmp(const void*a,const void*b)
{
    point aa=*(point*)a;
    point bb=*(point*)b;
    if(aa.y0>bb.y0) return 1;
    else return -1;
}

int merge(int left,int mid,int right)
{
    int i=left,j=mid+1,k,dt=0;
    for(k=left;k<=right;k++)
    {
        if(i>mid) {t[k]=p[j++];continue;}
        if(j>right) {t[k]=p[i++];continue;}
        if(p[j].y1<=p[i].y1)
        {
            if(p[j].y1==p[i].y1) sum+=mid-i;
            else sum+=mid-i+1;
            t[k]=p[j++];
        }
        else
        {
            t[k]=p[i++];
        }
    }
    for(k=left;k<=right;k++) p[k]=t[k];
    return 0;
}
int merge_sort(int left,int right)
{
    int mid=(left+right)/2;
    if(left>=right) return 0;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    merge(left,mid,right);
    return 0;
}
int main()
{
    int n,i;
    double x0,x1,m,c;
    scanf("%d",&n);
    scanf("%lf%lf",&x0,&x1);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&m,&c);
        p[i].y0=(m*x0)+c;
        p[i].y1=(m*x1)+c;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    merge_sort(0,n-1);
    printf("%lld",sum);
    return 0;
}
