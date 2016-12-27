#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct dt
{
    char str[25];
    int len;
};
struct dt data[100005];
int cmp(const void*a,const void*b)
{
    struct dt *aa=(struct dt*)a;
    struct dt *bb=(struct dt*)b;
    return strcmp(aa->str,bb->str);
}
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",data[i].str);
        data[i].len=strlen(data[i].str);
        for(j=data[i].len; j<=20; j++) data[i].str[j]=data[i].str[j%data[i].len];
        data[i].str[21]='\0';
    }
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0; i<n; i++)
    {
        for(j=0; j<data[i].len; j++) printf("%c",data[i].str[j]);
    }
    return 0;
}
