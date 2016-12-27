#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 1000005
int main()
{
    int n,i,idx,t=0,a;
    int *tmp,tm;
    long long total=0;
    int *data;
    int *maxx,sum_m=0,pm=0;
    int *minn,sum_n=0,pn=0;
    tmp=(int*)malloc(sizeof(int)*M);
    data=(int*)malloc(sizeof(int)*M);
    maxx=(int*)malloc(sizeof(int)*M);
    minn=(int*)malloc(sizeof(int)*M);
    scanf("%d",&n);
    tm=n;
    for(i=0;i<n;i++) {scanf("%d",&data[i]);tmp[i]=data[i];}
    while(1)
    {
        pm=0;
        pn=0;
        t=0;
        idx=rand()%n;
        for(i=0;i<n;i++)
        {
            if(data[i]>data[idx]) maxx[pm++]=data[i];
            else if(data[i]<data[idx]) minn[pn++]=data[i];
            else t++;
        }
        if(t>=abs((pm+sum_m)-(pn+sum_n))) break;
        if(pm+sum_m>pn+sum_n)
        {
            for(i=0;i<pm;i++) data[i]=maxx[i];
            n=pm;
            sum_n+=pn+t;
        }
        else
        {
            for(i=0;i<pn;i++) data[i]=minn[i];
            n=pn;
            sum_m+=pm+t;
        }
    }
    for(i=0;i<tm;i++)
    {
        if(tmp[i]>data[idx]) total+=tmp[i];
        else if(tmp[i]<data[idx]) total-=tmp[i];
    }
    if(pm+sum_m<pn+sum_n) total+=data[idx]*abs((pm+sum_m)-(pn+sum_n));
    if(pm+sum_m>pn+sum_n) total-=data[idx]*abs((pm+sum_m)-(pn+sum_n));
    printf("%lld",total);
    return 0;
}
