//má¶Ç n¤ÍÅÑÁ
#include <stdio.h>
#include <stdlib.h>

double input[5][5]= {0},map[5][5]= {0};
int point[5][5]= {0};
int cnt[11]= {0};
int ans[11]= {0};
int m,n,dt=0;
int i,j,k;
double sum=0,min=99999999999999,x;

int land(int t)//permutation
{
    int a;
    if(t<=dt)
    {
        for(a=1; a<=dt; a++)
        {
            if(cnt[a]==0)
            {
                cnt[a]=1;
                ans[t]=a;
                land(t+1);
                cnt[a]=0;
            }
        }
    }
    else
    {
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
                map[i][j]=input[i][j];
        for(k=1; k<=dt; k++)
        {
            for(i=1; i<=m; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(point[i][j]==ans[k])
                    {
                        sum+=map[i][j];
                        x=map[i][j]*0.1;
                        map[i+1][j+1]+=x;
                        map[i-1][j-1]+=x;
                        map[i+1][j-1]+=x;
                        map[i-1][j+1]+=x;
                        map[i+1][j]+=x;
                        map[i][j+1]+=x;
                        map[i-1][j]+=x;
                        map[i][j-1]+=x;
                    }
                }
            }
        }
        if(sum<min) min=sum;
        sum=0;
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%lf",&input[i][j]);
            point[i][j]=++dt;
        }
    land(1);
    printf("%.2lf",min);
    return 0;
}
