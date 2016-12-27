#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,k,l,sum=0;
int chk[12]={0};
int ans[12]={0};
int perm(int x)
{
    if(x<=k)
    {
        for(int i=ans[x-1]+1;i<=n;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                ans[x]=i;
                perm(x+1);
                chk[i]=0;
            }
        }
    }
    else
    {
        sum++;
        if(sum!=l) return 0;
        for(int i=1;i<=k;i++) printf("%d ",ans[i]);
        printf("\n");
        exit(0);
    }
}
int main()
{

    scanf("%d%d%d",&n,&k,&l);
    perm(1);
    return 0;
}
