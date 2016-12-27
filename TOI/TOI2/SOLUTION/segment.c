#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[3][50]={'\0'};
char chk(int a)
{
    int i,j;
    int sum=0;
    for(i=0;i<3;i++)
        for(j=a;j<a+3;j++)
            if(data[i][j]=='|'||data[i][j]=='_') sum++;
    if(sum==2) return '1';
    else if(sum==4) return '4';
    else if(sum==3) return '7';
    else if(sum==7) return '8';
    else if(sum==5)
    {
        if(data[1][a]=='|') return '5';
        else if(data[2][a]=='|') return '2';
        else return '3';
    }
    else if(sum==6)
    {
        if(data[2][a]==' ') return '9';
        else if(data[1][a+1]==' ') return '0';
        else return '6';
    }
}
int main()
{
    int n,m,i,j,t;
    long long ans,n_num1,n_num2;
    char ch;
    char s_num1[50]={'\0'},s_num2[50]={'\0'};
    scanf("%d %d",&n,&m);
    scanf("%c",&ch);
    for(i=0;i<3;i++)//input s_num1
    {
        for(j=0;;j++)
        {
            scanf("%c",&ch);
            if(ch!='\n') data[i][j]=ch;
            else break;
        }
    }
    t=0;
    for(i=0;i<n;i++){s_num1[i]=chk(t);t+=4;}

    for(i=0;i<3;i++) for(j=0;j<50;j++) data[i][j]='\0';
    for(i=0;i<3;i++)//input s_num2
    {
        for(j=0;;j++)
        {
            scanf("%c",&ch);
            if(ch!='\n') data[i][j]=ch;
            else break;
        }
    }
    t=0;
    for(i=0;i<m;i++){s_num2[i]=chk(t);t+=4;}

    n_num1=atoll(s_num1);
    n_num2=atoll(s_num2);
    ans=n_num1+n_num2;
    printf("%lld",ans);
    return 0;
}
