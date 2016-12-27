#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,y,p=0,num=0;
    scanf("%d%d",&n,&m);
    n--;m--;
    if(n<m) swap(n,m);
    for(int i=1;i<=m;i++)
    {
        y=(n*i)/m;
        if((n*i)%m!=0) y++;
        num+=(n-y)*(i-p);
        p=i;
    }
    num*=2;
    printf("%d",(n*m)-num);
    return 0;
}
