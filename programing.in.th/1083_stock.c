#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,q,a,b,dt,pt;
    int data[1000005]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    scanf("%d",&q);
    dt=data[1];
    data[1]=0;
    for(j=1;j<n;j++)
    {
        pt=data[j+1];
        if(dt>=pt) {data[j+1]=data[j];}
        else data[j+1]=pt-dt+data[j];
        dt=pt;
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",data[b]-data[a]);
    }
    return 0;
}

/*int main()//ถูกเหมือนกันแต่เกินเวลา
{
    int n,i,j,q,a,b;
    int data[1000005]={0};
    int qsum[1000005]={0};
    scanf("%d",&n);
    scanf("%d",&data[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&data[i]);
        if(data[i-1]>=data[i]) qsum[i]=qsum[i-1];
        else qsum[i]=data[i]-data[i-1]+qsum[i-1];
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",qsum[b]-qsum[a]);
    }
    return 0;
}*/
