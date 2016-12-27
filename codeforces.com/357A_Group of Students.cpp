#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int g1,g2,x,y;
    int a[110]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i]+=a[i-1];}
    scanf("%d%d",&x,&y);
    int i;
    for(i=1;i<=n;i++)
    {
        g1=a[i-1];
        g2=a[n]-g1;
        if((x<=g1&&g1<=y)&&(x<=g2&&g2<=y)) {printf("%d",i);break;}
    }
    if(i==n+1) printf("0");
    return 0;
}