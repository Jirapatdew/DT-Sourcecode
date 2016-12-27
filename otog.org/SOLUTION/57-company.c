#include <stdio.h>
#include <stdlib.h>
int p[25000]={0};
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
int Union(int a,int b)
{
    p[b]=a;
}
int main()
{
    int k,a,n,m,x,y;
    int i,j,cnt=0;
    int extra=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n+m;i++) p[i]=i;
    for(i=1;i<=n;i++)
    {
        p[i]=find(i);
        scanf("%d",&k);
        if(k==0) extra++;
        for(j=1;j<=k;j++)
        {
            scanf("%d",&a);
            p[a+n]=find(a+n);
            if(p[i]!=p[a+n]) Union(p[i],p[a+n]);
        }
    }
    for(i=1;i<=n;i++) if(p[i]==i) cnt++;
    if(extra==n) printf("%d",cnt);
    else printf("%d",cnt-1);
    return 0;
}
