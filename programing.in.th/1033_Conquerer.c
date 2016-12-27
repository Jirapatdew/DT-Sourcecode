#include <stdio.h>
#include <stdlib.h>

int map[105][105]={0};
int x[5]={0};
int y[5]={0};
int sc[5]={0},n,end=4;
void N(int a)//a = คนที่
{
    if(x[a]-1>=0&&map[x[a]-1][y[a]]!=-1)
    {
        if(map[x[a]-1][y[a]]!=0) sc[map[x[a]-1][y[a]]]--;
        else end++;
        map[x[a]][y[a]]=a;
        map[x[a]-1][y[a]]=-1;
        sc[a]++;
        x[a]-=1;
    }
}
void E(int a)
{
    if(y[a]+1<n&&map[x[a]][y[a]+1]!=-1)
    {
        if(map[x[a]][y[a]+1]!=0) sc[map[x[a]][y[a]+1]]--;
        else end++;
        map[x[a]][y[a]]=a;
        map[x[a]][y[a]+1]=-1;
        sc[a]++;
        y[a]+=1;
    }
}
void S(int a)
{
    if(x[a]+1<n&&map[x[a]+1][y[a]]!=-1)
    {
        if(map[x[a]+1][y[a]]!=0) sc[map[x[a]+1][y[a]]]--;
        else end++;
        map[x[a]][y[a]]=a;
        map[x[a]+1][y[a]]=-1;
        sc[a]++;
        x[a]+=1;
    }
}
void W(int a)
{
    if(y[a]-1>=0&&map[x[a]][y[a]-1]!=-1)
    {
        if(map[x[a]][y[a]-1]!=0) sc[map[x[a]][y[a]-1]]--;
        else end++;
        map[x[a]][y[a]]=a;
        map[x[a]][y[a]-1]=-1;
        sc[a]++;;
        y[a]-=1;
    }
}
int main()
{
    int k,t,i,j,max=0,num=0;
    char com[5][1005]={'\0'};
    char di;
    scanf("%d%d",&n,&k);
    y[1]=n-1;
    x[2]=n-1;
    y[2]=n-1;
    x[3]=n-1;
    for(i=1;i<=4;i++) {map[x[i]][y[i]]=-1;sc[i]=1;}
    for(i=1;i<=4;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%c",&com[i][j]);
            if(com[i][j]=='\n') scanf("%c",&com[i][j]);
        }
    }
    for(j=0;j<k;j++)
    {
        for(i=1;i<=4;i++)
        {
            if(com[i][j]=='N') N(i);
            else if(com[i][j]=='E') E(i);
            else if(com[i][j]=='S') S(i);
            else if(com[i][j]=='W') W(i);
        }
    }
    if(end!=n*n) printf("No");
    else
    {
        for(i=1;i<=4;i++) if(sc[i]>max) max=sc[i];
        for(i=1;i<=4;i++) if(sc[i]==max) num++;
        printf("%d %d\n",num,max);
        for(i=1;i<=4;i++) if(sc[i]==max) printf("%d\n",i);
    }
    return 0;
}
