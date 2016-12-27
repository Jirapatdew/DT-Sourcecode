#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    int p,a,i;
    int link_f[5005]={0};
    int link_b[5005]={0};
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) {link_f[i]=i+1;link_b[i]=i-1;}
    link_f[n]=1;
    link_b[1]=n;
    p=n;
    while(n>0)
    {
        a=k%n;
        if(a<n/2) for(i=1;i<=a;i++) p=link_f[p];
        else for(i=1;i<=n-a;i++) p=link_b[p];//ทำเพื่อย้นเวลา ถ้ามากกว่าครึ่งให้ถอยหลังแทน
        printf("%d\n",p);
        link_f[link_b[p]]=link_f[p];
        link_b[link_f[p]]=link_b[p];
        p=link_b[p];
        n--;
    }

    return 0;
}
