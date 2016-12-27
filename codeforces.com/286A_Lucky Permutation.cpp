#include <stdio.h>

using namespace std;
int ans[100050]={0};
int main()
{
    int n,t;
    scanf("%d",&n);
    if(n%4>1) {printf("-1");return 0;}
    t=n/2;
    if(n&1) ans[t+1]=t+1;
    for(int i=1;i<=t;i+=2)
    {
        int p=i,u=i+1;
        ans[i]=i+1;
        while(ans[u]==0)
        {
            ans[u]=n-p+1;
            p=u;
            u=ans[u];
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}