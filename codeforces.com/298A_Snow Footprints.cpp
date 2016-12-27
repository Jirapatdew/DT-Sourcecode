#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int s=0,t=0;
    char c[1010];
    scanf("%d%s",&n,&c[1]);
    for(int i=1;i<=n&&s==0;i++) if(c[i]!='.') s=i;
    for(int i=n;i>=1&&t==0;i--) if(c[i]!='.') t=i;
    if(c[s]=='L'&&c[t]=='L') printf("%d %d",t,s-1);
    else if(c[s]=='R'&&c[t]=='R') printf("%d %d",s,t+1);
    else//R L
    {
        int i=s+1;
        while(c[i]=='R') i++;
        printf("%d %d",s,i-1);
    }
    return 0;
}