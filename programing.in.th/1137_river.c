#include <stdio.h>
#include <stdlib.h>

long long total=0;
long long n,data[1000005]={0};
long long chk()
{
    long long a,b;
    a=data[n]+data[1]+data[n-1]+data[1];
    b=data[2]+data[1]+data[n]+data[2];
    n-=2;
    if(a<b) return a;
    else return b;
}
int main()
{
    int i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) scanf("%lld",&data[i]);
    while(n>0)
    {
        if(n==1||n==2) {total+=data[n];break;}
        if(n==3) {total+=data[n]+data[n-1]+data[n-2];break;}
        total+=chk();
    }
    printf("%lld",total);
    return 0;
}
