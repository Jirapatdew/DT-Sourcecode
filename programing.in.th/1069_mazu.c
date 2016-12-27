#include <stdio.h>
#include <stdlib.h>

//stack
int main()
{
    int n,i,p=0;
    char x[100005],c;
    scanf("%d",&n);
    scanf("\n%c",&c);
    x[0]=c;
    for(i=1;i<n;i++)
    {
        scanf("\n%c",&c);
        if(p<0||x[p]!=c) x[++p]=c;
        else {p--;}
    }
    printf("%d\n",p+1);
    if(p<0) printf("empty");
    else for(i=p;i>=0;i--) printf("%c",x[i]);
    return 0;
}
