#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,i;
    char x[101];
    gets(x);
    a=strlen(x);
    for(i=0;i<a;i++)
    {
        if(x[i]=='a'&&x[i+1]=='p'&&x[i+2]=='a') {printf("a");i=i+2;}
        else if(x[i]=='e'&&x[i+1]=='p'&&x[i+2]=='e') {printf("e");i=i+2;}
        else if(x[i]=='i'&&x[i+1]=='p'&&x[i+2]=='i') {printf("i");i=i+2;}
        else if(x[i]=='o'&&x[i+1]=='p'&&x[i+2]=='o') {printf("o");i=i+2;}
        else if(x[i]=='u'&&x[i+1]=='p'&&x[i+2]=='u') {printf("u");i=i+2;}
        else printf("%c",x[i]);
    }
    return 0;
}
