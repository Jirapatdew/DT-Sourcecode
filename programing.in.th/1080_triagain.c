#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,total,x,a,p,max=0;
    int data[505]= {0};
    int temp[505]= {0};
    int q_sum[505]={0};
    scanf("%d",&n);
    for(i=0; i<n; i++){scanf("%d",&a);data[a]++;}

    p=0;//ตัดเลขที่ไม่มี
    for(i=1; i<=500; i++) if(data[i]!=0) temp[++p]=i;

    q_sum[1]=data[temp[1]];
    for(i=2; i<=p; i++) q_sum[i]=data[temp[i]]+q_sum[i-1];

    for(j=p; j>0; j--)
    {
        for(i=1; i<=p; i++)
        {
            total=0;
            if(data[temp[i]]>=2)
            {
                x=temp[i]*2;
                if(x>temp[j]) {total= q_sum[j]-q_sum[i-1];break;}
            }
            x=temp[i]+temp[i+1];
            if(x>temp[j]) {total= q_sum[j]-q_sum[i]+1;break;}
        }
        if(total>max) max=total;
        //printf("%d\n",total);
    }
    if(n==1) printf("1");
    else printf("%d",max);
    return 0;
}
