#include <stdio.h>

using namespace std;

int a[100005]={0};
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while(m--){
        scanf("%d",&x);
        int lo=0,hi=n,mid;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(x>a[mid]) lo=mid+1;
            else hi=mid;
        }
        printf("%d\n",lo);
    }
    return 0;
}
