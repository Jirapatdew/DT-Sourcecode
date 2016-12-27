#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[305],n[305],ans[610],input[610];
    int x[305]= {0},y[305]={0},z[610]={0},t;
    int i,j,n1,n2,s;
    scanf("%s",m);
    scanf("%s",n);
    scanf("%s",input);
    n1=strlen(m);
    n2=strlen(n);
    if(n2>n1)
    {
        s=n2;
        for(i=n1-1; i>=0; i--) x[n1-1-i]=m[i]-'0';
        for(i=n2-1; i>=0; i--) y[n2-1-i]=n[i]-'0';
    }
    else
    {
        s=n1;
        for(i=n1-1; i>=0; i--) y[n1-1-i]=m[i]-'0';
        for(i=n2-1; i>=0; i--) x[n2-1-i]=n[i]-'0';
    }

    for(i=0; i<s; i++)
    {
        for(j=0; j<s; j++)
        {
            z[j+i]=z[j+i]+(x[j]*y[i]);
            t=z[j+i]/10;
            z[j+i]=z[j+i]%10;
            z[j+1+i]=z[j+1+i]+t;
        }
    }
    for(i=605; i>=0; i--) if(z[i]!=0) break;
    for(j=i; j>=0; j--)  ans[i-j]=z[j]+'0';
    ans[i+1]='\0';
    if(!strcmp(ans,input)) printf("truth");
    else printf("dream");
    return 0;
}
