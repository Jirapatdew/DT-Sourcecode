#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long *aa=(long long*)a;
    long long *bb=(long long*)b;
    if(aa[2]>bb[2]) return 1;
    else return -1;
}
int main()
{
    long long n,i,max=0,total,sum=0;
    long long data[100005][3];
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&data[i][0],&data[i][1]);
        data[i][2]=data[i][1]-2*data[i][0];
    }
    qsort(data,n,sizeof(data[0]),cmp);
    max=data[n-1][2]-(n-1)*(n-1);
    for(i=n-1;i>=0;i--)
    {
        sum+=data[i][2];
        total=sum-i*i;
        if(total>max) max=total;
    }
    printf("%lld",max);
    return 0;
}
