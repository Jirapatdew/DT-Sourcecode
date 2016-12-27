#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE 100
#define INF 1000000007

pair<int,pair<int,int>> E[MAX_NODE];
int d[MAX_NODE]={0},p[MAX_NODE]={0},n,e;


bool BellmanFord(int s){

    for(int i=1;i<=n;i++) d[i]=INF;
    d[s]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<e;j++){
            int u = E[j].second.first;
            int v = E[j].second.second;
            int w = E[j].first;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                p[v]=u;
            }
        }
    }
    // Check Negative-weight cycles
    for(int j=0;j<e;j++){
        int u = E[j].second.first;
        int v = E[j].second.second;
        int w = E[j].first;
        if(d[u]+w<d[v]) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d%d",&E[i].second.first,&E[i].second.second,&E[i].first);
    }
    if(!BellmanFord(1)) printf("Negative-weight cycles\n");
    else for(int i=1;i<=n;i++) printf("%d\n",d[i]);
    return 0;
}
/*
Testcase from somchaiSPJ
7 12
1 2 8
1 3 5
2 5 18
3 2 10
3 4 3
3 6 16
4 2 2
4 5 12
4 7 14
5 7 4
6 4 30
6 7 26
---------------------
Negative-weight cycles
5 5
1 2 2
2 3 2
3 4 4
3 5 -1
5 2 -2
*/
