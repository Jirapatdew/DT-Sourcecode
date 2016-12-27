/*
TASK: fence.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

int map[550][550];
int main()
{
    int n,m,a,b,l,sum;

    for(int t=0;t<2;t++)
    {
        scanf("%d%d",&n,&m);

        for(int i=0;i<=n+1;i++)
          for(int j=0;j<=m+1;j++)  map[i][j]=0;

        scanf("%d",&l);
        for(int i=0;i<l;i++) {scanf("%d%d",&a,&b);map[a+1][b+1]=1;}

        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++) map[i][j]+=map[i][j-1];
        for(int j=1;j<=m;j++)
            for(int i=1;i<=n;i++) map[i][j]+=map[i-1][j];

        int x=MIN(n,m);
        for(int k=x;k>=1;k--)
        {
            for(int i=k;i<=n;i++)
            {
                for(int j=k;j<=m;j++)
                {
                    sum=map[i][j]+map[i-k][j-k]-map[i][j-k]-map[i-k][j];
                    if(k>=3) sum-=map[i-1][j-1]+map[i-k+1][j-k+1]-map[i-1][j-k+1]-map[i-k+1][j-1];
                    if(sum==0)
                    {
                        printf("%d\n",k);
                        break;
                    }
                }
                if(sum==0) break;
            }
            if(sum==0) break;
        }
    }
    return 0;
}
