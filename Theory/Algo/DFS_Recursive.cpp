#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODE 100

vector<int> G[MAX_NODE];
int chk[MAX_NODE]={0},n,e;

int DFS(int u){
    chk[u] = 1;
    printf("%d\n",u);
    for(auto &v : G[u])
        if(chk[v]==0) DFS(v);
}
int DFS(){
    for(int i=1;i<=n;i++) chk[i]=0;
    for(int i=1;i<=n;i++)
        if(chk[i]==0) DFS(i);
}

int main()
{
    int x,y;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    DFS();

    return 0;
}
/*
9 12
1 2
1 3
1 4
2 5
2 6
3 4
4 7
5 8
7 9
7 3
8 6
9 6
-------------
9 11
1 2
1 3
2 4
2 5
3 5
4 8
8 5
6 1
6 7
7 9
9 3
*/
