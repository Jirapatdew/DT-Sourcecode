#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch[10000];
    int a,i,upper=0,lower=0;
    scanf("%s",ch);
    a=strlen(ch);
    for(i=0;i<=a;i++)
    {
        if(ch[i]<='Z'&&ch[i]>='A')
        upper=1;
        if(ch[i]<='z'&&ch[i]>='a')
        lower=1;
        if(upper==1 && lower==1)
    {
        printf("Mix");
        break;
    }
    }
    if(upper==1 && lower==0)
    printf("All Capital Letter");
    if(upper==0 && lower==1)
    printf("All Small Letter");
    return 0;
}
