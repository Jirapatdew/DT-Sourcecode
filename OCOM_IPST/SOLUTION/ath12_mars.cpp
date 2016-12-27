#include <stdio.h>
#include <string.h>
#define ab(_x) (((_x)>0)?(_x):(-(_x)))
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

int dm[2][26][26]={0};//can use 2D
int main()
{
    int T;
    char a[1010];
    scanf("%d\n",&T);
    while(T>0)
    {
        scanf("%s",a);
        int n=strlen(a);
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) dm[0][i][j]=dm[1][i][j]=-1u/2;
        dm[0][0][0]=0;
        for(int k=0;k<n;k++)
        {
            int u=k%2,v=(k+1)%2,x,y;
            int c=a[k]-'A',abs;
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dm[u][i][j]!=-1u/2)
                    {
                        abs=ab(j-c);
                        dm[v][i][c]=MIN(dm[v][i][c],dm[u][i][j]+MIN(abs,26-abs));
                        abs=ab(i-c);
                        dm[v][c][j]=MIN(dm[v][c][j],dm[u][i][j]+MIN(abs,26-abs));
                        dm[u][i][j]=-1u/2;
                    }
                }
            }
        }
        int v=n%2,mn=-1u/2;
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) mn=MIN(mn,dm[v][i][j]);
        printf("%d\n",mn);
        T--;
    }
    return 0;
}
