#include <stdio.h>
#include <stdlib.h>

char c[100005][100];
int x,tree[200005],emp[200005]={0},l[200005],r[200005],d=0,a=0;

void print(int i,int j,int k)
{
    if(c[i][j]=='*') printf("%d\n",tree[k]);
    else if(c[i][j]=='R') print(i,j+1,r[k]);
    else if(c[i][j]=='L') print(i,j+1,l[k]);
}
void check(int i,int j,int k)
{
    if(c[i][j]=='*') {emp[k]=1;l[k]=++d;r[k]=++d;}
    else if(c[i][j]=='R') check(i,j+1,r[k]);
    else if(c[i][j]=='L') check(i,j+1,l[k]);
}
void binary(int k)
{
    if(emp[k]!=0)
    {
        binary(l[k]);
        tree[k]=++a;
        binary(r[k]);
    }
}
int main()
{
    int i,n,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",c[i]);
        check(i,0,0);
    }
    binary(0);
    for(i=0; i<n; i++)
    {
        print(i,0,0);
    }
    return 0;
}
