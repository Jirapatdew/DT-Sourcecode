#include <stdio.h>
#define MAX(a,b) (a>b)?a:b

using namespace std;

int chk[1010]={0};
int main()
{
    int n,a,mx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        chk[a]++;
        mx=MAX(mx,chk[a]);
    }
    if(n-mx>=mx-1) printf("YES");
    else printf("NO");
    return 0;
}