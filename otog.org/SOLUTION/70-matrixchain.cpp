#include <stdio.h>
#define INF 2000000050
using namespace std;

int data[15][3]={0};
int f[15][15]={0};
int p[15][15]={0};

int print(int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
        return 0;
    }
    printf("(");
    print(i,p[i][j]);
    printf(" x ");
    print(p[i][j]+1,j);
    printf(")");
    return 0;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&data[i][0],&data[i][1]);
    for(int j=1;j<=n;j++)
    {
        for(int i=j;i>=0;i--)
        {
            int min=INF;
            for(int k=i;k<j;k++)
            {
                x=f[i][k]+f[k+1][j]+(data[i][0]*data[k+1][0]*data[j][1]);
                if(x<min) {min=x;p[i][j]=k;}
            }
            if(i!=j) f[i][j]=min;
        }
    }
    printf("%d\n",f[1][n]);
    print(1,n);
    return 0;
}
