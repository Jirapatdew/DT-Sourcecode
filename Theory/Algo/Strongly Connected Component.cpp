#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_NODE 100

vector<int> G[MAX_NODE];
vector<int> GT[MAX_NODE];
stack<int> S;
int chk[MAX_NODE]={0},n,e;
int num_SCC=0;

int DFS_GT(int u){
    chk[u] = 1;
    for(auto &v : GT[u])
        if(chk[v]==0) DFS_GT(v);
    S.push(u);
}
int DFS_GT(){
    for(int i=1;i<=n;i++) chk[i]=0;
    for(int i=1;i<=n;i++)
        if(chk[i]==0) DFS_GT(i);
}

int DFS_G(int u){
    chk[u] = num_SCC;
    printf("%d\n",u);
    for(auto &v : G[u])
        if(chk[v]==0) DFS_G(v);
}

int SCC(){
    DFS_GT(); // Build S
    for(int i=1;i<=n;i++) chk[i]=0;
    while(!S.empty()){
        int s = S.top();
         S.pop();
         if(chk[s]==0) {
            num_SCC++;
            printf("SCC no.%d\n",num_SCC);
            DFS_G(s);
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
        GT[y].push_back(x);
    }
    SCC();

    return 0;
}
/*
9 12
1 2
1 3
1 4
2 5
6 2
3 4
4 7
5 8
7 9
7 3
8 6
9 6
------------------
7 9
1 2
2 3
3 1
1 4
4 5
5 6
6 5
6 7
7 4

*/
