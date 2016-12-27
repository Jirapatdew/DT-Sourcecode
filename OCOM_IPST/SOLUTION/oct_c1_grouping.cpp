#include <stdio.h>
#define MAX(_x,_y) ((_x>_y)?_x:_y)
using namespace std;

int main()
{
    int n,m,mx=0,mem=0;
    int a[10010]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {scanf("%d",&a[i]);mx=MAX(mx,a[i]);}
    int l=mx,r=2000000000;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        int use=1,cap=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]+cap>mid)
            {
                use++;
                cap=a[i];
            }
            else cap+=a[i];
        }
        if(use==m) {l=mid;mem=mid;}
        else if(use>m) l=mid+1;
        else r=mid-1;
    }
    if(mem!=0) printf("%d",mem);
    else printf("IMPOSSIBLE");
    return 0;
}
