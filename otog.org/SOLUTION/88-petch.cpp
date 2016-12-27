#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

using namespace std;

struct dt
{
    int p;
    int number;
    bool operator < (const dt &T) const
    {
        return p<T.p;
    }
    dt(int b,int c)
    {
        p=b;
        number=c;
    }
};
set<dt> x;
set<dt> y;
set<dt>::iterator lo,up;
set<dt>::iterator px,py;
int main()
{
    int n,m,l;
    int tmp,i;
    int a,b;
    long long tmpx,tmpy;
    struct dt c(0,0);

    scanf("%d%d%d",&n,&m,&l);
    x.insert(dt(-1000000,0));
    for(i=1;i<=m;i++)
    {
        scanf("%d",&tmp);
        x.insert(dt(tmp,i));
    }
    x.insert(dt(1000000,0));
    y.insert(dt(-1000000,0));
    for(i=1;i<=l;i++)
    {
        scanf("%d",&tmp);
        y.insert(dt(tmp,i+m));
    }
    y.insert(dt(1000000,0));

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        c.p=b;
        lo=y.lower_bound(c);
        up=y.upper_bound(c);
        if(lo->p==b) py=lo;//ถ้าเจอ
        else
        {
            lo--;
            if(((up->p)-b)>(b-(lo->p))) py=lo;
            else if(((up->p)-b)==(b-(lo->p)))
            {
                if((up->number)>(lo->number)) py=lo;
                else py=up;
            }
            else py=up;
        }

        c.p=a;
        lo=x.lower_bound(c);
        up=x.upper_bound(c);
        if(lo->p==a) px=lo;//ถ้าเจอ
        else
        {
            lo--;
            if(((up->p)-a)>(a-(lo->p))) px=lo;
            else if(((up->p)-a)==(a-(lo->p)))
            {
                if((up->number)>(lo->number)) px=lo;
                else px=up;
            }
            else px=up;
        }

        //////////////
        tmpx=((long long)((px->p)-a)*(long long)((px->p)-a))+((long long)b*(long long)b);
        tmpy=((long long)((py->p)-b)*(long long)((py->p)-b))+((long long)a*(long long)a);
        if(tmpx<=tmpy) printf("%d\n",px->number);
        else printf("%d\n",py->number);
    }
    //printf("%d,%d",px->a,px->number);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

using namespace std;

struct dt
{
    int a;
    int number;
    bool operator < (const dt &T) const
    {
        return a<T.a;
    }
    dt(int b,int c)
    {
        a=b;
        number=c;
    }
};
set<dt> x;
set<dt> y;
set<dt>::iterator lo,up;
set<dt>::iterator px,py;
int main()
{
    int n,m,l;
    int tmp,i;
    int a,b;
    long long tmpx,tmpy;
    struct dt c(0,0);
    scanf("%d%d%d",&n,&m,&l);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&tmp);
        x.insert(dt(tmp,i));
    }
    for(i=1;i<=l;i++)
    {
        scanf("%d",&tmp);
        y.insert(dt(tmp,i+m));
    }
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        c.a=b;
        lo=y.lower_bound(c);
        up=y.upper_bound(c);
        if(lo==y.end()) py= --lo;//ไม่เจอและมีค่าเกิน
        else if(lo->a==b) py=lo;//ถ้าเจอ
        else
        {
            if(lo==y.begin()) py=lo;
            else
            {
                lo--;
                if(((up->a)-b)>(b-(lo->a))) py=lo;
                else if(((up->a)-b)==(b-(lo->a)))
                {
                    if(up->number>lo->number) py=lo;
                    else py=up;
                }
                else py=up;
            }
        }

        c.a=a;
        lo=x.lower_bound(c);
        up=x.upper_bound(c);
        if(lo==x.end()) px= --lo;//ไม่เจอและมีค่าเกิน
        else if(lo->a==a) px=lo;//ถ้าเจอ
        else
        {
            if(lo==x.begin()) px=lo;
            else
            {
                lo--;
                if(((up->a)-a)>(a-(lo->a))) px=lo;
                else if(((up->a)-a)==(a-(lo->a)))
                {
                    if(up->number>lo->number) px=lo;
                    else px=up;
                }
                else px=up;
            }
        }

        //////////////
        tmpx=(long long)((px->a-a)*(px->a-a))+(long long)(b*b);
        tmpy=(long long)((py->a-b)*(py->a-b))+(long long)(a*a);
        if(tmpx<=tmpy) printf("%d\n",px->number);
        else printf("%d\n",py->number);
    }
    //printf("%d,%d",px->a,px->number);
    return 0;
}
*/
