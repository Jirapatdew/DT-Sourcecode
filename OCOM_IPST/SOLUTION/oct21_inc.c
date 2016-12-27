#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[1001],ans[1001];
    int dp[1001],c[1001],n,i,j,max=1,idx=0,d=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&array[i]);
    for(i=0; i<n; i++) c[i]=-1;
    dp[0] = 1;
    for(i = 1; i < n; i++ )
    {
        dp[i]=1;
        for(j = 0; j < i; j++ )
        {
            if( array[i] > array[j] )
            {
                if( dp[i] < dp[j]+1 )
                {
                    dp[i] = dp[j]+1;
                    c[i]=j;
                    if(max<dp[i]) {max=dp[i];idx=i;}
                }
            }
        }
    }
    printf("%d\n",max);
    i=idx;
    ans[d++]=array[idx];
    while(c[i]>-1)
    {
        i=c[i];
        ans[d++]=array[i];
    }
    for(i=d-1;i>=0;i--) printf("%d ",ans[i]);
   return 0;
}
