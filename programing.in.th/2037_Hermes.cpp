#include <stdio.h>
#include <stdlib.h>
#define INF 100000000
using namespace std;

int y[2005]={0},v_x=0;
int x[2005]={0},v_y=0;
int tmp1[2005]={0};
int tmp2[2005]={0};
int ab(int a)
{
    if(a<0) return -a;
    else return a;
}
int MIN(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    int n;
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<=2000;i++) {x[i]=INF;y[i]=INF;}
    v_x=1000;
    v_y=1000;
    x[1000]=0;
    y[1000]=0;
    for(int k=1;k<=n;k++)
    {
        int pl;
        scanf("%d%d",&a,&b);
        a+=1000;
        b+=1000;
        pl=ab(a-v_x);
        for(int i=0;i<=2000;i++) tmp1[i]=INF;
        for(int i=0;i<=2000;i++) if(y[i]!=INF) tmp1[i]=y[i]+pl;
        for(int i=0;i<=2000;i++) if(x[i]!=INF) tmp1[v_y]=MIN(tmp1[v_y],x[i]+ab(a-i));

        pl=ab(b-v_y);
        for(int i=0;i<=2000;i++) tmp2[i]=INF;
        for(int i=0;i<=2000;i++) if(x[i]!=INF) tmp2[i]=x[i]+pl;
        for(int i=0;i<=2000;i++) if(y[i]!=INF) tmp2[v_x]=MIN(tmp2[v_x],y[i]+ab(b-i));

        for(int i=0;i<=2000;i++) x[i]=tmp2[i];
        for(int i=0;i<=2000;i++) y[i]=tmp1[i];

        v_x=a;
        v_y=b;
    }
    int mn=INF;
    for(int i=0;i<=2000;i++)
    {
        mn=MIN(mn,x[i]);
        mn=MIN(mn,y[i]);
    }
    printf("%d",mn);
    return 0;
}
