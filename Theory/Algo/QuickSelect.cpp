#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int a[10000]={0};
int part(int left,int right)
{
    int RD = rand()%(right-left)+left;//select pivot
    swap(a[left],a[RD]);
    int p = a[left];
    int i=left,j=right+1;
    while(i<j)
    {
        while(a[--j]>p);
        while(a[++i]<p) if(i==right) break;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[left],a[j]);
    return j;
}
int quickSelect(int left,int right,int k)
{
    if (left==right) return a[left];
    int j = part(left,right);
    int m = j-left+1;
    if(k==m) return a[j];
    if(k<m) return quickSelect(left,j-1,k);
    else return quickSelect(j+1,right,k-m);
}
int main()
{
    int n,k;
    srand(time(NULL));//change seed
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d",quickSelect(0,n-1,k));
    return 0;
}
