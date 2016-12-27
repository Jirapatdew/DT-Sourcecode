#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dice(char [],int,int,int,int,int,int,int);
int len;
int main()
{
    int n,i;
    char data[6][1001]={{'/0'}};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",data[i]);
    for(i=0;i<n;i++) {len = strlen(data[i]);dice(data[i],0,1,2,3,5,4,6);}
    return 0;
}
void dice(char data[],int i,int a,int b,int c,int d,int e,int f)
{
    if(i==len) printf("%d ",b);
    else switch(data[i])
    {
        case 'F':dice(data,i+1,d,a,c,f,e,b);break;
        case 'B':dice(data,i+1,b,f,c,a,e,d);break;
        case 'L':dice(data,i+1,e,b,a,d,f,c);break;
        case 'R':dice(data,i+1,c,b,f,d,a,e);break;
        case 'C':dice(data,i+1,a,e,b,c,d,f);break;
        case 'D':dice(data,i+1,a,c,d,e,b,f);break;
    }
}
