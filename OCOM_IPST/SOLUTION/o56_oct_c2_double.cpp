#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int a[100010]={0};
int main()
{
    int n,total;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    total=a[n];
    if(total%2==1) {printf("NO");return 0;}
    total/=2;
    int *pt;
    for(int i=1;i<=n;i++)
    {
        int key=a[i-1]+total;
        pt=lower_bound(a+i,a+n+1,key);
        if(pt==a+n+1) continue;
        if(*pt==key)
        {
            if(i==1) printf("%d",pt-a);
            else printf("%d %d",i-1,pt-a);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
