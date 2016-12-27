#include <stdio.h>
#define MIN(x,y) (x<y)?x:y
using namespace std;

int main()
{
    int n,t,v;
    int mn=-1u/2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&t,&v);
        mn=MIN(mn,v);
        if(mn==v) printf("0\n");
        else printf("%d\n",v-mn);
    }
    return 0;
}
