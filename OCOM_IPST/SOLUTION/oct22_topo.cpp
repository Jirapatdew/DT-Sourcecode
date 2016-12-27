#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> G[100005];
int visit[100005]={0};
int d[100005]={0};
int f[100005][2]={0},time=1;
bool DAG = true;

int tsort(int u)
{
    int s=G[u].size();
    int i,v;
    if(!DAG) return 0;
    visit[u]=1;
    d[u]=time++;
    for(i=0;i<s;i++)
    {
        v=G[u][i];
        if(visit[v]==0) tsort(v);
        if(visit[v]==1) DAG = false;
    }
    f[u][0]=time++;
    visit[u]=2;
}
int cmp(const void*a,const void *b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m;
    int a,b;
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
    }

    for(i=1;i<=n;i++) {f[i][1]=i;}
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0) tsort(i);
    }
    if(!DAG) printf("no\n");
    else
    {
        qsort(f+1,n,sizeof(f[0]),cmp);
        for(i=1;i<=n;i++) printf("%d\n",f[i][1]);
    }
    return 0;
}
