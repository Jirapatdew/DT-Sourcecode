#include <stdio.h>
#include <math.h>
#define MIN(_x,_y) ((_x)<(_y))?(_x):(_y);

using namespace std;
int t[15][5]={0};
int ans[15]={0};
int chk[15]={0};
int time=0;
int n,m,k;
int to_end(int a,int x,int y)
{
    int b=(n-1-x)*(n-1-x)+(m-1-y)*(m-1-y);
    b=sqrtl(b);
    if(b*b!=(n-1-x)*(n-1-x)+(m-1-y)*(m-1-y)) b++;
    return a+b;
}
int per(int x,int a)
{
    int tmp,b;
    if(x<=k)
    {
        for(int i=1;i<=k;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                ans[x]=i;
                b=sqrtl((t[i][0]-t[ans[x-1]][0])*(t[i][0]-t[ans[x-1]][0])+(t[i][1]-t[ans[x-1]][1])*(t[i][1]-t[ans[x-1]][1]));
                if(b*b!=(t[i][0]-t[ans[x-1]][0])*(t[i][0]-t[ans[x-1]][0])+(t[i][1]-t[ans[x-1]][1])*(t[i][1]-t[ans[x-1]][1])) b++;
                b+=a-t[i][2];
                tmp=to_end(b,t[i][0],t[i][1]);
                time=MIN(time,tmp);
                per(x+1,b);
                chk[i]=0;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        for(int j=0;j<3;j++) scanf("%d",&t[i][j]);
    time=to_end(0,0,0);
    per(1,0);
    printf("%d",time);
    return 0;
}
