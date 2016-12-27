#include <stdio.h>
#include <string.h>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define INF (-1u/2)
using namespace std;

char ch[30];
int op[30][30]={0};
int dm[300][300][30]={0};
int idx[30]={0};
char oc[30][30];
char a[300];
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++) {scanf(" %c",&ch[i]);idx[ch[i]-'a']=i;}
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d-%c",&op[i][j],&oc[i][j]);
        scanf("%d",&m);
        for(int _k=0;_k<m;_k++)
        {
            scanf("%s",a);
            int len=strlen(a);
            for(int i=0;i<len;i++)
                for(int j=0;j<len;j++)
                    for(int k=0;k<n;k++) dm[i][j][k]=INF;
            for(int l=0;l<len;l++)
            {
                for(int i=0,j=l;j<len;j++,i++)
                {
                    if(i==j) {dm[i][j][idx[a[i]-'a']]=0;}
                    for(int k=i;k<j;k++)
                    {
                        for(int x=0;x<n;x++)
                        {
                            if(dm[i][k][x]==INF) continue;
                            for(int y=0;y<n;y++)
                            {
                                if(dm[k+1][j][y]==INF) continue;
                                int res=idx[oc[x][y]-'a'];
                                dm[i][j][res]=MIN(dm[i][j][res],dm[i][k][x]+dm[k+1][j][y]+op[x][y]);
                            }
                        }
                    }
                }
            }
            int mn=0;
            for(int i=1;i<n;i++)
                if(dm[0][len-1][i]<dm[0][len-1][mn]) mn=i;
            printf("%d-%c\n",dm[0][len-1][mn],ch[mn]);
        }
        printf("\n");
    }
    return 0;
}
