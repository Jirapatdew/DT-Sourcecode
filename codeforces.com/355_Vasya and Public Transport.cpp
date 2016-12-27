#include <stdio.h>

using namespace std;

int main()
{
    int n,l,r,ql,qr;
    int Min=-1u/2;
    int a[100010]={0};
    int suml[100010]={0},sumr[100010]={0};
    scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) suml[i]=a[i]+suml[i-1];
    for(int i=n;i>0;i--) sumr[i]=a[i]+sumr[i+1];
    for(int i=1;i<=n;i++)
    {
        //left
        int x=(suml[i]*l)+(sumr[i+1]*r);
        if(i-1>n-i) x+=(i-n+i-1)*ql;
        else if(n-i-1>i) x+=(n-i-i-1)*qr;
        if(x<Min) Min=x;

        //right
        x=(suml[i-1]*l)+(sumr[i]*r);
        if(i-1-1>n-i+1) x+=(i-1-n+i-1-1)*ql;
        else if(n-i+1-1>i-1) x+=(n-i+1-i+1-1)*qr;
        if(x<Min) Min=x;

    }
    printf("%d",Min);
    return 0;
}