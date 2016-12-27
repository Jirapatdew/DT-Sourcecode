#include <stdio.h>

using namespace std;

int main()
{
    int n,m;
    int c[5]={0};
    int a[2000]={0},b[2000]={0};
    int sum1=0,sum2=0;
    scanf("%d%d%d%d",&c[1],&c[2],&c[3],&c[4]);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        if(c[1]*a[i]<c[2]) sum1+=c[1]*a[i];
        else sum1+=c[2];
    }
    if(c[3]<sum1) sum1=c[3];
    for(int i=0;i<m;i++)
    {
        if(c[1]*b[i]<c[2]) sum2+=c[1]*b[i];
        else sum2+=c[2];
    }
    if(c[3]<sum2) sum2=c[3];
    if(c[4]<sum1+sum2) printf("%d",c[4]);
    else printf("%d",sum1+sum2);
    return 0;
}