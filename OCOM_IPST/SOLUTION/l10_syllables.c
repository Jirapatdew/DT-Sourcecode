/*
LANG : C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char c[100];
    int n,p;
    int len,i,j,sum;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        gets(c);
        len=strlen(c);
        p=0;sum=0;
        for(j=0;j<len;j++)
        {
            if(c[j]=='a'||c[j]=='e'||c[j]=='i'||c[j]=='o'||c[j]=='u')
            {
                if(p==1) continue;
                p=1;
                sum++;
            }
            else p=0;
        }
        printf("%d\n",sum);
    }
    return 0;
}
