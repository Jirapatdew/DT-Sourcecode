#include <stdio.h>
#include <stdlib.h>

using namespace std;
int vitem[1005],witem[1005];
int data[1005][1005]={0};
int main()
{
    int n,W;
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++) scanf("%d%d",&witem[i],&vitem[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(i==0||j==0) data[i][j]=0;
            else if(witem[i]>j) data[i][j]=data[i-1][j];
            else if(data[i-1][j]>vitem[i]+data[i-1][j-witem[i]])
                    data[i][j]=data[i-1][j];
            else data[i][j]=vitem[i]+data[i-1][j-witem[i]];
        }
    }
    printf("%d",data[n][W]);
    return 0;
}
