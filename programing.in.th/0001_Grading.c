/*
TASK: grade
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s;
    scanf("%d",&s);
    if(s>=80) printf("4");
    else if(s>=75) printf("3.5");
    else if(s>=70) printf("3");
    else if(s>=65) printf("2.5");
    else if(s>=60) printf("2");
    else if(s>=55) printf("1.5");
    else if(s>=50) printf("1");
    else printf("0");

    return 0;
}
