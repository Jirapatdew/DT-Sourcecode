#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 2000000000
using namespace std;

int a[1000050]={0};
int main()
{
    int n,k,p;
    int mx=0;
    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;i++) {scanf("%d",&a[i]);mx=MAX(mx,a[i]);}
    int lo=0,hi=mx,num;
    long long total=p*(long long)k;
    if(n<=total)
    {
        int x,y;
        int mn=INF;
        for(int i=1;i<=n;i++)
        {
            x=(i-1+p-1)/p;
            y=(i+1+p-1)/p;
            if(x+y<=k) mn=MIN(mn,a[i-1]);
        }
        printf("%d",mn);
        return 0;
    }
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        num=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid) {num++;i+=p-1;}
        }
        if(num>k) lo=mid+1;
        else hi=mid;
    }
    printf("%d",lo);
    return 0;
}
