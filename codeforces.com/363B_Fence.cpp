#include <stdio.h>
#include <algorithm>
#define INF (-1u/2)
using namespace std;
int a[200010]={0};
int main()
{
    int n,k,x;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i]+=a[i-1];}
    int mn=INF,id=1;
    for(int i=k;i<=n;i++)
    {
        x=a[i]-a[i-k];
        if(x<mn)
        {
            mn=x;
            id=i-k+1;
        }
    }
    printf("%d",id);
    return 0;
}