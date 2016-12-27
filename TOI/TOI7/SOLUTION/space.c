/*
TASK: space
LANG: C
AUTHOR: Jirapat Atiwattanachai
CENTER: KKU03
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[20]= {'\0'};
int n;

int space()
{
    int i;
    for(i=0; i<n; i++)
    {
        if(data[i]=='0')
        {
            printf("%s ",data);
            data[i]='1';
            printf("%s\n",data);
            data[i]='0';
        }
    }
}

int bina()
{
    int i,t=0;
    for(i=0; i<n; i++)
    {
        if(data[i]=='0')
        {
            data[i]='1';
            t=1;
            break;
        }
        else if(data[i]=='1')
        {
            data[i]='0';
        }
    }
    if(t==1)
    {
        space();
        bina();
    }
    else return 0;
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        data[i]='0';
    }
    space();
    bina();
    return 0;
}
