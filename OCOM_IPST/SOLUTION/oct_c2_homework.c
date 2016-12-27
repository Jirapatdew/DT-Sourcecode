#include <stdio.h>
#include <stdlib.h>

int H[105][1005]={0};
int d[105]={0};
int s[105]={0};
int p[105]={0};
int t[105]={0};

int chk(int i,int day)
{
    if(d[i]<day) return s[i]-(p[i]*(day-d[i]));
    else return s[i];
}
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n;
    int i,j,val,k,l,ma=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d%d%d",&d[i],&s[i],&p[i],&t[i]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=1000;j++)
        {
            if(j-t[i]<0) {H[i][j]=H[i-1][j];continue;}
            val=chk(i,j);
            if(val<0) {H[i][j]=H[i-1][j];continue;}
            H[i][j]=max(H[i-1][j],H[i-1][j-t[i]]+val);
        }

    }
    for(j=0;j<=1000;j++) if(ma<H[n][j]) ma=H[n][j];
    printf("%d",ma);
    return 0;
}
