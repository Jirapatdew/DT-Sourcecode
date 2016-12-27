#include <stdio.h>
#include <stdlib.h>


int p;
int cmp(const void* a,const void* b)
{
    int i;
    int *aa=(int*)a;
    int *bb=(int*)b;
    for(i=0;i<p;i++)
    if(aa[i]>bb[i]) return 1;
    else if(aa[i]<bb[i]) return -1;
}
int main()
{
    int n,i,j,a[10002][12]={0},x[12];
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)
        for(j=0;j<p;j++) scanf("%d",&a[i][j]);
    for(i=1;i<=p;i++) scanf("%d",&x[i]);
    qsort(a,n+1,sizeof(a[0]),cmp);
    return 0;
}
