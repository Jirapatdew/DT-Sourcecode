#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200010]={0};
int main()
{
    int n;
    scanf("%d",&n);
    n*=2;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d",a[n/2-1]);
    return 0;
}
