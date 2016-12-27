#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[2005]={'\0'};
    int i,len;
    int num=0;
    int ans=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(a[i]=='(') num++;
        if(a[i]==')')
        {
            if(num<=0) ans++;
            else num--;
        }
    }
    printf("%d",ans+num);
    return 0;
}

