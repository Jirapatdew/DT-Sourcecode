#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check_prime(int x)
{
    int k,i;
    k=sqrt(x);
    for(i=2;i<=k;i++) if(x%i==0) return 0;
    return 1;
}
int check_palindrome(int x)
{
    char string[100];
    int len,i=0;
    while(x>0)
    {
        string[i++]=x%10+'0';
        x=x/10;
    }
    string[i]='\0';
    len=strlen(string);
    for(i=0;i<len/2;i++)
    {
        if(string[i]!=string[len-i-1]) return 0;
    }
    return 1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n>=100000) printf("1003001");
    else
    {
        for(i=n;;i++)
        {
            if(check_palindrome(i)==1)
            {
                if(check_prime(i)==1) {printf("%d",i); break;}
            }
        }
    }
    return 0;
}
//ประมาณ 100000-1000000 จะได้คำตอบ 1003001
