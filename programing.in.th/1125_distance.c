#include <stdio.h>
#include <stdlib.h>

int px=1,py=1;
long long x[500001]={0};
long long y[500001]={0};
long long ab(long long n)
{
    if(n>0) return n;
    else return n*-1;
}
void add_x(int z,int n)
{
    while(n>0)
    {x[px++]=(long long)z;n--;}
}
void add_y(int z,int n)
{
    while(n>0)
    {y[py++]=(long long)z;n--;}
}
int main()
{
    int chk_x[1000001]={0};
    int chk_y[1000001]={0};
    int n,i,a,b;
    long long total=0,c1,c2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        chk_x[a]++;chk_y[b]++;
    }
    for(i=1;i<=1000000;i++)
    {
        if(chk_x[i]>0) add_x(i,chk_x[i]);
        if(chk_y[i]>0) add_y(i,chk_y[i]);
    }
    for(i=2;i<=n;i++)
    {
        x[i]+=x[i-1];
        y[i]+=y[i-1];
    }
    for(i=1;i<=n;i++)
    {
        c1=(x[i]-x[i-1])*(n-i);
        c2=x[n]-x[i];
        total+=ab(c1-c2);
        c1=(y[i]-y[i-1])*(n-i);
        c2=y[n]-y[i];
        total+=ab(c1-c2);
    }
    printf("%lld",total);
    return 0;
}
