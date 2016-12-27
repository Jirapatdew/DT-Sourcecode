#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[100050]={0};
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,Q,v;
    int *pt;
    scanf("%d%d",&n,&Q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&v);
        pt=lower_bound(a,a+n,v);
        if(pt==a+n) printf("%d\n",n);
        else printf("%d\n",pt-a);
    }
    return 0;
}
