#include <stdio.h>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int p,q,a,b,c,ab,ac,bc,abc,total=0,np,nq,num,x;
        scanf("%d%d%d%d%d",&p,&q,&a,&b,&c);
        ab=(a*b)/gcd(a,b);
        ac=(a*c)/gcd(a,c);
        bc=(b*c)/gcd(b,c);
        abc=(ab*c)/gcd(ab,c);
        if(p<=0&&q<=0)
        {
            p*=-1;
            q*=-1;
            swap(p,q);
        }
        if(p>=0&&q>=0)
        {
            total=q-(q/a+q/b+q/c-q/ab-q/ac-q/bc+q/abc);
            p--;
            if(p>0) total-=p-(p/a+p/b+p/c-p/ab-p/ac-p/bc+p/abc);
        }
        else
        {
            p*=-1;
            total=q-(q/a+q/b+q/c-q/ab-q/ac-q/bc+q/abc);
            total+=p-(p/a+p/b+p/c-p/ab-p/ac-p/bc+p/abc);
        }
        printf("%d\n",total);
    }

    return 0;
}
