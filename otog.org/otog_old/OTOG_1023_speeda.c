#include <stdio.h>
#include <stdlib.h>

double max(double a,double b)
{
    if(a>b) return a;
    else return b;
}
/*int cmp(const void*a,const void*b)
{
    double *aa=(double*)a;
    double *bb=(double*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}*/
//ข้อมูล sort อยู่แล้ว
int main()
{
    int n,i;
    double data[300009]={0},x,y,max_true=0,a;
    scanf("%d",&n);
    for(i=2;i<=n+1;i++)
    {
        scanf("%lf%lf",&x,&y);
        data[i]=((y*3)-x)/2;
    }
    //data[0][0]=0;data[0][1]=0;data[1][0]=0;data[1][1]=0;
    //qsort(data,n+2,sizeof(data[0]),cmp);
    for(i=2;i<=n+1;i++)
    {
        a=max(data[i-1],data[i-2]);
        data[i]+=a;
        if(data[i]<0) data[i]=0;
        if(data[i]>max_true) max_true=data[i];
    }
    printf("%.2lf",max_true);
    return 0;
}
