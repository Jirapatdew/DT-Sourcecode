//เหลือใส่BTกับคำนวณค่า
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p=-1;
int check(char a)
{
    int sq;
    if(a=='*'||a=='/') sq=5;
    else if(a=='+'||a=='-') sq=3;
    else if(a=='(') sq=1;
    else if(a==')') sq=7;
    else sq=9;
    return sq;
}
int main()
{
    int len,d=0,x,y,i,n;
    char a[10000],b[10000];
    char stkopt[10000];
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {

        x=check(a[i]);
        if(x==9) b[d++]=a[i];
        else if(x==7)
        {
            while(stkopt[p]!='(')
            {
                b[d++]=stkopt[p];
                p--;
            }
            p--;
        }
        else if(x==1) stkopt[++p]=a[i];
        else if(p==-1) stkopt[++p]=a[i];
        else if(x>check(stkopt[p])) stkopt[++p]=a[i];
        else
        {
            while(x<=check(stkopt[p])&&p>=0)
            {
                b[d++]=stkopt[p];
                p--;
            }
            stkopt[++p]=a[i];
        }
    }
    while(p>=0) {b[d++]=stkopt[p];p--;}
    return 0;
}
