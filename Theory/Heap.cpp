#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
//min heap start 0
using namespace std;

int heap[100005]={0},size=0;
int fixup(int u)
{
    if(u==0) return 0;
    int p=(u-1)/2;
    if(heap[u]<heap[p]) {swap(heap[u],heap[p]);fixup(p);}
    else return 0;
}
int fixdown(int u)
{
    if(u>=size) return 0;
    int l=u*2+1,r=u*2+2;
    if(l>=size&&r>=size) return 0;
    else if(l<size&&r<size)
    {
        int mn;
        if(heap[l]<heap[r]&&heap[l]<heap[u])
        {
            swap(heap[u],heap[l]);
            fixdown(l);
        }
        else if(heap[r]<heap[u])
        {
            swap(heap[u],heap[r]);
            fixdown(r);
        }
    }
    else
    {
        if(heap[l]<heap[u])
        {
            swap(heap[u],heap[l]);
            fixdown(l);
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&heap[size++]);
        fixup(size-1);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",heap[0]);
        heap[0]=heap[--size];
        if(size>0)
        {
            fixdown(0);
        }
    }
    return 0;
}
