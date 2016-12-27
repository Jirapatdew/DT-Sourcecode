#include <stdio.h>

using namespace std;

int inc[200050]={0};
int stk[200050]={0},ed=2;
int main()
{
    int n,t,a,v;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d",&a,&v);
            inc[a]+=v;
            sum+=a*v;
        }
        else if(t==2)
        {
            scanf("%d",&v);
            stk[ed++]=v;
            sum+=v;
        }
        else
        {
            ed--;
            sum=sum-inc[ed]-stk[ed];
            inc[ed-1]+=inc[ed];
            inc[ed]=0;
        }
        printf("%.6lf\n",(double)sum/(ed-1));
    }
    return 0;
}
