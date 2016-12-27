#include <stdio.h>

using namespace std;

int op[30][30]={0};
int a[200]={0};
int dm[110][110][110]={0};
int main()
{
    int K,n;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
        for(int j=0;j<K;j++) scanf("%d",&op[i][j]);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int l=0;l<n;l++)
    {
        for(int j=l,i=0;j<n&&i<n;j++,i++)
        {
            if(i==j) {dm[i][i][a[i]]=1;continue;}
            for(int k=i;k<j;k++)
            {
                //dm[i][k][_i] dm[k+1][j][_j]
                for(int _i=0;_i<K;_i++)
                {
                    for(int _j=0;_j<K;_j++)
                    {
                        dm[i][j][op[_i][_j]]+=(dm[i][k][_i]*dm[k+1][j][_j])%2009;
                        dm[i][j][op[_i][_j]]%=2009;
                    }
                }
            }
        }
    }
    for(int i=0;i<K;i++) printf("%d\n",dm[0][n-1][i]);
    return 0;
}
