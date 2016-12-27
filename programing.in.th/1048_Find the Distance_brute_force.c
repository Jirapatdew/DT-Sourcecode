#include <stdio.h>
#include <stdlib.h>
//คำนวณได้
int main()
{
    int n,k,i,j,x;
    long long dif=0;
    int bit1[35]={0},bit2[35]={0};
    scanf("%d%d",&k,&n);
    for(i=1;i<n;i+=2)
    {
        dif++;
        for(x=0;x<2;x++)
        {
            if(i==1) x++;
            j=k;
            while(bit1[j]!=0) {bit1[j]=0;j--;}
            bit1[j]=1;
        }
        for(x=0;x<2;x++)
        {
            j=k;
            while(bit2[j]!=0) {bit2[j]=0;j--;}
            bit2[j]=1;
        }
        for(j=k;j>0;j--) dif+=bit1[j]^bit2[j];
    }
    if(n%2!=0) dif++;
    printf("%lld",dif);
    return 0;
}
