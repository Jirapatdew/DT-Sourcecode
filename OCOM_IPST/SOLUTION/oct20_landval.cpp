#include <stdio.h>

using namespace std;

int T[200010]={0},N;
int freqTo(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=T[i];
        i-=(i&-i);
    }
    return sum;
}
int freqAt(int i)
{
    int z=i-(i&-i);
    int x=T[i],y=i-1;
    while(y>z)
    {
        x-=T[y];
        y-=(y&-y);
    }
    return x;
}
int update(int i,int v)
{
    while(i<=N)
    {
        T[i]+=v;
        i+=(i&-i);
    }
}
int main()
{
    int M;
    int x,y,v,a;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d%d%d",&x,&y,&v);
            update(x,v);
            update(y+1,-v);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",freqTo(x));
        }

    }
    return 0;
}
