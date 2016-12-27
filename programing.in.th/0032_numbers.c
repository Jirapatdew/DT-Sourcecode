#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,x,j;
    int chk[13]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++) {scanf("%d",&x);chk[x]++;}
    if(chk[0]>0)
    {
        for(j=1;j<=10;j++)
        if(chk[j]>0) {printf("%d",j);chk[j]--;break;}
    }
    for(i=0;i<=10;i++)
    {
        while(chk[i]>0) {printf("%d",i);chk[i]--;}
    }
    return 0;
}
