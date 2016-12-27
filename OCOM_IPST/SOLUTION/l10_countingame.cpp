#include <stdio.h>
#define Min(_x,_y) ((_x)<(_y))?(_x):(_y)
using namespace std;

int main()
{
    int n,x[6]={0};
    int a[1050]={0};
    scanf("%d",&n);
    a[1]=1;
    for(int i=2;i<=n;i++) a[i]=-1u/2;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<6;j++) x[j]=0;
        for(int j=1;j<=1000;j*=10)
        {
            int b=(i/j)%10;
            if(0<b&&b<=5) x[b]=1;
        }
        for(int j=1;j<=5;j++)
        {
            if(x[j]==0&&i%j!=0&&a[i-j]>0)  a[i]=Min(a[i],a[i-j]+1);
        }
    }
    if(a[n]!=-1u/2) printf("%d",a[n]-1);
    else printf("-1");
    return 0;
}
