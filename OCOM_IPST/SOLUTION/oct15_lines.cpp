#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

double tree[100010]={0};
int MaxVal;
double A[100010][2]={0};
double B[100010]={0};
int cmp(const void*a,const void*b)
{
    double *aa=(double*)a;
    double *bb=(double*)b;
    if(aa[0]>bb[0]) return 1;
    else return 0;
}
int cmp2(const void*a,const void*b)
{
    double aa=*(double*)a;
    double bb=*(double*)b;
    if(aa>bb) return 1;
    else return -1;
}
void update(int idx ,double val)
{
    while(idx<=MaxVal)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
double freqTo(int idx)
{
    double sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void create(int n)
{
    int idx,z,y;
    double sum;
    for(idx=1;idx<=n;idx++)
    {
        sum=tree[idx];
        z=idx-(idx&-idx);
        y=idx-1;
        while(y>z)
        {
            sum+=tree[y];
            y-=(y&-y);
        }
        tree[idx]=sum;
    }
}
int main()
{
    int n;
    double x0,x1,m,c,y0,y1,sum=0;
    scanf("%d",&n);
    scanf("%lf%lf",&x0,&x1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&m,&c);
        y0=m*x0+c;
        y1=m*x1+c;
        A[i][0]=y0;
        A[i][1]=y1;
        B[i]=y1;
    }
    qsort(A+1,n,sizeof(A[0]),cmp);
    qsort(B+1,n,sizeof(B[0]),cmp2);
    MaxVal=n;
    for(int i=1;i<=n;i++) tree[i]=1;
    create(n);
    double *pt;
    int id;
    for(int i=1;i<=n;i++)
    {
        pt=lower_bound(B+1,B+n+1,A[i][1]);
        id=pt-B-1;
        sum+=freqTo(id);
        update(pt-B,-1);
    }
    printf("%.0lf",sum);
    return 0;
}
