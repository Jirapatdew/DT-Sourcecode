//จาก 1 เป็น 2 หลักผิดผลาด
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,a,b,count=1,sum=0,c;
    char x[20]= {'\0'},y[20]= {'\0'};
    scanf("%s %s",x,y);
    a=strlen(x);
    while(1)
    {
        for(i=0; i<a; i++)
        {
            if(x[i]==x[i+1]) ++count;
            else
            {
                sum=sum+((x[i]-'0')*count*count);
                count=1;
                continue;
            }
        }
        if(strcmp(x,y)==0) break;
        for(i=a-1; i>=0; i--)
        {
            if(x[i]=='9')
            {
                x[i]='0';
                if(x[i-1]!='9')
                {
                    c=(x[i-1]-'0')+1;
                    x[i-1]=c+'0';
                    break;
                }
            }
            else if(x[i]!='9')
            {
                c=(x[i]-'0')+1;
                x[i]=c+'0';
                break;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
