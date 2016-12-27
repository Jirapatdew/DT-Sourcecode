#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,t=0,sum,i;
    long long th[25]={0},q_th[25]={0};
    th[0]=1;
    for(i=1;i<=20;i++) th[i]=th[i-1]*3;
    q_th[0]=1;
    for(i=1;i<=20;i++) q_th[i]=th[i]+q_th[i-1];
    scanf("%lld",&n);
    sum=n;
    while(1)
    {
        for(i=0;i<20;i++)
            if(q_th[i]+n<th[i+1]) break;//ให้รู้ว่าใช้ตัวที่ i แน่ๆ
        n=abs(n-th[i]);
        t++;
        sum+=th[i];
        if(n==0) break;
    }
    printf("%lld %lld",t,sum/2);

    return 0;
}
