#include <stdio.h>
#define Min(_a,_b) ((_a)<(_b))?(_a):(_b)
using namespace std;

int main()
{
    int a,b,n;
    int dy[10200]={0},x;
    scanf("%d%d%d",&a,&b,&n);
    dy[a]=dy[b]=1;
    for(int i=0;i<10200;i++)
    {
        if(i-a>=0&&dy[i-a]==1) dy[i]=1;
        if(i-b>=0&&dy[i-b]==1) dy[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        int j;
        for(j=x;;j++) if(dy[j]!=0) break;
        printf("%d\n",j);
    }
    return 0;
}
