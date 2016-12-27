#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int a[1010],p=0,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[0]=a[2];
    a[n+1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        int x,y;
        x=a[i];
        y=a[i+1];
        if(x>y) swap(x,y);
        for(int j=1;j<=n;j++)
        {
            if(x<a[j]&&a[j]<y&&(a[j+1]<x||a[j+1]>y||a[j-1]<x||a[j-1]>y))
                {p=1;break;}
        }
        if(p==1) break;
    }
    if(p==1) printf("yes");
    else printf("no");
    return 0;
}