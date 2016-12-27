#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[500005];
int R[500005]={0};
int chk[500005]={0};
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        R[x]=1;
    }
    chk[1]=1;
    int mx=1;
    for(int i=2;i<=n;i++)
    {
        if(!R[i-1]&&chk[i-1]) {chk[i]=1;mx=i;continue;}
        for(int j=0;j<G[i].size();j++)
        {
            int u=G[i][j];
            if(chk[u]) {chk[i]=1;mx=i;break;}
        }
    }
    if(mx==n) printf("1");
    else printf("0 %d",mx);
    return 0;
}
