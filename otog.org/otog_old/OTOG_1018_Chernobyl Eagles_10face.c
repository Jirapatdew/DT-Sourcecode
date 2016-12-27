#include <stdio.h>
#include <stdlib.h>

int total[1000]= {1};
int len=1;
int mul(int a)//0<=a<=9
{
    int i,j,t=0;
    for(i=0; i<len; i++) total[i]*=a;
    i=0;
    while(t!=0||i<len)
    {
        total[i]+=t;
        t=total[i]/10;
        total[i]%=10;
        i++;
    }
    len=i;
}
int main()
{
    int n,k,i;
    scanf("%d",&n);
    if(n<4) printf("%d",n);
    else
    {
        k=(n%3==1)?(n/3)-1:(n/3);
        for(i=0; i<k; i++) mul(3);
        if(n%3==1) mul(4);
        else if(n%3==2) mul(2);
        for(i=len-1; i>=0; i--) printf("%d",total[i]);
    }
    return 0;
}
