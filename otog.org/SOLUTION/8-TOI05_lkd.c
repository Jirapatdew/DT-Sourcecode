//ไม่ควรปริ้นระหว่างรับค่า
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char code[18]={'\0'};
int binary()
{
    int j,dt=-1,mul=1,i,sum=0;
    for(i=14;i>=0;i-=2)
    {
        ++dt;
        if(code[i]=='1')
        {
           for(j=1;j<=dt;j++) mul*=2;
           sum+=mul;
        }
        mul=1;
    }
    return sum;
}
int main()
{
    int n,i,j,k;
    int s=1;
    int len;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(k=0;k<18;k++) code[k]='\0';
        scanf("%s",&code);
        len = strlen(code);
        if(len==16)
        {
            for(j=0;j<16;j+=2)
            {
                if(s==1)
                {
                   if(code[j]=='0'&&code[j+1]=='0') {code[j]='0';s=1;}//ไม่ก็ได้
                   else if(code[j]=='1'&&code[j+1]=='1') {code[j]='1';s=2;}
                }
                else if(s==2)
                {
                    if(code[j]=='1'&&code[j+1]=='0') {code[j]='0';s=3;}
                    else if(code[j]=='0'&&code[j+1]=='1') {code[j]='1';s=4;}
                }
                else if(s==3)
                {
                    if(code[j]=='1'&&code[j+1]=='1') {code[j]='0';s=1;}
                    else if(code[j]=='0'&&code[j+1]=='0') {code[j]='1';s=2;}
                }
                else if(s==4)
                {
                    if(code[j]=='0'&&code[j+1]=='1') {code[j]='0';s=3;}
                    else if(code[j]=='1'&&code[j+1]=='0') {code[j]='1';s=4;}
                }
            }
            k=binary();
            printf("%c",binary()) ;
        }
    }
    return 0;
}
