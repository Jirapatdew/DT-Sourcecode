#include <stdio.h>
#include <stdlib.h>

int a[1000005]={0};
int main()
{
    int q,i,j,x,y,d,sum;
    scanf("%d",&q);
    for(i=1;i<=1000000;i++)
        for(j=i;j<=1000000;j+=i)
            a[j]++;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&x,&y,&d);
        sum=0;
        for(j=x;j<=y;j++) if(a[j]==d) sum++;
        printf("%d\n",sum);
    }
    return 0;
}
