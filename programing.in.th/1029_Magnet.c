#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m,q,M,k;
    int i,j;
    int data[200005][2]={0};
    int ans[100005]={0},pa,pd,sum,del_sum[200005][2]={0},com[200005]={0};
    int question[100005][2]={0},pq;
    scanf("%d%d%d",&n,&m,&q);
    M=m*2;
    for(i=0;i<M;i+=2)
    {
        scanf("%d%d",&data[i][0],&k);
        data[i][1]=1;
        data[i+1][0]=data[i][0]+k;
        data[i+1][1]=-1;
    }
    data[M][0]=1;
    data[M][1]=0;
    data[M+1][0]=n+1;
    data[M+1][1]=0;
    qsort(data,M+2,sizeof(data[0]),cmp);
    for(i=0;i<q;i++)
    {
        scanf("%d",&question[i][0]);
        question[i][1]=i;
    }
    qsort(question,q,sizeof(question[0]),cmp);

    pd=0;
    sum=0;
    for(i=0;i<M+2;i++)//ตัดตัวซ้ำ
    {
        sum+=data[i][1];
        for(j=i+1;j<M+2;j++)
        {
            if(data[i][0]==data[j][0]) sum+=data[j][1];
            else break;
        }
        del_sum[pd][0]=data[i][0];
        del_sum[pd][1]=sum%2;
        pd++;
        i=j-1;
    }

    pa=0;
    for(i=0;i<pd;i++) //รวมตัวเท่า
    {
        sum=del_sum[i][1];
        for(j=i+1;j<pd;j++)
        {
            if(del_sum[i][1]!=del_sum[j][1]) break;
        }
        com[pa]=del_sum[i][0];
        pa++;
        i=j-1;
    }
    if(com[pa-1]!=n+1) {com[pa]=n+1;pa++;}
    pq=0;
    for(i=0;i<pa-1&&pq<q;)
    {
        if(com[i]<=question[pq][0]&&question[pq][0]<com[i+1])
        {
            ans[question[pq][1]]=com[i+1]-com[i];
            pq++;
        }
        else i++;
    }
    for(i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}
