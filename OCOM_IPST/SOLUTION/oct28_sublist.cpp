#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

int main()
{
    int n,mx,a,b=0;
    scanf("%d",&n);
    mx=-(-1u/2);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(i==1) mx=a;
        b+=a;
        if(b<a) b=a;
        mx=MAX(mx,b);
    }
    printf("%d",mx);
    return 0;
}
