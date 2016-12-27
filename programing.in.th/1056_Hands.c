#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n,k,i,total=0;
    int data[2005]={0};
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&data[i]);
    qsort(data,n,sizeof(int),cmp);
    for(i=n-1;i>=0;i-=k) total+=data[i];
    printf("%d",total);
    return 0;
}
