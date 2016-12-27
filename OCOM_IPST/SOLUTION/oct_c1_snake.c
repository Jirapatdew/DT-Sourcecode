#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa<bb) return 1;
    else return -1;
}
int a[200005][4],b[200005];
int main()
{
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        a[i][3]=a[i][2]-(a[i][0]-a[i][1]);
        b[i]=a[i][3];
    }
    m--;
    qsort(b,n,sizeof(b[0]),compare);
    for(i=0;i<k;i++)
    {
        if(b[i]>0) m=m-b[i];
    }
    printf("%d",m);
    return 0;
}
