#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100005]={'\0'};
int p=0;
void push(char ch)
{
    stack[p]=ch;
    p++;
}
char pop()
{
    return stack[--p];
}
int is_empty()
{
    if(p==0) return 1;
    else return 0;
}
int main()
{
    int n;
    int i,k;
    int len,pass;
    char data[100005]={'\0'},x;
    scanf("%d\n",&n);
    for(k=0;k<n;k++)
    {
        gets(data);
        p=0,pass=0;
        len=strlen(data);
        for(i=0;i<len;i++)
        {
            if(data[i]=='('||data[i]=='['||data[i]=='{') push(data[i]);
            else if(data[i]==')'||data[i]==']'||data[i]=='}')
            {
                if(is_empty()==1) {printf("no\n");pass=1;break;}
                else
                {
                    x=pop();
                    if((data[i]==')'&&x!='(')||(data[i]==']'&&x!='[')||(data[i]=='}'&&x!='{'))
                    {
                        printf("no\n");pass=1;break;
                    }
                }
            }
        }
        if(pass==0&&is_empty()==1) printf("yes\n");
        else if(pass==0) printf("no\n");
    }
    return 0;
}
