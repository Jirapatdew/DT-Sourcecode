#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct DT
{
    int id,val;
    bool operator < (const DT &T) const
    {
        return val>T.val;
    }
    DT(int _val,int _id)
    {
        val=_val;
        id=_id;
    }
};
priority_queue<DT> C,D,Y;
int chk[50005]={0},cnt=0;
int IN_Y[50005]={0};
long long sum=0;
void ans()
{
    cout << cnt;
    exit(0);
}
int main()
{
    int N,K;
    long long M;
    DT tmp(0,0);
    cin >> N >> K >> M;
    for(int i=1,a,b;i<=N;i++)
    {
        scanf("%d%d",&a,&b);
        C.push(DT(a,i));
        D.push(DT(b,i));
        IN_Y[i]=a-b;
    }
    for(cnt=0;cnt<K;cnt++)
    {
        tmp=D.top();D.pop();
        Y.push(DT(IN_Y[tmp.id],tmp.id));
        if(sum+tmp.val>M) ans();
        else sum+=tmp.val;
        chk[tmp.id]=1;
    }
    while(cnt<N)
    {
        int c,d,y;
        while(chk[C.top().id]==1) C.pop();
        while(chk[D.top().id]==1) D.pop();
        c=C.top().val;
        d=D.top().val;
        y=Y.top().val;
        if(d+y<c)
        {
            if(sum+d+y>M) ans();
            else sum+=d+y;
            chk[D.top().id]=1;
            D.pop();
            Y.pop();
            Y.push(DT(IN_Y[D.top().id],D.top().id));
        }
        else
        {
            if(sum+c>M) ans();
            else sum+=c;
            chk[C.top().id]=1;
            C.pop();
        }
        cnt++;
    }
    ans();
    return 0;
}
