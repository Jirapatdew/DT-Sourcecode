#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool DP[1005][1005];
int main()
{
    char x[1005],y[1005],a[2005];
    int n,m,k;

    scanf("%s",x+1);
    scanf("%s",y+1);
    scanf(" %d",&k);

    m = strlen(x+1);
    n = strlen(y+1);
    while(k--){
        scanf("%s",a+1);
        DP[0][0] = true;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i!=0||j!=0) DP[i][j]=false;
                if(a[i+j]==x[i]&&i>0) DP[i][j] |= DP[i-1][j];
                if(a[i+j]==y[j]&&j>0) DP[i][j] |= DP[i][j-1];
            }
        }
        if(DP[m][n]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
