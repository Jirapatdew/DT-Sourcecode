#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int rev(char a[],int p)
{
    if(p<0) return 0;
    else
    {
        printf("%c",a[p]);
        rev(a,p-1);
    }
}

int main()
{
    int len;
    char a[1005];
    scanf("%s",a);
    len=strlen(a);
    rev(a,len-1);

    return 0;
}
