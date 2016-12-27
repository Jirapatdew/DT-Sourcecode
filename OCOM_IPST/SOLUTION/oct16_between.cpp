#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n,c,t;
    int l[30]={0},r[30]={0},m[30]={0};
    int u[30]={0};
    int idx[30]={0};
    scanf("%d%d",&n,&c);
    for(int i=1;i<=c;i++) scanf("%d%d%d",&m[i],&l[i],&r[i]);
    for(int i=1;i<=n;i++) idx[i]=i;
    int k;
    for(k=1;k<=c;k++)
    {
        t=0;
        for(int i=1;i<=c;i++)
        {
            if(idx[l[i]]<idx[r[i]])
            {
                if(idx[m[i]]<idx[l[i]]) {swap(idx[m[i]],idx[l[i]]);t=1;}
                if(idx[m[i]]>idx[r[i]]) {swap(idx[m[i]],idx[r[i]]);t=1;}
            }
            if(idx[l[i]]>idx[r[i]])
            {
                if(idx[m[i]]>idx[l[i]]) {swap(idx[m[i]],idx[l[i]]);t=1;}
                if(idx[m[i]]<idx[r[i]]) {swap(idx[m[i]],idx[r[i]]);t=1;}
            }
        }
        if(t==0) break;
    }
    if(t==1) printf("NO");
    else
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) if(idx[j]==i) printf("%d ",j);
        }
    }
    return 0;
}
