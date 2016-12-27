#include <stdio.h>
#include <stdlib.h>
int C[53][53]={0};
int main()
{
    int i,j;
    int q;
    for(i=0;i<=52;i++) C[i][0]=1;
    for(i=0;i<=52;i++) C[i][i]=1;
    for(i=1;i<=52;i++)
        for(j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%2009;

    scanf("%d",&q);
    int n,k,sol;
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&n,&k);
        k++;
        sol=(C[n][k]*C[n-1][k-1]-C[n][k-1]*C[n-1][k]+2009*2009)%2009;
        printf("%d\n",sol);
    }
    //T(n,k)=C(n, k)*C(n-1, k-1) - C(n, k-1)*C(n-1, k)
    return 0;
}
