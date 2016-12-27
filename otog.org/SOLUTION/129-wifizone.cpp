#include <stdio.h>

using namespace std;

int map[1050][1050]={0};
int main()
{
    int n,m,k,q;
    int x,y,a;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d",&x,&y,&a);
        x=x-(a-1)/2;
        y=y-(a-1)/2;
        if(x>=1&&y>=1) map[x][y]++;
        else if(x>=1&&y<1) map[x][1]++;
        else if(y>=1&&x<1) map[1][y]++;
        else map[1][1]++; //bug//
        if(y+a<=m)
        {
            if(x<1) map[1][y+a]--;
            else map[x][y+a]--;
        }
        if(x+a<=n)
        {
            if(y<1) map[x+a][1]--;
            else map[x+a][y]--;
        }
        if(y+a<=m&&x+a<=n) map[x+a][y+a]++;
    }
    //for(int i=1;i<=n;i++)
    //    {for(int j=1;j<=m;j++) printf("%d ",map[i][j]);printf("\n");}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            map[i][j]+=map[i][j-1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            map[i][j]+=map[i-1][j];
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",map[x][y]);
    }
    return 0;
}
