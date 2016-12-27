#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum=0;
int k;

int change(int a,int b)//a>b
{
    if(b>=k) {b-=k;k=0;}
    else {k-=b;b=0;}
    sum+=a-b;
}
int main()
{
    int i,len;
    int n=0,s=0,w=0,e=0;
    char c[120];
    gets(c);
    scanf("%d",&k);
    len=strlen(c);
    for(i=0;i<len;i++)
    {
        if(c[i]=='N') n++;
        else if(c[i]=='S') s++;
        else if(c[i]=='W') w++;
        else if(c[i]=='E') e++;
    }
    if(n>=s) change(n,s);
    else change(s,n);
    if(w>=e) change(w,e);
    else change(e,w);
    if(k>0) sum-=k;
    printf("%d",sum*2);
    return 0;
}
