#include <stdio.h>
#include <stdlib.h>
int p[100005]={0};
int h[100005]={0};

void unionset(int s,int t)
{
    if(h[s]>h[t]) p[t]=s;
    else
    {
        p[s]=t;
        if(h[t]==h[s]) h[t]++;
    }
}
int findset(int e)
{
    while(e!=p[e])
    {
        p[e]=p[p[e]];
        e=p[e];
    }
    return e;
}
int main()
{

    int i;
    int n,m,a,b;
    int q,c,d;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++) p[i]=i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        p[a]=findset(a);
        p[b]=findset(b);
        if(p[a]!=p[b])
        {
            unionset(p[a],p[b]);
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&c,&d);
        p[c]=findset(c);
        p[d]=findset(d);
        if(p[c]==p[d]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
