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
    int i,data1[2001]={0},data2[2001]={0},n,sum=0,x;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&data1[i]);
    for(i=0;i<n;i++) scanf("%d",&data2[i]);
    qsort(data1,n,sizeof(int),compare);
    qsort(data2,n,sizeof(int),compare);
    for(i=0;i<n;i++)
    {
        x=data1[i]-data2[i];
        if(x<0) x=x*-1;
        sum+=x;
    }
    printf("%d",sum);
    return 0;
}
