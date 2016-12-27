#include <stdio.h>
#include <stdlib.h>

int main()//use array linklist
{
    int n,k,x,p,tm,j,i;
    int sum[25]={0};
    int val[105]={0};
    int link[105]={0};
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&val[i]);
    for(i=1;i<n;i++) link[i]=i+1;
    link[n]=1;
    p=1;
    for(i=1;i<n;i++)
    {
        scanf("%d",&x);
        for(j=1;j<=x;j++)
        {
            tm=p;
            p=link[p];
        }
        if(i%k==0) sum[k]+=val[p];
        else sum[i%k]+=val[p];
        link[tm]=link[p];
        p=link[p];
    }
    scanf("%d",&x);
    if(n%k==0) sum[k]+=val[p];
    else sum[n%k]+=val[p];
    for(i=1;i<=k;i++) printf("%d\n",sum[i]);
    return 0;
}
