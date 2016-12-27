#include <stdio.h>

using namespace std;

int main()
{
    int k,d;
    scanf("%d%d",&k,&d);
    if(k==1&&d==0) printf("0");
    else if(d==0) printf("No solution");
    else
    {
        printf("%d",d);
        for(int i=1;i<k;i++) printf("0");
    }
    return 0;
}