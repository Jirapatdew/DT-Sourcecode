#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int a=i*i+j*j,b=sqrt(a);
            if(a==b*b&&a<=n*n) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}