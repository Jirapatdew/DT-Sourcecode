#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int data[15][2]={0};
int num_d[15]={0};
int chk[5005][2];
int n,m,k;
int find(int j,int a,int idx)
{
    int i,num=1;
    for(i=j+1;i<=m;i++)
    {
        if(chk[i][0]>a+i-j||chk[i][0]==-1)
        {
            chk[i][0]=a+i-j;
            chk[i][1]=idx;
        }
        else break;
    }
    for(i=j-1;i>0;i--)
    {
        if(chk[i][0]>a+num||chk[i][0]==-1)
        {
            chk[i][0]=a+num;
            chk[i][1]=idx;
            num++;
        }
        else break;
    }
}
int main()
{
    int i,j,a;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++) scanf("%d%d",&data[i][0],&data[i][1]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) chk[j][0]=-1;
        for(j=1;j<=k;j++)
        {
            a=abs(i-data[j][0]);
            if(chk[data[j][1]][0]>a||chk[data[j][1]][0]==-1)
            {
                chk[data[j][1]][0]=a;
                chk[data[j][1]][1]=j;
                find(data[j][1],a,j);
            }
        }
        for(j=1;j<=m;j++)
        {
            num_d[chk[j][1]]++;
        }
    }
     for(i=1;i<=k;i++) printf("%d\n",num_d[i]);
    return 0;
}
