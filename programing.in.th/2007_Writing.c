#include <stdio.h>
#include <stdlib.h>

int A[30]={0};
int a[30]={0};
int chk_A[30]={0};
int chk_a[30]={0};
int chk()
{
    int i;
    for(i=0;i<26;i++)
    {
        if(chk_a[i]!=a[i]||chk_A[i]!=A[i]) return 0;
    }
    return 1;
}
int main()
{
    char temp[3005]={'\0'};
    char data[3000005]={'\0'};
    int n,s,total=0,t,x,i;
    scanf("%d %d\n",&n,&s);
    gets(temp);
    gets(data);
    for(i=0;i<n;i++)
    {
        if(temp[i]>='A'&&temp[i]<='Z') A[temp[i]-'A']++;
        else a[temp[i]-'a']++;
    }
    for(i=0;i<n;i++)
    {
        if(data[i]>='A'&&data[i]<='Z') chk_A[data[i]-'A']++;
        else chk_a[data[i]-'a']++;
    }
    t=s-n;
    for(i=0;i<=t;i++)
    {
        if(chk()==1) total++;
        if(data[i]>='A'&&data[i]<='Z') chk_A[data[i]-'A']--;
        else chk_a[data[i]-'a']--;
        x=i+n;
        if(data[x]>='A'&&data[x]<='Z') chk_A[data[x]-'A']++;
        else chk_a[data[x]-'a']++;
    }
    printf("%d",total);
    return 0;
}
