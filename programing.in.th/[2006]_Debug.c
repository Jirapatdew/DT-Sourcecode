#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[305][305]={'\0'};
int r,c,pass=0;
int chk(int i,int j,int k)
{
    int t=0,n,m,o,p,num=0;
    num=k*k/2;
    for(n=i,o=i-k+1;t!=num;n--,o++)
    {
        for(m=j,p=j-k+1;m>j-k&&t!=num;m--,p++)
        {
            t++;
            if(data[n][m]!=data[o][p]) return 0;
        }
    }
    return 1;
}
int main()
{
    int i,j,k,min;
    scanf("%d%d\n",&r,&c);
    for(i=0;i<r;i++)
    {
        gets(data[i]);
    }
    if(r<c) min=r;
    else min=c;
    for(k=min;k>=2;k--)
    {
        for(i=k-1;i<r;i++)
        {
            for(j=k-1;j<c;j++)
            {
                if(chk(i,j,k)==1) {pass=1;printf("%d",k);break;}
            }
            if(pass==1) break;
        }
        if(pass==1) break;
    }
    if(pass==0) printf("-1");
    return 0;
}
