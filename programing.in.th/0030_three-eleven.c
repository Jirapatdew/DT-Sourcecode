#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char x[1000005]={'\0'};
    int len,three,eleven,i;
    long long sum;
    gets(x);
    len=strlen(x);
    sum=0;
    for(i=0;i<len;i++) sum+=x[i]-'0';
    three=sum%3;
    sum=0;
    for(i=len-1;i>=1;i-=2)
    {
        sum+=(x[i-1]-'0')*10+(x[i]-'0');
    }
    if(len%2==1) sum+=x[0]-'0';
    eleven=sum%11;
    printf("%d %d",three,eleven);
    return 0;
}
