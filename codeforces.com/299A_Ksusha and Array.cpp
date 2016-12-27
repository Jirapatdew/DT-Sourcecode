#include <stdio.h>

using namespace std;
int data[100050]={0};
int gcd(int a,int b)
{
    if( b == 0 ) return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    int a,gc;
    scanf("%d",&n);
    scanf("%d",&data[0]);
    gc=data[0];
    for(int i=1;i<n;i++)
    {
        scanf("%d",&data[i]);
        gc=gcd(gc,data[i]);
    }
    for(int i=0;i<n;i++)
        if(data[i]<=gc&&gc%data[i]==0){printf("%d",data[i]);return 0;}
    printf("-1");
    return 0;
}