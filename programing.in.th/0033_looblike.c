#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,max=0,i;
    int chk[10005]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        chk[x]++;
        if(max<chk[x]) max=chk[x];
    }
    for(i=1;i<=10000;i++) if(max==chk[i]) printf("%d ",i);
    return 0;
}
