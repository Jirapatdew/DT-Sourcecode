#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,a,x,p,d,b,c=0;
    int i,j,l,max=0,num;
    int book[105]={0};
    scanf("%d%d%d",&n,&k,&a);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&book[i]);
        book[i]+=book[i-1];
    }
    x=book[n];
    p=1;
    for(i=1;i<=x;i++)
    {
        if(i>book[p]) p++;
        num=1;
        d=p;
        b=k;
        for(j=i;j<=x&&b>0;j+=a)
        {
            b--;
            if(j>book[d])
            {
                num++;
                for(l=d;l<=n;l++)
                {
                    if(j<=book[l]) {d=l;break;}
                }
            }
        }
        if(b>0) break;
        if(num>max) {max=num;c=i;}
    }
    printf("%d %d",c,max);
    return 0;
}
