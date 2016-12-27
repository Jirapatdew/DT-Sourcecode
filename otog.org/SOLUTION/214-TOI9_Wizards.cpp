/*
TASK: wizard.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

struct dt
{
    int x,y;
    int a,b;
};
struct cmpclass
{
    bool operator ()(const dt &a,const dt& b)
    {
        if(a.x!=b.x) return a.x<b.x;
        else return a.y<b.y;
    }
}cmp_obj;

dt da[2250050],tmp;
dt *pt;
int main()
{
    int n;
    int a,b,x[5][2000],y[5][2000],cnt=1;
    scanf("%d%d",&a,&b);
    scanf("%d",&n);

    for(int k=1;k<=4;k++)
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[k][i],&y[k][i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            da[cnt].x=x[1][i]+x[2][j];
            da[cnt].y=y[1][i]+y[2][j];
            da[cnt].a=i;
            da[cnt++].b=j;
        }
    sort(da+1,da+cnt+1,cmp_obj);
    for(int i=n;i>0;i--)
    {
        for(int j=n;j>0;j--)
        {
            tmp.x=a-(x[3][i]+x[4][j]);
            tmp.y=b-(y[3][i]+y[4][j]);
            pt=lower_bound(da+1,da+cnt+1,tmp,cmp_obj);
            if(pt==da+cnt+1||pt->x!=tmp.x||pt->y!=tmp.y) continue;
            printf("%d %d\n",x[1][pt->a],y[1][pt->a]);
            printf("%d %d\n",x[2][pt->b],y[2][pt->b]);
            printf("%d %d\n",x[3][i],y[3][i]);
            printf("%d %d\n",x[4][j],y[4][j]);
            return 0;
        }
    }

    return 0;
}
