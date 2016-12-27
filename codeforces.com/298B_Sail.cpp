#include <stdio.h>

using namespace std;

int main()
{
    int t;
    int a,b,x,y;
    int N,S,E,W;
    int chk=0;
    char c;
    N=S=E=W=0;
    scanf("%d%d%d%d%d\n",&t,&a,&b,&x,&y);
    x-=a;
    y-=b;
    for(int i=1;i<=t;i++)
    {
        scanf("%c",&c);
        if(c=='N') N++;
        else if(c=='S') S++;
        else if(c=='E') E++;
        else if(c=='W') W++;
        if(x>=0 and y>=0 and x<=E and y<=N) {printf("%d",i);return 0;}
        else if(x>=0 and y<=0 and x<=E and -y<=S) {printf("%d",i);return 0;}
        else if(x<=0 and y>=0 and -x<=W and y<=N) {printf("%d",i);return 0;}
        else if(x<=0 and y<=0 and -x<=W and -y<=S) {printf("%d",i);return 0;}
    }
    printf("-1");
    return 0;
}