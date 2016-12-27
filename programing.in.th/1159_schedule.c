#include <stdio.h>
#include <stdlib.h>

int val[2][1005]={0};
int data[1005][1005][2]={0};
int m;
int edit(int i,int j,int v)
{
    if(v==0)
    {
        data[i][j][0]=data[i-1][j][0];
        if(val[v][i]+data[i-1][j][1]>m)
        {
            data[i][j][0]++;
            data[i][j][1]=val[v][i];
        }
        else
        {
            data[i][j][1]=val[v][i]+data[i-1][j][1];
        }
    }
    else
    {
        data[i][j][0]=data[i][j-1][0];
        if(val[v][j]+data[i][j-1][1]>m)
        {
            data[i][j][0]++;
            data[i][j][1]=val[v][j];
        }
        else
        {
            data[i][j][1]=val[v][j]+data[i][j-1][1];
        }
    }
}
int main()
{
    int n;
    int i,j;
    int a[2],b[2];
    int min[2];
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=0;i<2;i++)
    {
        for(j=1;j<=n;j++) scanf("%d",&val[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        edit(i,0,0);
        edit(0,i,1);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

                edit(i,j,0);
                min[0]=data[i][j][0];
                min[1]=data[i][j][1];
                edit(i,j,1);
                if(data[i][j][0]>min[0]||(data[i][j][0]==min[0]&&data[i][j][1]>min[1]))
                {data[i][j][0]=min[0];data[i][j][1]=min[1];}


        }
    }
    printf("%d\n%d",data[n][n][0]+1,data[n][n][1]);
    return 0;
}
