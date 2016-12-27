#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

int mp[300][300]={};
int minn[2]={INF,INF};
int idx = -1;

struct data
{
    int d[2];
    int nxt;
}ins;

vector<data> nd[50000];

bool chk[50000]={};

void wlk(int x,int y,int k)
{
    int sz = nd[k].size();
    if(minn[0] > x)
    {
        minn[0] = x;
        minn[1] = y;
        idx = k;
    }
    else if(minn[0] == x)
    {
        if(minn[1] > y)
        {
            minn[1] = y;
            idx = k;
        }
    }
    for(int i = 0; i < sz; i++)
    {
        if(!chk[nd[k][i].nxt])
        {
            chk[nd[k][i].nxt]=1;
            wlk(x+nd[k][i].d[0],y+nd[k][i].d[1],nd[k][i].nxt);
        }
    }
}


void crt(int x,int y,int k)
{
    mp[x][y]=k;
    int sz = nd[k].size();
    for(int i = 0; i < sz; i++)
    {
        if(chk[nd[k][i].nxt])
        {
            chk[nd[k][i].nxt]=0;
            crt(x+nd[k][i].d[0],y+nd[k][i].d[1],nd[k][i].nxt);
        }
    }
}

int main()
{
    int n,m,lp;
    int x,z;
    char y;
    scanf("%d%d",&m,&n);
    lp = m*n-1;
    while(lp--)
    {
        scanf(" %d %c %d",&x,&y,&z);
        if(y=='U')
        {
            ins.nxt = z;
            ins.d[0] = 1;
            ins.d[1] = 0;
            nd[x].push_back(ins);
            ins.nxt = x;
            ins.d[0] = -1;
            ins.d[1] = 0;
            nd[z].push_back(ins);
        }
        else if(y=='L')
        {
            ins.nxt = z;
            ins.d[0] = 0;
            ins.d[1] = 1;
            nd[x].push_back(ins);
            ins.nxt = x;
            ins.d[0] = 0;
            ins.d[1] = -1;
            nd[z].push_back(ins);
        }
    }
    chk[0]=1;
    wlk(1,1,0);
    chk[idx]=0;
    crt(1,1,idx);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
