#include <stdio.h>
#include <stdlib.h>

struct stock
{
    int p;
    int q;
    double d;
};
int compare(const void* a,const void* b)
{
    struct stock aa=*(struct stock*)a;
    struct stock bb=*(struct stock*)b;
    if(aa.d>bb.d) return 1;
    else return -1;
}
int main()
{
    int k,m,i,pt=0,b=0;
    double sum;
    struct stock stock[100005]={0};
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&stock[i].p,&stock[i].q);
        stock[i].d=(double)stock[i].p/stock[i].q;
    }
    qsort(stock,k,sizeof(struct stock),compare);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&b);
        sum=0;
        while(b>0)
        {
            if(b<stock[pt].q)
            {
                stock[pt].q-=b;
                sum+=b*stock[pt].d;
                b=0;
            }
            else if(b>=stock[pt].q)
            {
                sum+=stock[pt].q*stock[pt].d;
                b-=stock[pt].q;
                stock[pt].q=0;
                pt++;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
