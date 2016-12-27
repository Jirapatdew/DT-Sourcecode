#include <stdio.h>
using namespace std;
int up[1005][1005];
int down[1005][1005];
int left[1005][1005];
int right[1005][1005];
int map[1005][1005];
int main()
{
    int T,r,c,x,y,mx;
    scanf("%d",&T);
    for(int k=0;k<T;k++)
    {
        mx=1;x=1;y=1;
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++) scanf("%d",&map[i][j]);
        for(int i=1;i<=r;i++)
        {
            map[i][0]=left[i][0]=0;
            for(int j=1;j<=c;j++)
            {
                if(map[i][j]>=map[i][j-1]) left[i][j]=left[i][j-1]+1;
                else left[i][j]=1;
            }
            map[i][c+1]=right[i][c+1]=0;
            for(int j=c;j>=1;j--)
            {
                if(map[i][j]>=map[i][j+1]) right[i][j]=right[i][j+1]+1;
                else right[i][j]=1;
            }
        }
        for(int j=1;j<=c;j++)
        {
            map[0][j]=up[0][j]=0;
            for(int i=1;i<=r;i++)
            {
                if(map[i][j]>=map[i-1][j]) up[i][j]=up[i-1][j]+1;
                else up[i][j]=1;
            }
            map[r+1][j]=down[r+1][j]=0;
            for(int i=r;i>=1;i--)
            {
                if(map[i][j]>=map[i+1][j]) down[i][j]=down[i+1][j]+1;
                else down[i][j]=1;
            }
        }
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                int a=up[i][j]+down[i][j]+left[i][j]+right[i][j]-3;
                if(mx<a)
                {
                    mx=a;
                    x=i;y=j;
                }
            }
        printf("%d\n",mx);
        printf("%d %d\n",x,y);
    }
    return 0;
}
