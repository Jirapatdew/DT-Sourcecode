#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
using namespace std;

int tree[110][5]={0};
int w[110][110]={0},cnt[110]={0};
int f[110][110]={0};
int k;
int travel(int u,int p)
{
    if(cnt[u]==1) return 0;
    int ch[2],a=0;
    for(int i=0;i<cnt[u];i++)
    {
        if(tree[u][i]==p) continue;
        ch[a]=tree[u][i];
        travel(ch[a],u);
        a++;
    }
    for(int i=1;i<=k;i++)
    {
        f[u][i]=MAX(f[u][i],f[ch[0]][i-1]+w[u][ch[0]]);
        f[u][i]=MAX(f[u][i],f[ch[1]][i-1]+w[u][ch[1]]);
        for(int j=0;j<=i-2;j++)
        {
            f[u][i]=MAX(f[u][i],f[ch[0]][j]+f[ch[1]][i-j-2]+w[u][ch[0]]+w[u][ch[1]]);
        }
    }
    return 0;
}
int main()
{
    int n;
    int a,b,c;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        tree[a][cnt[a]++]=b;
        tree[b][cnt[b]++]=a;
        w[a][b]=c;
        w[b][a]=c;
    }
    travel(1,0);
    printf("%d",f[1][k]);
    return 0;
}
