#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,b=0,c=0,d=0,e=0,sum=0;
    int x[5]= {0};
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d%d%d",&x[0],&x[1],&x[2],&x[3],&x[4]);
        a+=x[0];
        b+=x[1];
        c+=x[2];
        d+=x[3];
        e+=x[4];
    }
    sum+=a;
    d+=e/2;
    e=e%2;
    if(b>d)
    {
        sum+=d;
        b=b-d;
        d=0;
        sum+=c/2;
        c=c%2;
    }
    else
    {
        sum+=b;
        d=d-b;
        b=0;
        c+=d/2;
        d=d%2;
        sum+=c/2;
        c=c%2;
    }
    b*=6;c*=4;d*=2;
    if((b+c+d+e)%8==0) sum+=(b+c+d+e)/8;
    else sum+=((b+c+d+e)/8)+1;
    printf("%d",sum);
    return 0;
}
