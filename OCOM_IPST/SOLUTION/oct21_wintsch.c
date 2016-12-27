#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n,i;
    int val[1005]={0},k=0,st;
    int s[1005]={0};
    int t[1005]={0};
    int w[1005]={0};
    int ans[1005]={0},d=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d%d",&s[i],&t[i],&w[i]);
    for(i=1;i<=n;i++)
    {
        for(k=i;k>=1;k--)
        {
            if(t[k]<=s[i]) break;
        }
        val[i]=max(val[i-1],w[i]+val[k]);
    }
    printf("%d\n",val[n]);
    st=t[n];
    for(i=n;i>=1;i--)
    {
        if(t[i]>st) continue;
        if(val[i]!=val[i-1]) {ans[d++]=i;st=s[i];}
    }
    printf("%d\n",d);
    for(i=d-1;i>=0;i--) printf("%d ",ans[i]);

    return 0;
}
