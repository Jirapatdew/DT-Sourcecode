#include <stdio.h>

using namespace std;

int main()
{
    int n,k,num=1;
    scanf("%d%d",&n,&k);
    k=n-k;
    if(k==0) printf("-1");
    else
    {
        for(int i=1;i<=k;i++) printf("%d ",i%k+1);
        for(int i=k+1;i<=n;i++) printf("%d ",i);
    }
    return 0;
}