#include <stdio.h>

using namespace std;

int fac[14]={0};
int chk[14]={0};
int main()
{
    int n,l,Q;
    int i,a,j,x,b,c;
    fac[0]=1;
    for(i=1;i<=11;i++)
    {
        fac[i]=fac[i-1]*i;
    }

    scanf("%d",&Q);
    while(--Q>=0)
    {
        scanf("%d%d",&n,&l);
        b=fac[n];
        for(i=1;i<=11;i++) chk[i]=0;
        for(i=1;i<=n;i++)
        {
            if(l%b==0) c=b;
            else c=l%b;
            x=fac[n-i];
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
        printf("\n");
    }
    return 0;
}
