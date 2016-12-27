#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow(int a,int b)
{
    int i,total=1;
    for(i=0; i<b; i++) total*=a;
    return total;
}
int main()
{
    int num=0,st=0,len,i;
    char data[2005]= {'\0'};
    gets(data);
    len=strlen(data);
    for(i=0; i<len; i++)
    {
        if(data[i]=='{') st++;
        if(data[i]=='}') st--;
        if(data[i]==','&&st==1) num++;
    }
    if(len==2) printf("1");
    else printf("%d",pow(2,num+1));
    return 0;
}
