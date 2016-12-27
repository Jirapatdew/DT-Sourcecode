#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d%d",&m,&p);
        if(n<m||p>n) printf("no\n");
        else if(((n+p)-(m*2))==2&&m!=n-p) printf("yes\n");
        else if(((n+p)-(m*2))<=1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
