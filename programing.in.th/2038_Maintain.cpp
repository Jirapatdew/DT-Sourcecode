#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int p[205]={0};
int h[205]={0};

void unionset(int s,int t)
{
    if(h[s]>h[t]) p[t]=s;
    else
    {
        p[s]=t;
        if(h[s]==h[t]) h[t]++;
    }
}
int findset(int e)
{
    int tmp;
    while(p[e]!=e)
    {
        tmp=p[e];
        p[e]=p[p[e]];
        e=p[e];
    }
    return e;
}

struct dt
{
    int a;
    int b;
    int s;
    bool operator < (const dt &T) const
    {
        return s<T.s;
    }
    dt(int x,int y,int z)
    {
        a=x;
        b=y;
        s=z;
    }
};

int main()
{
    int n,w;
    int x,y,z;
    int a,b;
    int i,j;
    int sum,num;
    multiset<dt> data;
    multiset<dt>::iterator pt;
    scanf("%d%d",&n,&w);
    for(i=0;i<w;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        data.insert(dt(x,y,z));

        if(i<n-1) {printf("-1\n"); continue;}

        num=1;
        sum=0;
        pt=data.begin();
        for(j=1;j<=n;j++) p[j]=j;
        for(j=1;j<=n;j++) h[j]=0;
        for(j=0;j<=i&&num<n;j++)
        {
            a=pt->a;
            b=pt->b;
            p[a]=findset(a);
            p[b]=findset(b);
            if(p[a]!=p[b])
            {
                sum+=pt->s;
                num++;
                unionset(p[a],p[b]);
            }
            pt++;
        }
        if(num==n) printf("%d\n",sum);
        else printf("-1\n");
    }
    return 0;
}
