#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#define MaxV 100100
using namespace std;

int T[200010]={0};
int freqTo(int i)
{
    int sum=0;
    for(;i>0;i-=(i&-i)) sum+=T[i];
    return sum;
}
void update(int i,int val)
{
    for(;i<MaxV;i+=(i&-i)) T[i]+=val;
}
struct dt
{
    int id,p;
    bool operator <(const dt& T) const
    {
        return p>T.p;
    }
    dt(int _id,int _p){id=_id;p=_p;}
};
priority_queue<dt> Q;
int a[200010]={0};
int main()
{
    int m,c,num=1,p;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d",&p);
            Q.push(dt(num,p));
            update(p,1);
            a[num]=p;
            num++;
        }
        else if(c==2)
        {
            if(Q.empty()) printf("0\n");
            else
            {
                dt x=Q.top();
                Q.pop();
                printf("%d\n",x.id);
                update(x.p,-1);
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",freqTo(a[x]-1));
        }
    }
    return 0;
}
