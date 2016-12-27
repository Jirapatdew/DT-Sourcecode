#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,sum=0,i;
    int c[105],a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) c[i]=1000;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        if(c[a]>b) c[a]=b;
    }
    for(i=1;i<=n;i++) sum+=c[i];
    printf("%d\n",sum);
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",i,c[i]);
    }
    return 0;
}
