#include "device.h"
#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

int a[100010]={0};
int l,r,n;
int partition(int left, int right)
{
    int u;
    u=(rand()%(right-left+1))+left;
    int p = a[u];
    swap(a[left],a[u]);
    int i = left, j = right + 1;
    while(i < j)
    {
        while(1)
        {
            --j;
            if(j == left) break;
            u=Med3(p,r,a[j]);
            if(u!=a[j]) break;
        }
        while(1)
        {
            ++i;
            if(i == right) break;
            u=Med3(p,l,a[i]);
            if(u!=a[i]) break;
        }
        if (i < j) swap(a[i],a[j]);
    }
    swap(a[left],a[j]);
    return j;
}
int quickSelect(int left,int right,int k)
{
    if(left == right) return a[left];
    int j=partition(left, right);
    int m=j-left+1;
    if(k == m) return a[j];
    if(k < m) return quickSelect(left,j-1,k);
    else return quickSelect(j+1,right,k-m);

}
int main()
{
    int x;
    n=GetN();
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n-2;i++)
    {
        x=Med3(a[n-1],a[n],a[i]);
        if(x==a[n-1]) swap(a[n-1],a[i]);
        else if(x==a[n]) swap(a[n],a[i]);
    }
    l=a[n-1];
    r=a[n];
    n-=2;
    Answer(quickSelect(1,n,(n+1)/2));
    return 0;
}
