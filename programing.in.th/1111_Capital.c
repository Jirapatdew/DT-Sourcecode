#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long *aa=(long long*)a;
    long long *bb=(long long*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int main()
{
    long long n,i,max=0;
    long long data[100005][3]={0};
    int map[100005]={0};
    scanf("%lld",&n);
    for(i=0;i<n-1;i++) scanf("%lld%lld%lld",&data[i][0],&data[i][1],&data[i][2]);
    qsort(data,n-1,sizeof(data[0]),cmp);
    for(i=0;i<n-1;i++)
    {
        map[data[i][1]]=map[data[i][0]]+data[i][2];
        if(map[data[i][1]]>max) max=map[data[i][1]];
    }
    printf("%lld",max);
    return 0;
}
