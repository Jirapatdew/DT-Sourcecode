#include <stdio.h>
#include <stdlib.h>
#define INF 2000000000
char map[100][100]={0};
int chk[100][100]={0};
int queue[10000][2],be=0,end=0;
int ans[30]={0};
void enqueue(int a,int b)//a=x,b=y
{
    queue[end][0]=a;
    queue[end++][1]=b;
}
void dequeue()
{
    be++;
}
int Q_empty()
{
    if(be==end) return 1;
    else return 0;
}
int main()
{
    int i,j;
    int n,m;
    int x,y,min=INF,cnt=0;;
    for(i=0;i<26;i++) ans[i]=INF;
    scanf("%d%d",&n,&m);
    scanf("%d%d\n",&x,&y);//x=col y=row
    for(i=0;i<m;i++) gets(map[i]);
    enqueue(x,y);

    while(!Q_empty())
    {
        x=queue[be][0];
        y=queue[be][1];//x,y error
        if('A'<=map[y][x]&&map[y][x]<='Z') ans[map[y][x]-'A']=chk[y][x];
        else
        {
            if(map[y][x+1]!='1'&&chk[y][x+1]==0) {enqueue(x+1,y);chk[y][x+1]=chk[y][x]+1;}
            if(map[y][x-1]!='1'&&chk[y][x-1]==0) {enqueue(x-1,y);chk[y][x-1]=chk[y][x]+1;}
            if(map[y+1][x]!='1'&&chk[y+1][x]==0) {enqueue(x,y+1);chk[y+1][x]=chk[y][x]+1;}
            if(map[y-1][x]!='1'&&chk[y-1][x]==0) {enqueue(x,y-1);chk[y-1][x]=chk[y][x]+1;}
        }
        dequeue();
        //for(i=0;i<m;i++) {for(j=0;j<n;j++) printf("%d ",chk[i][j]); printf("\n");}
        //printf("\n");
        //cnt++;
    }
    //find min
    for(i=0;i<26;i++) if(ans[i]<min) min=ans[i];
    for(i=0;i<26;i++) if(ans[i]==min) printf("%c\n",'A'+i);
    return 0;
}
