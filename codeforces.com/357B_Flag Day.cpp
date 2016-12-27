#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> a[100010];
int b[100010]={0};
//int c[100010][4]={0};
int n,m,sum=0;
int walk(int u,int t)
{
    if(t==4) t=1;
    sum++;
    b[u]=t;
    if(sum==n) {for(int i=1;i<=n;i++) printf("%d ",b[i]);exit(0);}
    int sz=a[u].size();
    for(int j=0;j<sz;j++)
    {
        if(b[a[u][j]]==0) {walk(a[u][j],t+1);}

    }
}
int main()
{
    int x[3];
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++) scanf("%d",&x[j]);
        a[x[0]].push_back(x[1]);
        a[x[0]].push_back(x[2]);

        a[x[1]].push_back(x[0]);
        a[x[1]].push_back(x[2]);

        a[x[2]].push_back(x[0]);
        a[x[2]].push_back(x[1]);
    }
    for(int i=1;i<=n;i++) if(b[i]==0)walk(i,1);

}