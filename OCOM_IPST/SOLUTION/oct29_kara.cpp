#include <stdio.h>
#define MAX(x,y) (x>y)?x:y
using namespace std;

int num[25]={0};

int main()
{
    int n,a,b;
    int mx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        for(int j=a;j<b;j++) num[j]++;
    }
    for(int i=0;i<25;i++) mx=MAX(mx,num[i]);
    printf("%d",mx);
    return 0;
}
