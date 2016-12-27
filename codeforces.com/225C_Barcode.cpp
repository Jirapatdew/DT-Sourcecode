#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
#define INF 20000500
using namespace std;
char input[1005];
int f[1005][2]={0};
int w[1005]={0};
int b[1005]={0};
int main()
{
    int n,m,x,y;
    scanf("%d%d%d%d\n",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)
    {
        gets(&input[1]);
        for(int j=1;j<=m;j++)
            if(input[j]=='#') b[j]++;
            else w[j]++;
    }
    for(int j=1;j<=m;j++) {w[j]+=w[j-1];b[j]+=b[j-1];}
    for(int i=1;i<=m;i++) {f[i][0]=INF;f[i][1]=INF;}
    for(int i=x;i<=m;i++)
    {
        for(int j=x;j<=y&&j<=i;j++)
            if(f[i-j][1]!=INF) f[i][0]=MIN(f[i][0],f[i-j][1]+(w[i]-w[i-j]));
        for(int j=x;j<=y&&j<=i;j++)
            if(f[i-j][0]!=INF) f[i][1]=MIN(f[i][1],f[i-j][0]+(b[i]-b[i-j]));
    }
    printf("%d",MIN(f[m][0],f[m][1]));
    return 0;
}