#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void *b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,i,total=0,half,sum=0,a,p;
    int data[300005][2]={0};
    int result[300005]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i][0]);
        data[i][1]=i;
        total+=data[i][0];
    }
    qsort(data,n+1,sizeof(data[0]),cmp);
    half=total/2;
    for(i=n;i>0;i--)
    {
        sum+=data[i][0];
        if(sum>half)
        {
            sum-=data[i][0];
            a=n-i;
            p=i+1;
            break;
        }
    }
    for(i=n;i>0;i--)
    {
        if(i>=p) result[data[i][1]]=a;
        else
        {
            if(data[i][0]+sum>half) result[data[i][1]]=a;
            else result[data[i][1]]=a+1;
        }
    }
    for(i=1;i<=n;i++) printf("%d\n",result[i]);
    return 0;
}
