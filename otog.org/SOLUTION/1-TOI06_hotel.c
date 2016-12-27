#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    sum+=(n/15)*3000;
    n=n%15;
    if(n>10) sum+=3000;
    else
    {
        sum+=(n/5)*1500;
        n=n%5;
        if(n>3) sum+=1500;
        else
        {
            sum+=(n/2)*800;
            n=n%2;
            sum+=(n)*500;
        }
    }
    printf("%d",sum);
    return 0;
}
