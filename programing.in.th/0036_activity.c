#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    long long up=1,down=1;
    scanf("%d",&n);
    if(n%2==1) n++;
    for(i=n/2+1;i<=n;i++) up*=i;
    for(i=2;i<=n/2;i++) down*=i;
    printf("%lld",up/down);
    return 0;
}
