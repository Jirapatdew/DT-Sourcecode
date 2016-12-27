#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int v,t,i,now;
    scanf("%d",&n);
    scanf("%d%d",&t,&v);
    now=v;
    printf("0\n");
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&t,&v);
        if(v>now) printf("%d\n",v-now);
        else if(v==now) printf("%d\n",now);
        else {printf("0\n");now=v;}
    }
    return 0;
}
