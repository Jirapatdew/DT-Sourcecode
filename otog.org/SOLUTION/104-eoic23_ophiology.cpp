#include <stdio.h>

using namespace std;

int a[100050][2]={0};
int main()
{
    int n;
    int mx=0,grd=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
    for(int j=1;j<=5;j++)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][0]==j||a[i][1]==j) sum++;
            else sum=0;
            if(sum>mx){mx=sum;grd=j;}
        }
    }
    printf("%d %d",mx,grd);
    return 0;
}
