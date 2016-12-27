#include <stdio.h>
#include <string.h>
using namespace std;

bool chk(char b)
{
    if(b=='a'||b=='e'||b=='i'||b=='o'||b=='u') return true;
    else return false;
}
int main()
{
    char a[1010];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        int len=strlen(a);
        int s1=0,t1=0,s2=0,t2=0;
        for(int i=0;i<len;i++)
            if(chk(a[i])) {s1=i;break;}
            t1=s1;
        for(int i=s1+1;i<len;i++)
            if(!chk(a[i])) {t1=i-1;break;}
        for(int i=len-1;i>=0;i--)
            if(chk(a[i])) {t2=i;break;}
            s2=t2;
        for(int i=t2-1;i>=0;i--)
            if(!chk(a[i])) {s2=i+1;break;}
        if(s1==s2&&t1==t2) {printf("%s\n",a);continue;}
        for(int i=0;i<s1;i++) printf("%c",a[i]);
        for(int i=s2;i<=t2;i++) printf("%c",a[i]);
        for(int i=t1+1;i<s2;i++) printf("%c",a[i]);
        for(int i=s1;i<=t1;i++) printf("%c",a[i]);
        for(int i=t2+1;i<len;i++) printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
