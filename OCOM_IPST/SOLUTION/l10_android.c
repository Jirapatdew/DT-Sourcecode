#include <stdio.h>
#include <stdlib.h>

int mem[1005]={0};
int chk[1005]={0};
int time[1005]={0};
int m,memk;
int d=1;
int use(int b,int k)
{
    if(b<=memk) {memk-=b;return 0;}
    memk-=b;
    for(;d<k;d++)
    {
        if(chk[time[d]]==d&&memk<0)
        {
            memk+=mem[time[d]];
            chk[time[d]]=0;
        }
        if(memk>=0) break;
    }
}
int main()
{
    int p,s;
    int i,k,a;
    scanf("%d%d%d",&p,&s,&m);
    for(i=1;i<=p;i++) scanf("%d",&mem[i]);
    memk=m;
    for(k=1;k<=s;k++)
    {
        scanf("%d",&time[k]);
        if(chk[time[k]]==0)
        {
            use(mem[time[k]],k);
            chk[time[k]]=k;
        }
        else
        {
            chk[time[k]]=k;
        }
    }
    printf("%d",memk);
    return 0;
}
