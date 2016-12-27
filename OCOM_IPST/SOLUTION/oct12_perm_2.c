#include <stdio.h>
#include <stdlib.h>

int fac[14]={0};
int chk[14]={0};
int main()
{
    int n,k,l;
    int i,a,j,x,b,c;
    scanf("%d%d%d",&n,&k,&l);
    fac[0]=1;
    for(i=1;i<=11;i++)
    {
        fac[i]=fac[i-1]*i;
    }
    b=fac[n]/fac[n-k];
    for(i=1;i<=k;i++)
    {
        if(l%b==0) c=b;
        else c=l%b;
        x=fac[n-i]/fac[n-k];
        a=c/x;
        if(c%x!=0) a++;
        j=1;
        while(a>0)
        {
            if(chk[j]==0) a--;
            if(a==0) {printf("%d ",j);chk[j]=1;}
            j++;
        }
        b=x;
    }
    return 0;
}
