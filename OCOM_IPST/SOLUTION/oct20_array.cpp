#include <stdio.h>
#include <algorithm>
#define INF (-1u/2)
#define MIN(_x,_y) ((_x<_y)?_x:_y)
#define MAX(_x,_y) ((_x>_y)?_x:_y)
using namespace std;

int in[100010][4];
int be[500010]={0},en[500010]={0};//1...sz
int ST[200010]={0},sz=0;
int T[1000010]={0};//1...X
int create(int node,int l,int r)
{
    T[node]=INF;
    if(l>=r) return 0;
    int m=(l+r)/2;
    create(node*2,l,m);
    create(node*2+1,m+1,r);
}
int insert(int node,int l,int r,int x,int y,int v)
{
    if(y<be[l]||x>en[r]) return 0;
    if(x<=be[l]&&en[r]<=y) {T[node]=v;return 0;}
    int m=(l+r)/2;
    if(T[node]!=INF)///***///
    {
        int tmp=T[node];
        T[node]=INF;
        if(be[l]<x&&x<=en[r]) insert(node,l,r,be[l],x-1,tmp);
        if(be[l]<=y&&y<en[r]) insert(node,l,r,y+1,en[r],tmp);
    }
    insert(node*2,l,m,x,y,v);
    insert(node*2+1,m+1,r,x,y,v);
}
long long query(int node,int l,int r,int x,int y)
{
    long long sum=0;
    if(y<be[l]||x>en[r]) return 0;
    if(x<=be[l]&&en[r]<=y&&T[node]!=INF) return (en[r]-be[l]+1)*(long long)T[node];
    int m=(l+r)/2;
    if(T[node]!=INF) return (MIN(en[r],y)-MAX(be[l],x)+1)*(long long)T[node];///**///
    sum+=query(node*2,l,m,x,y);
    sum+=query(node*2+1,m+1,r,x,y);
    return sum;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&in[i][0]);
        if(in[i][0]==0)
        {
            scanf("%d%d%d",&in[i][1],&in[i][2],&in[i][3]);
            ST[sz++]=in[i][1];
            ST[sz++]=--in[i][2];
        }
        else {scanf("%d%d",&in[i][1],&in[i][2]);--in[i][2];}
    }
    sort(ST,ST+sz);//0...sz-1
    int num=0;
    for(int i=1;i<sz;i++)
    {
        if(ST[i]!=ST[num]) ST[++num]=ST[i];
    }//0...num
    sz=1;
    be[1]=en[1]=ST[0];
    for(int i=1;i<=num;i++)
    {
        if(ST[i]-en[sz]>1)
        {
            sz++;
            be[sz]=en[sz-1]+1;
            en[sz]=ST[i]-1;
        }
        sz++;
        be[sz]=en[sz]=ST[i];
    }//1...sz
    create(1,1,sz);
    T[1]=0;
    for(int i=1;i<=q;i++)
    {
        if(in[i][0]==0)
        {
            insert(1,1,sz,in[i][1],in[i][2],in[i][3]);
        }
        else printf("%lld\n",query(1,1,sz,in[i][1],in[i][2]));
    }
    return 0;

}
