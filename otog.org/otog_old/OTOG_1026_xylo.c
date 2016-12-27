#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[3000]= {'\0'};
int chk[10];
int d[10];
int tran(char a)
{
    if(a=='D') return 0;
    else if(a=='R') return 1;
    else if(a=='M') return 2;
    else if(a=='F') return 3;
    else if(a=='S') return 4;
    else if(a=='L') return 5;
    else return 6;
}
char re_tran(int a)
{
    if(a==0) return 'D';
    else if(a==1) return 'R';
    else if(a==2) return 'M';
    else if(a==3) return 'F';
    else if(a==4) return 'S';
    else if(a==5) return 'L';
    else return 'T';
}
int is_one()
{
    int i;
    for(i=0; i<7; i++)
        if(chk[i]>0) return 1;
    return 0;
}
int main()
{
    int n,i,j,k,p,max,min;
    int len,num;
    scanf("%d\n",&n);

    for(k=0; k<n; k++)
    {
        p=0;
        num=0;
        for(i=0; i<7; i++) d[i]=0;
        scanf("%s",data);
        len=strlen(data);
        for(i=0; i<len; i++) d[tran(data[i])]++;
        if(len%7==0)
        {
            for(i=1; i<7; i++)
            {
                if(d[i]==d[0]) num++;
                else break;
            }
            if(num==6) {printf("YES MANY\n");continue;}
        }
        max=d[0];
        min=d[0];
        for(i=1; i<7; i++)
        {
            if(d[i]>max) max=d[i];
            if(d[i]<min) min=d[i];
        }
        for(i=0; i<7; i++) d[i]-=min;//// optimize
        max-=min;////
        for(j=0;j<7;j++)
        {
            if(d[j]==max)
            {
                for(i=0; i<7; i++) chk[i]=d[i];
                for(i=j; i<7; i=(i+1)%7)
                {
                    if(chk[i]==0)
                    {
                        if(is_one()==0) {p=1;printf("YES %c %c\n",re_tran(j),re_tran((6+i)%7));}
                        break;
                    }
                    else chk[i]--;
                }
            }
        }
        if(p==0) printf("NO\n");
    }
    return 0;
}
