#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n;
    long long total=0,a;
    long long i,j,data[10005]={0};
    long long ans[10005]={0};
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&data[i]);
    for(i=1;i<n;i++) data[i]+=data[i-1];
    for(i=n-1;i>0;i--)
    {
        a=(((data[i]-data[i-1])*i)-data[i-1])%49999;
        total+=a;
        total%=49999;
    }
    /*for(i=0;i<n;i++)//ตรงๆไม่ทัน
    {
        for(j=i+1;j<n;j++)
        {
            total+=abs(data[i]-data[j]);
            total%=49999;
        }
    }*/
    ans[2]=1;
    for(i=3;i<=n;i++)
    {
        ans[i]=(ans[i-1]*(i-2))%49999;
    }
    printf("%lld",ans[n]*total%49999);


    return 0;
}
