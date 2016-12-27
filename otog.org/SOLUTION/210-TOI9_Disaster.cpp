/*
TASK: disaster.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int ans[5000]={0};
int G[50][50]={0};
int n,chk[50]={0};
//int chk[50][50]={0};
void walk(int u,int num)
{
    if(num>n)
    {
        for(int i=0;i<=n;i++) printf("%c ",ans[i]+'A');
        exit(0);
    }
    for(int i=0;i<26;i++)
    {
        if(G[u][i]!=1) continue;
        G[u][i]=2;
        G[i][u]=2;
        ans[num]=i;
        walk(i,num+1);
        G[u][i]=1;
        G[i][u]=1;
    }

}
int main()
{
    char a[5];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        G[a[0]-'A'][a[1]-'A']=1;
        G[a[1]-'A'][a[0]-'A']=1;
        chk[a[0]-'A']++;
        chk[a[1]-'A']++;
    }
    for(int i=0;i<26;i++)
    {
        ans[0]=i;
        if(chk[i]%2==1) walk(i,1);
    }
    for(int i=0;i<26;i++)
    {
        ans[0]=i;
        if(chk[i]%2==0) walk(i,1);
    }
    return 0;
}
