#include <stdio.h>
#include <stdlib.h>

int data[1000005]={0};
int main()
{
    int n,k;
    int p,i;
    scanf("%d%d",&n,&k);
    for(i=n;i>0;i--)
    {
        data[i]=k%i;
    }
    p=1; //เริ่มให้อยู่ตำแหน่งที่ 1
    for(i=2;i<=n;i++)
    {
        p=(data[i]+p)%i;
        if(p==0) p=i;
    }
    printf("%d",p);
    return 0;
}
