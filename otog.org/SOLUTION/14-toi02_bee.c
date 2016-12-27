#include <stdio.h>
#include <stdlib.h>
void bee(int [],int);
int main()
{
    int x[26],i;
    for(i=1;i<=25;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]==-1) break;
    }
    bee(x,i-1);
    return 0;
}
void bee(int data[],int n)//x[i][0]=นางพญา, x[i][1]=ผึ้งงาน ,x[i][2]=ผึ้งทหาร
{
    int x[25][3]={{1,1,0}},i;
    for(i=1;i<=24;i++)
    {
        x[i][0]=1;
        x[i][1]=x[i-1][0]+x[i-1][1]+x[i-1][2];
        x[i][2]=x[i-1][1];
    }
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",x[data[i]][1],x[data[i]][0]+x[data[i]][1]+x[data[i]][2]);
    }
}
