#include <stdio.h>
#define Mod 1000000007
using namespace std;
//dynamic programming
//f(n)=f(n-1)+(f(n-1)-f(p(n-1)))+2     ans=f(n+1)
int main()
{
    int n,a[1005]={0},p[1005]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=2;i<=n+1;i++) a[i]=(a[i-1]+(a[i-1]-a[p[i-1]]+Mod)%Mod+2)%Mod;
    printf("%d",a[n+1]);
    return 0;
}
