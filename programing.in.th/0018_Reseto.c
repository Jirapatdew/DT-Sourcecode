#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,x[1001]={0},y[1001]={0},i,j,a=0;
    scanf("%d%d",&n,&k);
    for(i=2; i<=n; i++) x[i]=i;
    for(i=2; i<=n; i++)
    {
        if(x[i]!=0)
        {
            y[a]=x[i];
            ++a;
            for(j=i+1; j<=n; j++)
            {
                if(x[j]%x[i]==0&&x[j]!=0)
                {
                    y[a]=x[j];
                    ++a;
                    x[j]=0;
                }
            }
            x[i]=0;
        }
    }
    if(k<n)
    printf("%d",y[k-1]);
    return 0;
}
