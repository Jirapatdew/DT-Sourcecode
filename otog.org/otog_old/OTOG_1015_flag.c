#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    long long chk[2]={0},a,b;
    scanf("%d",&n);
    chk[0]=1;
    for(i=2;i<n;i++)
    {
        a=chk[0];
        b=chk[1];
        chk[0]=a+b;
        chk[1]=a;
    }
    printf("%lld",(chk[0]+chk[1])*2);
    return 0;
}
