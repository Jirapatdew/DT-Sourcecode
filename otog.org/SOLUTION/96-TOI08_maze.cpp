#include <stdio.h>
#include <stdlib.h>
#define INF 200000000
#define MIN(_a,_b) ((_a<_b)?_a:_b)

using namespace std;

int n,m;
int rs,cs;
int re,ce;
int num=0;
int mn=INF;
int data[200][200]={0};
int time[200][200]={0};
int Q[100050][2],be=0,ed=0;
int enqueue(int a,int b)
{
    Q[ed][0]=a;
    Q[ed++][1]=b;
}
void dequeue()
{
    be++;
}
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    scanf("%d%d",&rs,&cs);
    scanf("%d%d",&re,&ce);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&data[i][j]);

    data[rs][cs]=1;
    data[re][ce]=1;
    time[rs][cs]=1;
    time[re][ce]=1;
    enqueue(rs,cs);
    while(be!=ed)
    {
        int x=Q[be][0];
        int y=Q[be][1];
        if(x>m||y>n||x<=0||y<=0) {dequeue();continue;}
        if(data[x][y]==1)
        {
            int t=time[x][y]+1;
            if(time[x][y+1]==0) {enqueue(x,y+1);time[x][y+1]=t;}
            if(time[x+1][y]==0) {enqueue(x+1,y);time[x+1][y]=t;}
            if(time[x][y-1]==0) {enqueue(x,y-1);time[x][y-1]=t;}
            if(time[x-1][y]==0) {enqueue(x-1,y);time[x-1][y]=t;}
        }
        dequeue();
    }
    enqueue(re,ce);
    while(be!=ed)
    {
        int x=Q[be][0];
        int y=Q[be][1];
        if(x>m||y>n||x<0||y<0) {dequeue();continue;}
        if(data[x][y]==1)
        {
            int t=time[x][y]+1;
            if(time[x][y+1]==0&&data[x][y+1]==1) {enqueue(x,y+1);time[x][y+1]=t;}
            else if(time[x][y+1]!=0&&data[x][y+1]==0) {mn=MIN(mn,time[x][y+1]+time[x][y]);num++;data[x][y+1]=2;}

            if(time[x+1][y]==0&&data[x+1][y]==1) {enqueue(x+1,y);time[x+1][y]=t;}
            else if(time[x+1][y]!=0&&data[x+1][y]==0) {mn=MIN(mn,time[x+1][y]+time[x][y]);num++;data[x+1][y]=2;}

            if(time[x][y-1]==0&&data[x][y-1]==1) {enqueue(x,y-1);time[x][y-1]=t;}
            else if(time[x][y-1]!=0&&data[x][y-1]==0) {mn=MIN(mn,time[x][y-1]+time[x][y]);num++;data[x][y-1]=2;}

            if(time[x-1][y]==0&&data[x-1][y]==1) {enqueue(x-1,y);time[x-1][y]=t;}
            else if(time[x-1][y]!=0&&data[x-1][y]==0) {mn=MIN(mn,time[x-1][y]+time[x][y]);num++;data[x-1][y]=2;}
        }
        dequeue();
    }
    printf("%d\n%d",num,mn);
    return 0;
}
