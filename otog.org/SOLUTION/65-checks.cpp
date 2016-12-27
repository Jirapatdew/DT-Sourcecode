#include <stdio.h>
#define MAX(a,b) (a>b)?a:b;
using namespace std;

int main()
{
    int n,T,k,s,mx=-1;
    int a[30005]={0};
    scanf("%d",&T);
    while(--T>=0)
    {
        scanf("%d%d",&s,&n);
        mx=-1;
        for(int i=1;i<=s;i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
            a[i]=MAX(a[i],a[i-1]+a[i]);
            if(a[i]>mx) mx=a[i];
        }
        if(mx<=n) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
