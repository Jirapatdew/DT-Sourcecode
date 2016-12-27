#include <stdio.h>
#include <stdlib.h>

long long nr(long long a)
{
    long long i,sum=1;
    for(i=a-1; i<=a; i++) sum=sum*i;
    return sum/2;
}
int main()
{
    long long n,a,num=0,i,ti,j;
    long long data[100001]= {0},x;
    scanf("%lld",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&x);
        ++data[x];
    }
    scanf("%lld",&a);
    for(i=0,ti=a; ti>a/2; i++,ti--)
    {
        if(data[i]>0)
        {
            num=num+(data[i]*data[ti]);
            data[ti]=0;
            data[i]=0;
        }
    }
    if(a%2==0&&data[a/2]>1)
    {
        num=num+nr(data[a/2]);
        data[a/2]=0;
    }
    printf("%lld",num);
    return 0;
}
