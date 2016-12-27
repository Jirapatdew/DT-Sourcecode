#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,l,k,c;
    int i,j,x,sum=0;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&l,&k);
    scanf("%d",&c);
    for(i=0;i<n*m;i++) {scanf("%d",&x);sum+=x;}
    sum+=l*k*c;
    if(sum%c==0) printf("%d",sum/c);
    else printf("%d",sum/c+1);


    return 0;
}
