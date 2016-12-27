/*
TASK: mountain
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,r,s,sc,h,hc,max=0,maxh=0;
    char map[11][100]= {'\0'};
    scanf("%d",&n);
    for(r=0; r<n; r++)
    {
        scanf("%d%d",&s,&h);
        if(s+(h*2)-1>max) max=s+(h*2)-1;
        if(h>maxh) maxh=h;
        sc=s+1;
        hc=s+(h*2)-2;
        for(i=10; i>(10-h)-1; i--)
        {
            for(j=sc; j<=hc; j++)
            {
                map[i][j]='X';
            }
            sc++;
            hc--;
        }
        if(map[10-h+1][h+s-1]=='\0'&&map[10-h+1][h+s-2]!='X') map[10-h+1][h+s-1]='/';
        else map[10-h+1][h+s-1]='v';
        if(map[10-h+1][h+s]=='\0'&&map[10-h+1][h+s+1]!='X') map[10-h+1][h+s]='\\';
        else map[10-h+1][h+s]='v';
    }
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=max; j++)
        {
            if(map[i][j]=='\0'&&map[i][j+1]=='X') map[i][j]='/';
            else if(map[i][j]=='X'&&map[i][j+1]=='\0') map[i][j+1]='\\';
            else if(map[i][j]=='\\'&&map[i][j+1]=='X') map[i][j]='v';
            else if(map[i][j]=='\0') map[i][j]='.';
        }
    }
    for(i=10-maxh+1; i<=10; i++)
        {for(j=1; j<=max; j++) {printf("%c",map[i][j]);}printf("\n");}

return 0;
}
