#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int a[10000]={0};
int Part(int left,int right)
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
int q_sort(int left,int right)
{
    if (left>=right) return 0;
    int j = Part(left,right);
    q_sort(left,j-1);
    q_sort(j+1,right);
}
int main()
{
    int n;
    srand(time(NULL));//change seed
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    q_sort(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
