#include <stdio.h>
#define MIN(_x,_y) ((_x<_y)?_x:_y)
using namespace std;

int a[20]={0};
int chk[20]={0};
int num[20]={0},n;
int gen(int t,int c,int col)
{
    if(t<n)
    {
        for(int i=1;i<=n;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                gen(t+1,a[i],col+1);//new col
                if(c>=1)
                {
                    int tmp=MIN(c-1,a[i]);
                    gen(t+1,tmp,col);//old col
                }
                chk[i]=0;
            }
        }
    }
    else num[col]++;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    gen(0,0,0);
    for(int i=1;i<=n;i++) printf("%d\n",num[i]);
    return 0;
}
