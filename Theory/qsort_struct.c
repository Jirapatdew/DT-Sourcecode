#include <stdio.h>
#include <stdlib.h>

typedef struct dt
{
    int a;
    int b;
}dt;
//int compare(const void* a,const void* b)
//{
//    dt aa=*(dt*)a;
//    dt bb=*(dt*)b;
//    if(aa.a>bb.a) return 1;
//    else if(aa.a==bb.a&&aa.b>bb.b) return 1;
//    else return -1;
//}
int compare(const void* a,const void* b)
{
    dt *aa=(dt*)a;
    dt *bb=(dt*)b;
    if(aa->a>bb->a) return 1;
    else if(aa->a==bb->a&&aa->b>bb->b) return 1;
    else return -1;
}
int main()
{
    int k,n,m;
    int i;
    dt data[100]={0};
    //scanf("%d%d%d",&k,&n,&m);
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&data[i].a,&data[i].b);
    qsort(data,n,sizeof(dt),compare);
    for(i=0;i<n;i++) printf("\n%d %d",data[i].a,data[i].b);
    return 0;
}

