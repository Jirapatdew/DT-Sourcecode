#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void *b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int main()
{
    int n,i,p=0,sum=0,max=0;
    int data[30005][2]={0};
    int dt[60005][2]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&data[i][0],&data[i][1]);
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n-1;i++)
    {
        if(data[i][1]>data[i+1][1])//ตัวน้อยเป็นบวกตัวมากเป็นลบ
        {
            dt[p][0]=data[i+1][1];
            dt[p][1]=1;
            p++;
            dt[p][0]=data[i][1]+1;
            dt[p][1]=-1;
            p++;
        }
        else
        {
            dt[p][0]=data[i][1];
            dt[p][1]=1;
            p++;
            dt[p][0]=data[i+1][1]+1;
            dt[p][1]=-1;
            p++;
        }
    }
    qsort(dt,p,sizeof(dt[0]),cmp);
    for(i=0;i<p;i++)
    {
        sum+=dt[i][1];
        if(sum>max) max=sum;
    }
    printf("%d",max);
    return 0;
}
