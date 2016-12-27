#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char p[1005]={'\0'},e[2005]={'\0'};
    int lenp,lene,d=0,t[1005][5]={0},i,j,k,l,x=0;
    scanf("%s%s",p,e);
    lenp=strlen(p);
    lene=strlen(e);
    for(i=0,j=0;i<lenp&&j<lene;i++,j++)
    {
        if(p[i]==e[j]) {continue;}
        else if(p[i]>='A'&&p[i]<='Z')
        {
            l=0;
            t[d][0]=j;
            for(j=j;j<lene;j++)
            {
                if(e[j]=='(') l++;
                else  if(e[j]==')') l--;
                if((e[j]==','&&l==0)||(e[j]==')'&&l==-1)) {t[d][1]=j;i++;d++;break;}
            }
        }
        else {printf("no");x=1;break;}
    }
    if(x==0)
    {
        for(i=0;i<d;i++)
        {
            for(j=t[i][0];j<t[i][1];j++)
            printf("%c",e[j]);
            printf("\n");
        }
    }
    return 0;
}
