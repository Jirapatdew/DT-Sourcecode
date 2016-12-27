#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE 100
#define INF 1000000007

pair<int,pair<int,int>> E[MAX_NODE];
int p[MAX_NODE]={0},n,e;
int findSet(int x){
    if(x==p[x]) return x;
    else return p[x]=findSet(p[x]);
}

int MST(){
    sort(E,E+e);
    for(int i=1;i<=n;i++) p[i]=i;

    int cnt=0;
    for(int i=0; i<e && cnt<n-1; i++){
        int u = E[i].second.first;
        int v = E[i].second.second;
        int p_u = findSet(u);
        int p_v = findSet(v);

        if(p_u==p_v) continue;
        p[p_u]=p_v;
        printf("%d %d\n",u,v);
        cnt++;
    }
}
int main()
{
    int x,y,w;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d%d",&E[i].second.first,&E[i].second.second,&E[i].first);
    }
    MST();
    return 0;
}
/*
9 14
1 2 4
2 3 9
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
3 9 2
9 7 6
3 6 4
4 6 14
*/
