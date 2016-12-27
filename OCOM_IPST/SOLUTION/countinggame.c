#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    int data[1005]= {0},chk[10]={0},k;
    int n,i,j;
    scanf("%d",&n);
    data[5]=1;
    data[4]=1;
    data[3]=1;

    for(i=6; i<=n; i++)
    {
        for(j=0;j<10;j++) chk[j]=0;
        k=i;
        while(k>0)
        {
            chk[k%10]++;
            k/=10;
        }
        for(j=2; j<=5; j++)
        {

            if(i%j!=0&&chk[j]==0)
            {
                if(data[i-j]!=0||i-j==1)
                {
                    if(data[i]==0) data[i]=data[i-j]+1;
                    else data[i]=min(data[i],data[i-j]+1);
                }
            }
        }
    }
    if(data[n]!=0) printf("%d",data[n]);
    else printf("-1");
    return 0;
}
