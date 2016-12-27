#include <stdio.h>
#include <stdlib.h>

long long data[100005]={0};
int main()
{
    int n,k,i,j;
    long long sum=0;
    scanf("%d%d",&n,&k);
    data[1]=1;
    for(i=2;i<=n;i++)
    {
        if(i<=k) data[i]=data[i-1]*2;
        else
        {
            sum=0;
            for(j=i-k;j<i;j++) sum+=data[j];
            data[i]=sum%2009;
        }
    }
    printf("%lld",data[n]%2009);
    return 0;
}
