#include <stdio.h>
#include <stdlib.h>

int V[105][105]={0};
int n1[105][105]={0};
int n2[105][105]={0};
int A[105]={0},B[105]={0},T[105]={0};
int max={0};
int ab(int a)
{
    return a<0?-a:a;
}
int main()
{
    int m,k;
    int i,j;
    scanf("%d%d",&m,&k);
    for(i=1;i<=k;i++) scanf("%d%d%d",&A[i],&B[i],&T[i]);
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(j<A[i]) V[i][j]=V[i-1][j];
            else
            {
                if(V[i-1][j]<V[i-1][j-A[i]]+B[i])
                {
                    V[i][j]=V[i-1][j-A[i]]+B[i];
                    n1[i][j]=n1[i-1][j-A[i]];
                    n2[i][j]=n2[i-1][j-A[i]];
                    if(T[i]==0) n1[i][j]++;
                    else n2[i][j]++;
                }
                else if(V[i-1][j]>V[i-1][j-A[i]]+B[i])
                {
                    V[i][j]=V[i-1][j];
                    n1[i][j]=n1[i-1][j];
                    n2[i][j]=n2[i-1][j];
                }
                else
                {
                    V[i][j]=V[i-1][j];
                    if(ab(n1[i-1][j]-n2[i-1][j])>ab((n1[i-1][j-A[i]]+((T[i]==0)?1:0))-(n2[i-1][j-A[i]]+((T[i]==1)?1:0))))
                    {
                        n1[i][j]=n1[i-1][j-A[i]];
                        n2[i][j]=n2[i-1][j-A[i]];
                        if(T[i]==0) n1[i][j]++;
                        else n2[i][j]++;
                    }
                    else
                    {
                        n1[i][j]=n1[i-1][j];
                        n2[i][j]=n2[i-1][j];
                    }
                }

            }
        }
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(n1[i][j]>n2[i][j])
            {
                if(n2[i][j]>=n1[i][j]/2-((n1[i][j]%2==0)?1:0))
                {
                    if(max<V[i][j]) max=V[i][j];
                }
            }
            else
            {
                if(n1[i][j]>=n2[i][j]/2-((n2[i][j]%2==0)?1:0))
                {
                    if(max<V[i][j]) max=V[i][j];
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}
