#include <stdio.h>
#include <stdlib.h>

int check_box(int x,int y,int map[10][10])
{
    int i,j;
    int chk[10]={0};
    for(i=x;i<x+3;i++)
    {
        for(j=y;j<y+3;j++)
        {
            if(chk[map[i][j]]==0) chk[map[i][j]]=1;
            else return 0;
        }
    }
    return 1;
}
int check_row(int x,int map[10][10])
{
    int j;
    int chk[10]={0};
    for(j=0;j<9;j++)
    {
        if(chk[map[x][j]]==0) chk[map[x][j]]=1;
        else return 0;
    }
    return 1;
}
int check_column(int y,int map[10][10])
{
    int i;
    int chk[10]={0};
    for(i=0;i<9;i++)
    {
        if(chk[map[i][y]]==0) chk[map[i][y]]=1;
        else return 0;
    }
    return 1;
}
int main()
{
    int n,i,j,k;
    int Truth_value=1;
    int temp[10][10]={0};
    int map[10][10]={0};
    scanf("%d",&n);
    for(i=0;i<9;i++) for(j=0;j<9;j++) scanf("%d",&temp[i][j]);
    for(k=0;k<n;k++)
    {
        Truth_value=1;
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
            {
                scanf("%d",&map[i][j]);
                if(temp[i][j]!=0&&map[i][j]!=temp[i][j]) Truth_value=0;
            }
        if(Truth_value==1)
        {
            for(i=0;i<9;i=i+3)
            {
                for(j=0;j<9;j=j+3)
                {
                    Truth_value=check_box(i,j,map);
                }
            }
            for(i=0;i<9;i++) Truth_value=check_row(i,map);
            for(j=0;j<9;j++) Truth_value=check_column(j,map);
        }
        if(Truth_value==1) printf("%d\n",k+1);
    }
    printf("END");
    return 0;
}
