#include <stdio.h>
#include <stdlib.h>

double chk[1100000];
int pow(int a,int b)
{
    int i,total=1;
    for(i=0;i<b;i++) total*=a;
    return total;
}
int one(int a,int n)
{
    int j,idx=1,total=0;
    for(j=n;j>0;j--)
    {
        if((a&idx)>0) total++;
        idx<<=1;
    }
    return total;
}
int main()
{
    int n,i,j,idx,m,b;
    double a;
    double data[25][25]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) {scanf("%lf",&data[i][j]);data[i][j]/=100;}
    idx=1;
    m=pow(2,n)-1;
    for(i=0;i<=m;i++) chk[i]=-1;
    for(j=n;j>0;j--)//set start
    {
        chk[idx]=data[1][j];
        idx<<=1;
    }
    for(i=1;i<=m;i++)
    {
        if(chk[i]==-1)
        {
            b=one(i,n);
            idx=1;
            for(j=n;j>0;j--)
            {
                if((i&idx)>0)//if have some bit is same
                {
                    a=chk[i^idx]*data[b][j];
                    if(chk[i]<a) chk[i]=a;
                }
                idx<<=1;//a <<= b  mean  a = a << b
            }
        }
    }
    printf("%.6lf",chk[m]*100);
    return 0;
}
