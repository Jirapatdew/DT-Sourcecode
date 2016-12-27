#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int k,i,j,a,b,p=0,x,len,l;
    char c[200]={'\0'};
    scanf("%d\n",&n);
    for(k=0;k<n;k++)
    {
        gets(c);
        len=strlen(c);
        p=0;
        for(i=0;i<len;i++)
            if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u') break;
        for(j=i;j<len;j++)
            if(c[j]!='a'&&c[j]!='e'&&c[j]!='i'&&c[j]!='o'&&c[j]!='u') break;

        for(b=len-1;b>=0;b--)
            if(c[b]=='a'||c[b]=='e'||c[b]=='i'||c[b]=='o'||c[b]=='u') {b++;break;}
        for(a=b-1;a>=0;a--)
            if(c[a]!='a'&&c[a]!='e'&&c[a]!='i'&&c[a]!='o'&&c[a]!='u') {a++;break;}
        if(a<0) a=0;

        p=0;
        for(l=0;l<len;l++)
        {
            if(l==i)
            {
                x=a;
                while(x<b)
                {
                    printf("%c",c[x]);
                    x++;
                }
                l=j-1;
                p=0;
                continue;
            }
            if(l==a)
            {
                x=i;
                while(x<j)
                {
                    printf("%c",c[x]);
                    x++;
                }
                l=b-1;
                p=0;
                continue;
            }
            printf("%c",c[l]);
        }
        printf("\n");
    }
    return 0;
}
