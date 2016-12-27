#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (a<b)?a:b
using namespace std;
int a[100005]={0},b[100005]={0};
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,mx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
    {
        int c = MIN(a[i],b[n-i-1]);
        if(c>mx) mx=c;
    }
    printf("%d",mx);
    return 0;
}
