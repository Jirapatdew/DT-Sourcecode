#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100050][15]={'\0'};

int cmp(const void*a,const void*b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    int n,i;
    scanf("%d\n",&n);
    for(i=0;i<n;i++) gets(data[i]);
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n;i++) printf("%s\n",data[i]);
    return 0;
}
