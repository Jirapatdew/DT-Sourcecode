#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int i,data[100]={0},n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&data[i]);
    qsort(data,n,sizeof(int),compare);
    for(i=0;i<n;i++) printf("%d ",data[i]);
    return 0;
}
