#include <stdio.h>
#include <stdlib.h>


int cnt[100]= {0},ans[100],in;
int n,k,l;
void cal(int N)
{
    int a,b;
    if(N<k)
    {
        for(a=0; a<n; a++)
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
        if(l==0) for(a=0; a<k; a++)
            printf("%d ",ans[a]+1);
    }
}

int main()
{

    scanf("%d%d%d",&n,&k,&l);
    cal(0);
    return 0;
}

