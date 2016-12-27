#include <stdio.h>
#define MIN(_x,_y) ((_x)<(_y))?(_x):(_y)
using namespace std;
int a[100],b[100],n;
int ans[100]={0};
double mn=-1u/2;
int bi(int x)
{
    if(x<n)
    {
        ans[x]=0;
        bi(x+1);
        ans[x]=1;
        bi(x+1);
    }
    else
    {
        int num1=0,sum1=0,sum2=0,num2;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1) {sum1+=a[i];num1++;}
            else sum2+=b[i];
        }
        num2=n-num1;
        double u=(sum1-(num1*sum1/100.0))+(sum2-(num2*sum2/100.0));
        mn=MIN(mn,u);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    bi(0);
    printf("%.2lf",mn);
    return 0;
}
