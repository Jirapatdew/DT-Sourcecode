#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,j,cnt=0;
    scanf("%d%d",&n,&k);
    if(k>n) {printf("-1");return 0;}
    if(k==1&&n!=1) {printf("-1");return 0;}
    if(k==1&&n==1) {printf("a");return 0;}
    else if(k==1)  {printf("-1");return 0;}
    for(i=1;i<=n-(k-2);i++)
    {
        if(i%2==1) printf("a");
        else printf("b");
        cnt=2;
    }
    if(cnt==0) printf("-1");
    else for(i=1;i<=k-2;i++){ printf("%c",cnt+'a');cnt++;}
    return 0;
}