#include <stdio.h>
#include <stdlib.h>
#define ab(a) ((a>0)?a:-a)
int main()
{
    int t,i,n,d,k;
    int plus,minus;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d",&n,&d,&k);
        plus=(n+1)/2;
        minus=n/2;
        if(d>=0)
        {
            plus-=d/k;
            if(plus*k-(d%k)>=minus) printf("yes\n");
            else printf("no\n");
        }
        else
        {
            d=ab(d);
            minus-=d/k;
            if(minus*k-(d%k)>=plus) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
