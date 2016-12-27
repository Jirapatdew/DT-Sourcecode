#include <stdio.h>
#include <stdlib.h>
#define mx 9000000000001;
long long delta=mx;
struct point
{
  long long x;
  long long y;
}p[100005],tmp[100005];

int cmp_x(const void*a,const void*b)
{
    struct point *aa=(struct point*)a;
    struct point *bb=(struct point*)b;
    if(aa->x > bb->x) return 1;
    else return -1;
}
int cmp_y(const void*a,const void*b)
{
    struct point *aa=(struct point*)a;
    struct point *bb=(struct point*)b;
    if(aa->y > bb->y) return 1;
    else return -1;
}
long long min(long long a,long long b)
{
    if(a<b) return a;
    else return b;
}
long long cal(long long a,long long b,long long c,long long d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
long long closest_pair(long long left,long long right)
{
    long long mid=(left+right)/2;
    long long d_l,d_r,num=0,i,j,t;

    if(left>=right) return mx;
    d_l=closest_pair(left,mid);
    d_r=closest_pair(mid+1,right);
    delta=min(d_l,d_r);

    for(i=left;i<=right;i++)
    {
        if(p[mid].x-delta<=p[i].x&&p[i].x<=p[mid].x+delta) tmp[num++]=p[i];
    }
    qsort(tmp,num,sizeof(tmp[0]),cmp_y);
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num&&tmp[j].y<=tmp[i].y+delta;j++)
        {
            t=cal(tmp[i].x,tmp[i].y,tmp[j].x,tmp[j].y);
            if(t<delta) delta=t;
        }
    }
    return delta;
}
int main()
{
    long long n;
    long long i;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(p[0]),cmp_x);
    printf("%lld",closest_pair(0,n-1));
    return 0;
}
