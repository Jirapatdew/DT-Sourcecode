#include <stdio.h>
#include <algorithm>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;

int b[100010]={0};
int main()
{
    int n,sz=0,a;
    int *pt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pt=lower_bound(b,b+sz,a);
        if(pt==b+sz) b[sz++]=a;
        else b[pt-b]=a;
    }
    printf("%d\n",sz);
    return 0;
}
