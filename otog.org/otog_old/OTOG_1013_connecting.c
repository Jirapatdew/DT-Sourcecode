#include <stdio.h>
#include <stdlib.h>

long long port[200005][2]= {0};
int cmp(const void*a,const void*b)
{
    long long *aa=(long long*)a;
    long long *bb=(long long*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
long long binary(long long key,long long imin,long long imax)
{
    int mid;
    while(imin<=imax)
    {
        mid=(imin+imax)/2;
        if(key==port[mid][0]) return port[mid][1];
        if(key>port[mid][0])
        {
            imin=mid+1;
            continue;
        }
        if(key<port[mid][0])
        {
            imax=mid-1;
            continue;
        }
    }
    return -1;
}
int main()
{
    long long n,m,total,i,pass=0;
    long long x,y;
    long long line,re=0;
    scanf("%lld%lld%lld",&n,&m,&total);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&port[i][0]);
        port[i][1]=i+1;
    }
    qsort(port,n,sizeof(port[0]),cmp);
    for(i=1; i<=m; i++)
    {
        scanf("%lld",&line);
        if(pass==0)
        {
            re=binary(total-line,0,n-1);
            if(re!=-1)
            {
                x=re;
                y=i;
                pass=1;
            }
        }

    }
    printf("%lld %lld",x,y);
    return 0;
}
