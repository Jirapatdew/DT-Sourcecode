#include <stdio.h>
#include <stdlib.h>

int n,m;
int rs,cs;
int re,ce;
int num=0;
int min=200000000;
int data[200][200]={0};
int time[200][200]={0};

int walk_st(int x,int y,int t)
{
    if(x>m||y>n||x<0||y<0) return 0;

    if(data[x][y]==1&&t<time[x][y])
    {
        time[x][y]=t;
        walk_st(x,y+1,t+1);
        walk_st(x+1,y,t+1);
        walk_st(x,y-1,t+1);
        walk_st(x-1,y,t+1);
    }
    else if(data[x][y]!=1)
    {
        data[x][y]=2;
        if(t<time[x][y]) time[x][y]=t;
    }
}

int walk_ed(int x,int y,int t)
{
    if(x>m||y>n||x<0||y<0) return 0;

    if(data[x][y]==1&&t<time[x][y])
    {
        time[x][y]=t;
        walk_ed(x,y+1,t+1);
        walk_ed(x+1,y,t+1);
        walk_ed(x,y-1,t+1);
        walk_ed(x-1,y,t+1);
    }
    else if(data[x][y]>1)
    {
        if(data[x][y]==2){data[x][y]=3;num++;}//เช็คว่ามีกี่กำแพงที่ระเบิดแล้วไปถึง
        if(t+time[x][y]<min)
        {
            min=t+time[x][y];
        }
    }
}

int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    scanf("%d%d",&rs,&cs);
    scanf("%d%d",&re,&ce);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&data[i][j]);
            time[i][j]=200000000;
        }
    }
    data[rs][cs]=1;//***********
    data[re][ce]=1;//***********
    walk_st(rs,cs,0);
    walk_ed(re,ce,1);
    printf("%d\n%d",num,min);
    return 0;
}

//1160_maze<8.in>8.txt
/*
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) printf("%d ",data[i][j]);
        printf("\n");
    }
*/
