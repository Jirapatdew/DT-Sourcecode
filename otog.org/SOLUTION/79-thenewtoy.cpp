#include <stdio.h>
#define INF 2000000500
#define MAX(a,b) (a>b)?a:b
using namespace std;

int main()
{
    int T,n,m;
    bool p;
    int map[115][115]={0};
    int row[115]={0},col[115]={0};
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            row[i]=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&map[i][j]);
                row[i]=MAX(row[i],map[i][j]);
            }
        }
        for(int j=0;j<m;j++)
        {
            col[j]=0;
            for(int i=0;i<n;i++)
                col[j]=MAX(col[j],map[i][j]);
        }
        p=false;
        //printf("Case #%d: ",k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]!=row[i]&&map[i][j]!=col[j])
                {
                    printf("NO\n");
                    p=true;
                    break;
                }
            }
            if(p) break;
        }
        if(!p) printf("YES\n");
    }
    return 0;
}
