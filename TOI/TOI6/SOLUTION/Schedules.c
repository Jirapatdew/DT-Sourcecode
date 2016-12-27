#include <stdio.h>
#include <stdlib.h>

typedef struct dt
{
    int s;
    int f;
    int t;
} dt;
int compare(const void* a,const void* b)
{
    dt aa=*(dt*)a;
    dt bb=*(dt*)b;
    if(aa.s>bb.s) return 1;
 //   else if(aa.s==bb.s&&aa.f>bb.f) return 1;
    else return -1;
}
int main()
{
    int n,k,m;
    int i,j,p;
    int kl=0;
    char ans[500001]={'\0'};
    dt data[500001]= {0};
    scanf("%d%d%d",&n,&k,&m);
    for(i=0; i<n; i++) scanf("%d%d",&data[i].s,&data[i].f);
    for(i=1; i<=m; i++)
    {
        scanf("%d",&p);
        data[p-1].t=i;
    }
    qsort(data,n,sizeof(dt),compare);

    for(i=0; i<k; i++)
    {
        kl=data[i].f+1;
        data[i].s=0;
        for(j=k-1; j<n; j++)
        {
            if(kl<=data[j].s)
            {
                data[j].s=0;
                kl=data[j].f+1;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(data[i].t!=0)
         if(data[i].s!=0) ans[data[i].t-1]='N';
         else ans[data[i].t-1]='Y';
    }
    for(i=0; i<m; i++) printf("%c ",ans[i]);
    return 0;
}
