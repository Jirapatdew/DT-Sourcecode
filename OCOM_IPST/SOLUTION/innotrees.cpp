#include <stdio.h>

using namespace std;

struct dt
{
    int x,y;
};
char Map[110][110]={'\0'};
dt p[110][110];
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",Map[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {p[i][j].x=i;p[i][j].y=j;}
    for(int k=0;k<n-1||k<m-1;k++)
    {
        if(k<n-1)
        {
           for(int i=k+1;i<=n)
            {

            }
        }

    }
    return 0;
}
