#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_NODE 100

vector<int> G[MAX_NODE];
int chk[MAX_NODE]={0},n,e;
stack<int> S; // ans

// return true = DAG , false = Not DAG
bool Topological_Sort(int u){
    chk[u] = 1;
    for(auto &v : G[u]){
        if(chk[v]==0){
            if(!Topological_Sort(v)) return false;
        }
        else if(chk[v]==1) return false;
    }
    S.push(u);
    chk[u] = 2;
    return true;
}
bool Topological_Sort(){
    for(int i=1;i<=n;i++) chk[i]=0;
    for(int i=1;i<=n;i++)
        if(chk[i]==0)
            if(!Topological_Sort(i)) return false;
    return true;
}

int main()
{
    int x,y;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    if(Topological_Sort()) {
        while(!S.empty()){
            printf("%d\n",S.top());
            S.pop();
        }
    }
    else printf("Not DAG\n");

    return 0;
}
/*
False
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

True
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
