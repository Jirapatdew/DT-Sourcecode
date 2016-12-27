#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int cmp(const void*_a,const void*_b)
{
    int *aa=(int*)_a;
    int *bb=(int*)_b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int a[100010][2];
int b[100010]={0},sz=0,*pt;
int main()
{
    int n,T;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
        for(int i=0;i<n;i++) b[i]=0;
        qsort(a,n,sizeof(a[0]),cmp);
        sz=0;
        for(int i=0;i<n;i++)
        {
            pt=upper_bound(b,b+sz,a[i][1]);
            if(pt==b+sz) b[sz++]=a[i][1];
            else b[pt-b]=a[i][1];
        }
        printf("%d\n",sz);

    }
    return 0;
}
