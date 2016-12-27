#include <stdio.h>
#include <stdlib.h>
int dfs(int [][100],int ,int *,int *,int *);
int main()
{
    int G[100][100]={0},p[100]={0},s[100]={0},x[100]={0};
    //G=กราฟ   p=พ่อ  s=สถานะ(  0=สีขาว 1=สีเทา  2=สีดำ )  x=ตัวชี้หยุดบอกข้อมูลหมด
    int i,n,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&G[a][x[a]]);
        x[a]++;
    }
    for(i=1;i<100;i++)
    {
        if(x[i]!=0)
        {
            if(s[i]==0) dfs(G,i,s,p,x);
        }
    }
    return 0;
}
int dfs(int G[][100],int u,int *s,int *p,int *x)//u=ตัวเริ่ม
{
    int i;
    s[u]=1;
    for(i=0;i<x[u];i++)
    {
        if(s[G[u][i]]==0)
        {
            p[G[u][i]]=u;
            dfs(G,G[u][i],s,p,x);
        }
    }
    s[u]=2;
}
/*
11
1 2
1 3
1 4
2 5
2 6
3 4
4 7
5 8
7 9
8 6
9 6
*/
