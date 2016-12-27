#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,m,k;
int chk[15]={0};
int ans[15]={0};
int x[15]={0};
int y[15]={0};
int p[15]={0};
int min;
int to_end(int t,int xx,int yy)
{
    int b;
    b=sqrtl((n-xx-1)*(n-xx-1)+(m-yy-1)*(m-yy-1));
    if((n-xx-1)*(n-xx-1)+(m-yy-1)*(m-yy-1)!=b*b) b++;
    return t+b;
}
int per(int a,int t)
{
    int i,b,tmp;
    if(a<=k)
    {
        for(i=1;i<=k;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                ans[a]=i;
                b=sqrtl((x[i]-x[ans[a-1]])*(x[i]-x[ans[a-1]])+(y[i]-y[ans[a-1]])*(y[i]-y[ans[a-1]]));
                if((x[i]-x[ans[a-1]])*(x[i]-x[ans[a-1]])+(y[i]-y[ans[a-1]])*(y[i]-y[ans[a-1]])!=b*b) b++;
                b=b+t-p[i];
                tmp=to_end(b,x[i],y[i]);
                if(min>tmp) min=tmp;
                per(a+1,b);
                chk[i]=0;
            }
        }
    }
    else return 0;
}

int main()
{
    int i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++) scanf("%d%d%d",&x[i],&y[i],&p[i]);
    min=to_end(0,0,0);
    per(1,0);
    printf("%d",min);
    return 0;
}
