#include <stdio.h>
#include <stdlib.h>

int a,b;
char data[110][110]= {'\0'};
int map[110][110]= {0};
int queue[100001][2]={0},p=0,st=0;
void enqueue(int c,int d,int x,int y)
{
    queue[p][0]=c;
    queue[p][1]=d;
    map[c][d]=map[x][y]+1;
    p++;
}
void dequeue()
{
    st++;
}
int is_emp()
{
    if(p==st) return 1;
    else return 0;
}
void print(int c,int d)
{
    printf("%d\n",map[c][d]);
    printf("%d %d",c,d);
}
int main()
{
    int i,j,x,y;
    scanf("%d%d\n",&a,&b);
    for(i=1; i<=a; i++)
        for(j=1; j<=b; j++)scanf(" %c",&data[i][j]);
    enqueue(1,1,1,1);
    while(!is_emp())
    {
        x=queue[st][0];
        y=queue[st][1];
        dequeue();
        if(data[x][y]=='R'||data[x][y]=='B')
        {
            if(y+1<=b)
            {
                if(map[x][y+1]==0) enqueue(x,y+1,x,y);
                else if(map[x][y+1]==map[x][y]+1) {print(x,y+1);break;}
            }
        }
        if(data[x][y]=='D'||data[x][y]=='B')
        {
            if(x+1<=a)
            {
                if(map[x+1][y]==0) enqueue(x+1,y,x,y);
                else if(map[x+1][y]==map[x][y]+1) {print(x+1,y);break;}
            }
        }
        if(x-1>0)
        {
            if(data[x-1][y]=='D'||data[x-1][y]=='B')
            {
                if(map[x-1][y]==0) enqueue(x-1,y,x,y);
                else if(map[x-1][y]==map[x][y]+1) {print(x-1,y);break;}
            }
        }
        if(y-1>0)
        {
            if(data[x][y-1]=='R'||data[x][y-1]=='B')
            {
                if(map[x][y-1]==0) enqueue(x,y-1,x,y);
                else if(map[x][y-1]==map[x][y]+1) {print(x,y-1);break;}
            }
        }
    }
    return 0;
}
