#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE 100

vector<int> G[MAX_NODE];
queue<int> Q;
int chk[MAX_NODE]={0},n,e;

int bfs(int s){
    Q.push(s);
    chk[s]=1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        printf("%d\n",u); //print
        for(auto &v : G[u]){
            if(chk[v]==0){
                Q.push(v);
                chk[v]=1;
            }
        }
    }

}

int main()
{
    int x,y;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    for(int i=1;i<=n;i++) chk[i]=0;
    for(int i=1;i<=n;i++)
        if(chk[i]==0) bfs(i);

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
*/
