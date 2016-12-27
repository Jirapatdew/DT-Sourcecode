#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_NODE 100

vector<int> G[MAX_NODE];
stack<int> S;
int chk[MAX_NODE]={0},n,e;
int cnt[MAX_NODE]={0};

int dfs(int s){
    S.push(s);
    chk[s]=1;
    printf("%d\n",s); //print
    while(!S.empty()){
        int u = S.top(),v=0;

        //choose v is member in adj(u) AND v never been in stack
        while(cnt[u]<G[u].size()){
            v = G[u][cnt[u]];
            cnt[u]++;
            if(chk[v]==0) break;
            else v = 0;
        }

        if(v==0){  // v does not exist
            S.pop();
        }
        else {
            S.push(v);
            chk[v]=1;
            printf("%d\n",v); //print
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
    for(int i=1;i<=n;i++) chk[i]=cnt[i]=0;
    for(int i=1;i<=n;i++)
        if(chk[i]==0) dfs(i);

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
