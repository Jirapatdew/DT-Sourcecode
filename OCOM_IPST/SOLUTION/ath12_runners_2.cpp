#include <stdio.h>
#include <stdlib.h>
using namespace std;
int cmp(const void*a,const void*b)
{
    double *aa=(double*)a;
    double *bb=(double*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]<bb[1]) return 1;
    else return -1;
}
int main()
{
    int n,m,t,T;
    double a[10020][3]={0},v,x;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%d",&v,&t);
            x=m*1000/v;
            a[i][0]=x+t;
            a[i][1]=t;
            a[i][2]=i;
        }
        qsort(a+1,n,sizeof(a[0]),cmp);
        for(int i=1;i<=n;i++) printf("%.0lf\n",a[i][2]);
        T--;
    }
    return 0;
}
