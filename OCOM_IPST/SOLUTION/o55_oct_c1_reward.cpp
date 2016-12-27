#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
#define MIN(_x,_y) ((_x)<(_y))?(_x):(_y)
using namespace std;

int a[500010]={0};
int n,m;
int mn=-1u/2;
int bi(int left,int right)
{
    int mid=(left+right)/2,k=0;
    if(left>right) return 0;
    for(int i=1;i<=n;i++)
    {
        k+=(a[i]+mid-1)/mid;
    }
    if(k<=m) {mn=MIN(mn,mid);bi(left,mid-1);}
    else bi(mid+1,right);


}
int main()
{
    int mx=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);mx=MAX(mx,a[i]);}
    bi(1,mx);
    printf("%d",mn);
    return 0;
}
