#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,i=9;
    int chk[15]={0};
    scanf("%d",&n);
    if(n==1) {printf("1");return 0;}
    if(n==0) {printf("10");return 0;}
    while(i>=2&&n>1)
    {
        if(n%i==0) {n/=i;chk[i]++;}
        else i--;
    }
    if(n!=1) {printf("-1");return 0;}
    for(i=2;i<=9;i++)
    {
        while(chk[i]>0)
        {
            printf("%d",i);
            chk[i]--;
        }
    }
    return 0;
}
