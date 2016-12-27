#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long val=0,total=0;
    long long a[1000005],n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=2;i<=n;i++) a[i]+=a[i-1];
    val=a[1];
    total=a[1];
    for(i=2;i<=n;i++)
    {
        val=(val+a[i])%2553;
        total+=val;
        total=total%2553;
    }
    printf("%lld",total%2553);

}
/*int main()
{
    int val = 0,n,i,j,k;
    int a[10000];
    scanf("%d",&n);
    //for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++)
     for(j=0;j<=i;j++)
        {for(k=0;k<=j;k++)
              printf("%d ",k+1);printf("\n");}//val += a[k];
    //val %= 2553;
   // printf("%d",val);
    return 0;
}*/
