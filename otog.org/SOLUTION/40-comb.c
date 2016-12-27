#include <stdio.h>
#include <stdlib.h>
int n,k,l;
int ans[20]={0};
int chk[20]={0};
int perm(int a)
{
    int i;
    if(a<=k)
    {
        for(i=ans[a-1]+1;i<=n;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                ans[a]=i;
                perm(a+1);
                chk[i]=0;
            }
        }
    }
    else if(l==1)
    {
        for(i=1;i<=k;i++) printf("%d ",ans[i]);
        printf("\n");
        exit(0);
    }
    else l--;
}
int main()
{

    scanf("%d%d%d",&n,&k,&l);
    perm(1);
    return 0;
}
