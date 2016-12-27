#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    while(n>0)
    {
        sum+=n/5;
        n/=5;
    }
    printf("%d",sum);
    return 0;
}
