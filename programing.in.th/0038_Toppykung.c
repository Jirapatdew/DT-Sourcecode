#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    char data[1005][50]={'\0'};
    int i,n;
    scanf("%d\n",&n);
    for(i=0;i<n;i++) scanf("%s",data[i]);
    qsort(data,n,sizeof(data[0]),cmp);
    printf("%s\n",data[0]);
    for(i=1;i<n;i++)
    {
        if(strcmp(data[i-1],data[i])) printf("%s\n",data[i]);
    }

    return 0;
}
