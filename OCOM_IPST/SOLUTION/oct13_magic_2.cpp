#include <stdio.h>
#include <set>
#include <map>
using namespace std;

struct all
{
    int w,v;
    bool operator < (const all& T) const
    {
        return w<T.w;
    }
    all(int _w,int _v)
    {
        w=_w;
        v=_v;
    }
};
struct three
{
    int w,d,x,v;
    bool operator < (const three& T) const
    {
        return d<T.d;
    }
    three(int _w,int _v,int _d,int _x)
    {
        w=_w;
        d=_d;
        x=_x;
        v=_v;
    }
};
struct two
{
    int w,v;
    two(int _w,int _v)
    {
        w=_w;
        v=_v;
    }
};
struct cmp
{
    bool operator ()(const two& A,const two& B)
    {
        if(A.w!=B.w) return A.w<B.w;
        else return A.v<B.v;
    }
};
multiset<all> S1;
multiset<three> S3;
map<two,int,cmp> S2;
int main()
{
    int n,m,c;
    int w,v,d,x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n+m;i++)
    {
        scanf("%d",&c);
        set<three>::iterator low=S3.lower_bound(three(0,0,i,0)),pt1;
        set<three>::iterator up=S3.upper_bound(three(0,0,i,0));
        set<all>::iterator pt2;
        pt1=low;
        while(pt1!=up)
        {
            pt2=S1.find(all(pt1->w,0));
            if(pt2!=S1.end())
            {
                S1.erase(pt2);
                S1.insert(all(pt1->x,pt1->v));
            }
            pt1++;
        }
        S3.erase(low,up);
        if(c==1)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d%d",&w,&v);
                S1.insert(all(w,v));
            }
            else if(c==2)
            {
                scanf("%d%d%d",&w,&v,&d);
                S1.insert(all(w,v));
                two tmp(w,v);
                S2[tmp]=d;
            }
            else
            {
                scanf("%d%d%d%d",&w,&v,&d,&x);
                S1.insert(all(w,v));
                S3.insert(three(w,v,d,x));

            }
        }
        else
        {
            map<two,int,cmp>::iterator it;
            while(1)
            {
                if(S1.empty()) {printf("0\n");break;}
                it=S2.find(two(S1.begin()->w,S1.begin()->v));
                if(it==S2.end()||it->second>i)
                {
                    printf("%d\n",S1.begin()->v);
                    S1.erase(S1.begin());
                    break;
                }
                else S1.erase(S1.begin());
            }

        }
    }
    return 0;
}
