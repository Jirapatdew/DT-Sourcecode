#include<stdio.h>
int cnt[100]= {0},ans[100]= {0},in,k,l;

void cal(int N)
{
    int a,b;
    if(N<=k&&l>0)
    {
        for(a=ans[N-1]+1; a<=in; a++)
        {
            if(cnt[a]==0)
            {
                cnt[a]=1;
                ans[N]=a;
                cal(N+1);
                cnt[a]=0;
            }
        }
    }
    else
    {
        l--;
        if(l==0)
        {
            for(a=1; a<=k; a++)
                printf("%d ",ans[a]);
        }
    }
}

int main()
{
    scanf("%d%d%d",&in,&k,&l);
    cal(1);
    return 0;
}
