#include <stdio.h>
#include <set>
#define MAX(a,b) (a>b)?a:b
using namespace std;

int map[1005][1005];
int chk[1005][1005]={0};
struct p
{
    int x,y;
    bool operator < (const p &T) const
    {
        if(chk[x][y] != chk[T.x][T.y]) return chk[x][y] < chk[T.x][T.y];
        else if(x != T.x) return x < T.x;
        else return y < T.y;
    }
    p(int a,int b)
    {
        x = a;
        y = b;
    }
};
set<p> Q;
set<p>::iterator pt;

int main()
{
    int n,cnt=0,pass=0;
    int st[2][2],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    scanf("%d",&n);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++) map[i][j]=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]==0) {st[cnt][0]=i;st[cnt][1]=j;cnt++;}
            }
    Q.insert(p(st[0][0],st[0][1]));
    while(!Q.empty())
    {
        pt=Q.begin();
        int a=pt->x,b=pt->y;
        if(map[a][b]>0||pass==0)
        {
            pass=1;
            for(int j=0;j<4;j++)
            {
                int c=chk[a+dir[j][0]][b+dir[j][1]];
                int d=MAX(chk[a][b],map[a+dir[j][0]][b+dir[j][1]]);
                if(c==0||c>d)
                {
                    chk[a+dir[j][0]][b+dir[j][1]]=d;
                    Q.insert(p(a+dir[j][0],b+dir[j][1]));
                }
                if(a+dir[j][0]==st[1][0]&&b+dir[j][1]==st[1][1])
                {printf("%d",chk[st[1][0]][st[1][1]]);return 0;}
            }
        }
        Q.erase(pt);
    }
    printf("%d",chk[st[1][0]][st[1][1]]);
    return 0;
}
