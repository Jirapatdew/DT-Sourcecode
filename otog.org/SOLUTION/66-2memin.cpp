#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
#define INF 1000000500
using namespace std;

int main()
{
    int n;
    int a[5005]={0},b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b);
        a[b]++;
    }
    for(int i=1;i<=5000;i++) a[i]+=a[i-1];
    int mn=INF;
    for(int i=5000;i>=1;i--)
    {
        if(a[i]-a[i-1]==0) continue;
        mn=MIN((a[5000]-a[i])+a[(i+1)/2-1],mn);
    }
    printf("%d",mn);
    return 0;
}
