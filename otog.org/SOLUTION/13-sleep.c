#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,t,j;
    int x,y;
    int a,b;
    scanf("%d",&t);
    for(j=0; j<t; j++)
    {
        scanf("%d",&n);
        scanf("%d%d",&x,&y);
        for(i=2; i<=n; i++)
        {
            scanf("%d%d",&a,&b);
            if(a>x) x=a;
            if(b<y) y=b;
        }
        if(x<=y) printf("no\n");
        else printf("yes\n");
    }

    return 0;
}
