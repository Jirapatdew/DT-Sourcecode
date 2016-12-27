#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int i,j,k,max=0,num,len;
    char tmp[]="UUDDLRLRBAS";
    char c[200]={'\0'};
    gets(c);
    len=strlen(c);


    for(i=len-10;i<len;i++)
    {
        num=0;
        if(i<0) continue;
        for(j=i;j<len;j++)
        {
            if(c[j]!=tmp[j-i]) break;
        }
        if(j==len) {max=j-i;break;}
    }
    for(i=max;i<=10;i++) printf("%c",tmp[i]);
    return 0;
}
