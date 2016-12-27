#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

int a[5010]={0};
int main()
{
    int n,h,l,x;
    int mx=0;
    scanf("%d%d%d",&h,&l,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=l;i<=l+h;i++) mx=MAX(mx,a[i]);
    printf("%d",mx);
    return 0;
}
