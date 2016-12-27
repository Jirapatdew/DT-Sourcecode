#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
using namespace std;

int main()
{
    long long a,b,n,i,j,sum=0;
    long long chk[4]={0};//N N , N L , L N , L L
    scanf("%lld%lld%lld",&n,&a,&b);

    for(int p=1;p<=n;p++)
    {
        long long x=(p+a-1)/a,y=(p+b-1)/b;
        if(x%2==1||y%2==1) chk[0]++;
        if(x%2==1||y%2==0) chk[1]++;
        if(x%2==0||y%2==1) chk[2]++;
        if(x%2==0||y%2==0) chk[3]++;
    }
    for(int p=1;p<=n;p++)
    {
        long long x=(p+a-1)/a,y=(p+b-1)/b;
        if(x%2==1&&y%2==1) sum+=chk[0];
        if(x%2==1&&y%2==0) sum+=chk[1];
        if(x%2==0&&y%2==1) sum+=chk[2];
        if(x%2==0&&y%2==0) sum+=chk[3];
    }
    printf("%lld",sum);
    return 0;
}
