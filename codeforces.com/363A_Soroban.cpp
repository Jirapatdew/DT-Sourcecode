#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==0) printf("O-|-OOOO");
    while(n>0)
    {
        int x=n%10;
        n/=10;
        if(x>=5) {printf("-O|");x-=5;}
        else printf("O-|");
        for(int i=0;i<=4;i++)
        {
            if(i==x) printf("-");
            else printf("O");
        }
        printf("\n");
    }
    return 0;
}