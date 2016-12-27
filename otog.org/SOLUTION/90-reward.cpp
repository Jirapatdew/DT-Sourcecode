#include <stdio.h>

using namespace std;

int a[500050]={0};
int n,b,ans=0;
int chk(int x)
{
    int num=0;
    for(int i=1;i<=n;i++) num+=(a[i]+x-1)/x;
    return num;
}
int main()
{
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int lo=1,hi=5000000;
    while(lo<hi)
    {
        int mid=(lo+hi)/2,num;
        num=chk(mid);
        if(num>b) lo=mid+1;
        else hi=mid;
    }
    printf("%d",lo);
    return 0;
}
