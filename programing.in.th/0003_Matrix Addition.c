#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,t,i,j,matrix[2][100][100],sum=0;
    scanf("%d%d",&m,&n);
    for(t=0;t<2;t++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&matrix[t][i][j]);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=matrix[0][i][j]+matrix[1][i][j];
            printf("%d ",sum);
        }
        printf("\n");
    }

    return 0;
}
