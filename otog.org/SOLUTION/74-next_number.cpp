#include <stdio.h>
#include <string.h>

using namespace std;

char a[3000];
int len;
int print(int n,int p)
{
    int i=len-1;
    while(n>0)
    {
        if(n>9)
        {
            a[i]='9';
            n-=9;
        }
        else
        {
            a[i]=n+'0';
            n=0;
        }
        i--;
    }
    while(i>p)
    {
        a[i]='0';
        i--;
    }
    printf("%s",a);
}
int main()
{
    int i,sum=0;
    gets(a);
    len=strlen(a);
    sum=a[len-1]-'0';
    for(i=len-2;i>=0;i--)
    {
        if(a[i]!='9'&&sum>0)
        {
            a[i]++;
            print(sum-1,i);
            return 0;
        }
        else sum+=a[i]-'0';
    }
    printf("-1");

    return 0;
}
