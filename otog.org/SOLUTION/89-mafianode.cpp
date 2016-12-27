#include <stdio.h>
#include <queue>

using namespace std;

struct dt
{
    int val,id;
    bool operator < (const dt& T) const
    {
        if(val!=T.val) return val<T.val;
        else return id<T.id;
    }
    dt(int _val,int _id)
    {
        val=_val;
        id=_id;
    }
};

priority_queue<dt> ST;
int v[1000010]={0};
int chk[1000010]={0};
int main()
{
    int n,l,r,y,x;
    char ch[5];
    scanf("%d%d%d\n",&n,&l,&r);
    for(int i=1;i<=n;i++) ST.push(dt(0,i));
    for(int i=1;i<=l+r;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='L'||ch[0]=='C')
        {
            scanf("%d%d",&x,&y);
            if(ch[0]=='L') v[y]+=1;
            else v[y]+=3;
            ST.push(dt(v[y],y));
        }
        else if(ch[0]=='R')
        {
            while(chk[ST.top().id]!=0)
                ST.pop();
            printf("%d\n",ST.top().id);
        }
        else
        {
            while(chk[ST.top().id]!=0) ST.pop();
            chk[ST.top().id]=1;
            ST.pop();
        }
    }
    return 0;
}
