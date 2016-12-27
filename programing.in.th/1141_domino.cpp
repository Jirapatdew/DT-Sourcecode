#include <stdio.h>
#include <set>
using namespace std;

struct N
{
    int a,b,c,d;
    bool operator < (const N &T) const
    {
        return c < T.c;
    }
    N(int x1,int y1,int x2,int y2)
    {
        a=x1;b=y1;c=x2;d=y2;
    }
};
struct S
{
    int a,b,c,d;
    bool operator < (const S &T) const
    {
        return c < T.c;
    }
    S(int x1,int y1,int x2,int y2)
    {
        a=x1;b=y1;c=x2;d=y2;
    }
};
struct E
{
    int a,b,c,d;
    bool operator < (const E &T) const
    {
        return d < T.d;
    }
    E(int x1,int y1,int x2,int y2)
    {
        a=x1;b=y1;c=x2;d=y2;
    }
};
struct W
{
    int a,b,c,d;
    bool operator < (const W &T) const
    {
        return d < T.d;
    }
    W(int x1,int y1,int x2,int y2)
    {
        a=x1;b=y1;c=x2;d=y2;
    }
};
set<struct N> s_N;
set<struct S> s_S;
set<struct E> s_E;
set<struct W> s_W;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    s_N.insert(N(1,1,n,n));
    s_S.insert(S(1,1,n,n));
    s_E.insert(E(1,1,n,n));
    s_W.insert(W(1,1,n,n));

    for(int i=0;i<m;i++)
    {
        char in[5];
        int num;
        int a,b,c,d;
        scanf("%s%d",in,&num);
        if(in[0]=='N')
        {
            if(s_N.empty()) {printf("0\n");continue;}
            set<struct N>::iterator pt;
            pt=s_N.lower_bound(N(0,0,num,0));
            a=pt->a;b=pt->b;c=pt->c;d=pt->d;
            if(num<a||b!=1) {printf("0\n");continue;}
            s_N.erase(pt);
            if(d==n) s_S.erase(S(a,b,c,d));
            if(c==n) s_E.erase(E(a,b,c,d));
            if(a==1) s_W.erase(W(a,b,c,d));
            if(num!=a)
            {
                if(b==1) s_N.insert(N(a,b,num-1,d));
                if(d==n) s_S.insert(S(a,b,num-1,d));
                if(num-1==n) s_E.insert(E(a,b,num-1,d));
                if(a==1) s_W.insert(W(a,b,num-1,d));
            }
            if(num!=c)
            {
                if(b==1) s_N.insert(N(num+1,b,c,d));
                if(d==n) s_S.insert(S(num+1,b,c,d));
                if(c==n) s_E.insert(E(num+1,b,c,d));
                if(num+1==1) s_W.insert(W(num+1,b,c,d));
            }
            printf("%d\n",d);
            //for (set<struct N>::iterator it=s_N.begin(); it!=s_N.end(); ++it)
            //    printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
        }
        else if(in[0]=='S')
        {
            if(s_S.empty()) {printf("0\n");continue;}
            set<struct S>::iterator pt;
            pt=s_S.lower_bound(S(0,0,num,0));
            a=pt->a;b=pt->b;c=pt->c;d=pt->d;
            if(num<a||d!=n) {printf("0\n");continue;}
            s_S.erase(pt);
            if(b==1) s_N.erase(N(a,b,c,d));
            if(c==n) s_E.erase(E(a,b,c,d));
            if(a==1) s_W.erase(W(a,b,c,d));
            if(num!=a)
            {
                if(b==1) s_N.insert(N(a,b,num-1,d));
                if(d==n) s_S.insert(S(a,b,num-1,d));
                if(num-1==n) s_E.insert(E(a,b,num-1,d));
                if(a==1) s_W.insert(W(a,b,num-1,d));
            }
            if(num!=c)
            {
                if(b==1) s_N.insert(N(num+1,b,c,d));
                if(d==n) s_S.insert(S(num+1,b,c,d));
                if(c==n) s_E.insert(E(num+1,b,c,d));
                if(num+1==1) s_W.insert(W(num+1,b,c,d));
            }
            printf("%d\n",n-b+1);
           // for (set<struct S>::iterator it=s_S.begin(); it!=s_S.end(); ++it)
            //    printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
        }
        else if(in[0]=='E')
        {
            //for (set<struct E>::iterator it=s_E.begin(); it!=s_E.end(); ++it)
            //    printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
            if(s_E.empty()) {printf("0\n");continue;}
            set<struct E>::iterator pt;
            pt=s_E.lower_bound(E(0,0,0,num));
            a=pt->a;b=pt->b;c=pt->c;d=pt->d;
            if(num<b||c!=n) {printf("0\n");continue;}
            s_E.erase(pt);
            if(b==1) s_N.erase(N(a,b,c,d));
            if(d==n) s_S.erase(S(a,b,c,d));
            if(a==1) s_W.erase(W(a,b,c,d));
            if(num!=b)
            {
                if(b==1) s_N.insert(N(a,b,c,num-1));
                if(num-1==n) s_S.insert(S(a,b,c,num-1));
                if(c==n) s_E.insert(E(a,b,c,num-1));
                if(a==1) s_W.insert(W(a,b,c,num-1));
            }
            if(num!=d)
            {
                if(num+1==1) s_N.insert(N(a,num+1,c,d));
                if(d==n) s_S.insert(S(a,num+1,c,d));
                if(c==n) s_E.insert(E(a,num+1,c,d));
                if(a==1) s_W.insert(W(a,num+1,c,d));
            }
            printf("%d\n",n-a+1);
           // for (set<struct E>::iterator it=s_E.begin(); it!=s_E.end(); ++it)
            //    printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
        }
        else
        {
            if(s_W.empty()) {printf("0\n");continue;}
            set<struct W>::iterator pt;
            pt=s_W.lower_bound(W(0,0,0,num));
            a=pt->a;b=pt->b;c=pt->c;d=pt->d;
            if(num<b||a!=1||a==0||b==0||c==0||d==0) {printf("0\n");continue;}
            s_W.erase(pt);
            if(b==1&&!s_N.empty()) s_N.erase(N(a,b,c,d));
            if(d==n&&!s_S.empty()) s_S.erase(S(a,b,c,d));
            if(c==n&&!s_E.empty()) s_E.erase(E(a,b,c,d));
            if(num!=b)
            {
                if(b==1) s_N.insert(N(a,b,c,num-1));
                if(num-1==n) s_S.insert(S(a,b,c,num-1));
                if(c==n) s_E.insert(E(a,b,c,num-1));
                if(a==1) s_W.insert(W(a,b,c,num-1));
            }
            if(num!=d)
            {
                if(num+1==1) s_N.insert(N(a,num+1,c,d));
                if(d==n) s_S.insert(S(a,num+1,c,d));
                if(c==n) s_E.insert(E(a,num+1,c,d));
                if(a==1) s_W.insert(W(a,num+1,c,d));
            }
            printf("%d\n",c);
            //for (set<struct W>::iterator it=s_W.begin(); it!=s_W.end(); ++it)
            //    printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
        }
    }
    return 0;
}
