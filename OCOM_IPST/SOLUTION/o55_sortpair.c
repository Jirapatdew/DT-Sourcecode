#include <stdio.h>
#include <stdlib.h>

int data[100050][2]={0};

int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&data[i][0],&data[i][1]);
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n;i++) printf("%d %d\n",data[i][0],data[i][1]);
    return 0;
}
