#include <stdio.h>
#include <stdlib.h>


int pt;
int G[100][100][2]= {0},p[100]= {0},x[100]= {0},hp[100]= {0};
int d[100]= {0},inMST[100]= {0},idx[100];
//G=กราฟ   p=พ่อ  s=สถานะ(  0=สีขาว 1=สีเทา  2=สีดำ )  x=ตัวชี้หยุดบอกข้อมูลหมด
// hp=heap(min)
int prim();
void update(int);
void check(int);
int main()
{
    int i,n,a,b,c,v;
    scanf("%d%d",&v,&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        scanf("%d",&c);
        G[a][x[a]][0]=b;
        G[b][x[b]][0]=a;
        G[a][x[a]][1]=c;
        G[b][x[b]][1]=c;
        x[a]++;x[b]++;
    }
    for(i=0; i<=v; i++) d[i]=2000000000;//ใช้ 1-v
    for(i=0; i<=v; i++) {hp[i]=i+1;idx[i+1]=i;}
    pt=v-1;
    d[1]=0;
    prim();
    for(i=1;i<=v;i++) printf("%d\n",p[i]);
    return 0;
}
void update(int x)
{
    int temp;
    if(d[hp[x]]<d[hp[(x-1)/2]]&&x>=0)
    {
        temp=hp[x];
        hp[x]=hp[(x-1)/2];
        hp[(x-1)/2]=temp;
        idx[hp[x]]=x;
        idx[hp[(x-1)/2]]=(x-1)/2;
        update((x-1)/2);
    }
    else if(x>=0)
    {
        check(x);
    }
}
void check(int x)
{
    int temp;
    if(2*x+2>pt&&2*x+1<=pt)
    {
        if(d[hp[x]]>d[hp[2*x+1]])
        {
            temp=hp[x];
            hp[x]=hp[2*x+1];
            hp[2*x+1]=temp;
            idx[hp[x]]=x;
            idx[hp[2*x+1]]=2*x+1;
            check(2*x+1);
        }
    }
    else if(2*x+2<=pt)
    {
        if(d[hp[2*x+1]]>d[hp[2*x+2]])
        {
            if(d[hp[x]]>d[hp[2*x+1]])
            {
                temp=hp[x];
                hp[x]=hp[2*x+1];
                hp[2*x+1]=temp;
                idx[hp[x]]=x;
                idx[hp[2*x+1]]=2*x+1;
                check(2*x+1);
            }
        }
        else if(d[hp[x]]>d[hp[2*x+2]])
        {
            temp=hp[x];
            hp[x]=hp[x+2];
            hp[x+2]=temp;
            idx[hp[x]]=x;
            idx[hp[2*x+2]]=2*x+2;
            check(2*x+2);
        }
    }
}
int prim()
{
    int u,i;
    while(pt>0)
    {
        u=hp[0];
        hp[0]=hp[pt];
        idx[hp[0]]=0;
        pt--;
        check(0);
        inMST[u]=1;
        for(i=0; i<x[u]; i++)
        {
            if(inMST[G[u][i][0]]==0&&G[u][i][1]<d[u])
            {
                d[u]=G[u][i][1];
                p[G[u][i][0]]=u;
                update(idx[G[u][i][0]]);
            }
        }
    }
}
/*
7 11
1 2 3
1 3 1
2 4 2
2 5 3
3 4 2
3 6 4
4 5 1
4 6 7
5 6 5
5 7 2
6 7 3
*/
