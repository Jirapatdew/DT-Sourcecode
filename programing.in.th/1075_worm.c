#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long *aa=(long long*)a;
    long long *bb=(long long*)b;
    if(aa[1]>bb[1]) return 1;
    else if(aa[1]==bb[1]&&aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    long long n,i,a=0,b=0;
    double max=0,x;
    long long data[100005][2]={0};
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld%lld",&data[i][0],&data[i][1]);
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=1;i<n;i++) data[i][0]+=data[i-1][0];
    for(i=0;i<n;i++)
    {
        x=(double)data[i][0]/data[i][1];
        if(max<x)
        {
            max=x;
            a=data[i][0];
            b=data[i][1];
        }
    }
    printf("%lld %lld",a,b);
    return 0;
}
