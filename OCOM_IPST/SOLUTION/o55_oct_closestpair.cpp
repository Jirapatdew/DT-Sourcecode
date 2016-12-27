#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define INF 9000000000000
using namespace std;

struct dt
{
    long long x,y;
};
int cmpx(const void*a,const void*b)
{
    dt *aa=(dt*)a;
    dt *bb=(dt*)b;
    if(aa->x>bb->x) return 1;
    else return -1;
}
int cmpy(const void*a,const void*b)
{
    dt *aa=(dt*)a;
    dt *bb=(dt*)b;
    if(aa->y>bb->y) return 1;
    else return -1;
}
dt a[100010],tmp[100010];
long long divide(int L,int R)
{
    int M=(L+R)/2,num=0;
    long long d1,d2,mn;
    if(L>=R) return INF;
    d1=divide(L,M);
    d2=divide(M+1,R);
    mn=MIN(d1,d2);
    for(int i=L;i<=R;i++)
        if(a[M].x-mn<=a[i].x&&a[i].x<=a[M].x+mn) tmp[num++]=a[i];
    qsort(tmp,num,sizeof(tmp[0]),cmpy);
    for(int i=0;i<num;i++)
        for(int j=i+1;j<num&&tmp[j].y<=tmp[i].y+mn;j++)
            mn=MIN(mn,((tmp[j].y-tmp[i].y)*(tmp[j].y-tmp[i].y)+(tmp[j].x-tmp[i].x)*(tmp[j].x-tmp[i].x)));
    return mn;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
    qsort(a,n,sizeof(a[0]),cmpx);
    printf("%lld\n",divide(0,n-1));
    return 0;
}
