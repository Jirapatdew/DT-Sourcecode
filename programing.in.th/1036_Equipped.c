#include <stdio.h>
#include <stdlib.h>

int pow(int a,int b)
{
    int i,total=1;
    for(i=0; i<b; i++) total*=a;
    return total;
}
int main()
{
    int n,k,m;
    int chk[300];
    int i,a,b,j,total,x;
    scanf("%d%d",&n,&k);
    for(i=0; i<300; i++) chk[i]=-1;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        total=0;
        for(j=0; j<k; j++)
        {
            scanf("%d",&b);
            total+=b*pow(2,j);
        }
        if(chk[total]>a||chk[total]==-1) chk[total]=a;
    }
    m=pow(2,k)-1;
    for(i=1; i<=m; i++)
    {
        if(chk[i]!=-1)
        {
            for(j=i+1; j<=m; j++)
            {
                if(chk[j]!=-1)
                {
                    x=i|j;
                    if(x<=m)
                    {
                        if(chk[x]==-1||chk[x]>chk[i]+chk[j]) chk[x]=chk[i]+chk[j];
                    }
                }
            }
        }
    }
    printf("%d",chk[m]);
    return 0;
}
