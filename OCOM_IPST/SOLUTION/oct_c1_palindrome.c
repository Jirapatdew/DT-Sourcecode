#include <stdio.h>
#include <stdlib.h>

int x[5005]= {0},y=0;
int a[5005];
int n,k,z=0;
int check()
{
    int s=(k-1)/2,i;
    for(i=0;i<=s;i++)
    {
        if(a[x[i+1]-1]!=a[x[k-i]-1]) return -1;
    }
    return 1;
}
int combination(int s,int p)
{
    int i,j,ans;
    if(p>k&&z==0)
    {
        ans=check();
        if(ans==1) {z=k;printf("%d",z);}
        return 0;
    }
    else if(z==0) for(i=s; i<=n-(k-p); i++)
        {
            x[p]=i;
            combination(i+1,p+1);
        }
}
int main()
{
    int i;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n; i>0; i--)
    {
        k=i;
        combination(1,1);
        if(z!=0) {break;}
    }
    return 0;
}
