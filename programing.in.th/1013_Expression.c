#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100]={'\0'};
int ans[100]={0},pt=0;
int p=0;
int st,sp;
void pr()
{
    int i;
    for(i=pt-1;i>=0;i--) printf("op(%d,",ans[i]);
    printf("p");
    for(i=pt-1;i>=0;i--) printf(")");
    printf("=");
    if(p==0) for(i=st;i<=sp;i++) printf("%c",data[i]);
    else printf("null");
    printf("\n");
    pt=0;
}
int part(int a)
{
    int i,num=4,chk=0,total=1;
    char ch;
    for(i=st;i<=sp;i++)
    {
        if(data[i]=='(') chk++;
        if(data[i]==')') chk--;
        if(data[i]=='^'&&num>3&&chk==0) num=3;
        if(data[i]=='*'&&num>2&&chk==0) num=2;
        if(data[i]=='+'&&num>1&&chk==0) num=1;
    }
    if(data[st]=='('&&data[sp]==')'&&num==4)///////////////////////////// ******* ไว้ให้ถูกลำดับ check num = 4
    {
        if(a>1) p=1;
        else {st++;sp--;}
        return 0;
    }
    if(num==3) ch='^';
    if(num==2) ch='*';
    if(num==1) ch='+';
    for(i=st;i<=sp;i++)
    {
        if(data[i]=='(') chk++;
        if(data[i]==')') chk--;
        if(data[i]==ch&&chk==0)
        {
            if(total==a) {sp=i-1;return 0;}
            st=i+1;
            total++;
        }
    }
    if(total==a) return 0;
    else p=1;
}
int main()
{
    int len,n,a,i,j;
    gets(data);
    len=strlen(data);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        st=0;
        sp=len-1;
        p=0;
        while(1)
        {
            scanf("%d",&a);
            if(a==0) break;
            ans[pt++]=a;
            if(st==sp&&a>1) p=1;
            if(st!=sp&&p==0) part(a);
        }
        pr();
    }
    return 0;
}
