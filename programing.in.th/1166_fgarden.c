#include <stdio.h>
#include <stdlib.h>

int max;
char map[35][35];
int num;
int run(int x,int y)
{
    map[x][y]='2';
    num++;
    if(x>0) if(map[x-1][y]=='.') run(x-1,y);
    if(y>0) if(map[x][y-1]=='.') run(x,y-1);
    if(map[x+1][y]=='.') run(x+1,y);
    if(map[x][y+1]=='.') run(x,y+1);
    return 0;
}
int main()
{
    int n,m,a;
    int i,j;

    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++) scanf("%s",map[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='#')
            {
                if(i>0) if(map[i-1][j]=='.') map[i-1][j]='1';
                if(j>0) if(map[i][j-1]=='.') map[i][j-1]='1';
                if(map[i+1][j]=='.') map[i+1][j]='1';
                if(map[i][j+1]=='.') map[i][j+1]='1';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='.')
            {
                num=0;
                run(i,j);
                if(num>max) max=num;
            }
        }
    }
    printf("%d",max);
    return 0;
}
