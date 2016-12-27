#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,sum=0;
    int a[200000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int i=0,j=n-1;
    while(j-i>=4)
    {
        a[j-1]=0;
        j-=2;
        i+=3;
    }
    for(int i=0;i<n;i++) sum+=a[i];
    printf("%d",sum);
    return 0;
}
