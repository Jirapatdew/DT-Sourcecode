#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[40][40]={0};
int n,num=0;
int way(int x,int y)
{
    int i;
    if(x<1||y<1||x>n||y>n||data[x][y]!='.') return 0;
    else if(data[x][y]=='.')
    {
        data[x][y]='X';
        if(data[x-1][y]=='#') num++;
        else if(data[x-1][y]=='.') way(x-1,y);
        if(data[x][y-1]=='#') num++;
        else if(data[x][y-1]=='.') way(x,y-1);
        if(data[x+1][y]=='#') num++;
        else if(data[x+1][y]=='.') way(x+1,y);
        if(data[x][y+1]=='#') num++;
        else if(data[x][y+1]=='.') way(x,y+1);
    }
}
int main()
{
    int i,j;
    char tmp[40]={0};
    scanf("%d\n",&n);
    for(i=0;i<=n+1;i++) data[0][i]='#';
    for(i=1;i<=n;i++)
    {
        strcpy(data[i],"#");
        gets(tmp);
        strcat(data[i],tmp);
        data[i][n+1]='#';
    }
    for(i=0;i<=n+1;i++) data[n+1][i]='#';
    data[1][0]='.';data[0][1]='.';
    data[n+1][n]='.';data[n][n+1]='.';
    way(1,1);
    printf("%d",num*9);
    return 0;
}
