#include <stdio.h>
#define INF 2000000500
using namespace std;

char map[10][10];
int ans[20]={0},mn=INF;

int choose(int a)
{
    int dir[5][2]={{0,0},{1,0},{0,1},{0,-1},{-1,0}},num=0;
    for(int i=0;i<5;i++)
    {
        int x=(a+3)/4+dir[i][0];
        int y=(a%4==0)?4+dir[i][1]:(a%4)+dir[i][1];
        if(map[x][y]=='b') {map[x][y]='w';num--;}
        else if(map[x][y]=='w') {map[x][y]='b';num++;}
    }
    return num;
}
int bi(int a,int black,int one)
{
    if(a<=16)
    {
        ans[a]=0;
        bi(a+1,black,one);
        ans[a]=1;
        bi(a+1,black+choose(a),one+1);
        choose(a);
    }
    else
    {
        if(black==16||black==0)
            if(one<mn) mn=one;
    }
    return 0;
}
int main()
{
    int i,j,num=0;
    for(i=1;i<=4;i++) gets(&map[i][1]);
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++) if(map[i][j]=='b') num++;
    bi(1,num,0);
    if(mn==INF) printf("Impossible");
    else printf("%d",mn);

    return 0;
}
