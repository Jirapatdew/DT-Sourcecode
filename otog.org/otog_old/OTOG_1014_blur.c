#include <stdio.h>
#include <stdlib.h>

int h,w,m;
int map[205][205]={0};
int chk(int a,int b)
{
    int tmp=m/2,n,total;
    int x[5]={0},y[5]={0};
    x[0]=(a+tmp<=h)?a+tmp:h;
    y[0]=(b+tmp<=w)?b+tmp:w;
    x[1]=(a-tmp-1>0)?a-tmp-1:0;
    y[1]=(b-tmp-1>0)?b-tmp-1:0;
    x[2]=x[0];
    y[2]=y[1];
    x[3]=x[1];
    y[3]=y[0];
    n=(y[0]-y[2])*(x[0]-x[3]);
    total=map[x[0]][y[0]]+map[x[1]][y[1]]-map[x[2]][y[2]]-map[x[3]][y[3]];
    return total/n;

}
int main()
{
    int i,j;

    int ans[205][205]={0};
    scanf("%d%d",&h,&w);
    scanf("%d",&m);
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            scanf("%d",&map[i][j]);
            map[i][j]+=map[i][j-1];//qsum right
        }
    }
    for(j=1;j<=w;j++)
        for(i=1;i<=h;i++) map[i][j]+=map[i-1][j];
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            ans[i][j]=chk(i,j);
        }
    }
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
