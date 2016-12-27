#include <stdio.h>
#include <stdlib.h>

int tree[200005]={0};
int MaxVal;
void update(int idx ,int val)
{
    while(idx<=MaxVal)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
int freqTo(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    int n,m,i,a,b,c,d,e;
    scanf("%d%d",&n,&m);
    MaxVal=n;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d%d%d",&b,&c,&d);
            update(b,d);
            update(c+1,-d);
        }
        else
        {
            scanf("%d",&e);
            printf("%d\n",freqTo(e));
        }
    }

    return 0;
}
