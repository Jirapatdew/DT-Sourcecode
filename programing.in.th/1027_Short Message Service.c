#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char vote[10001]= {'/0'};
    int i,s[7]={0},min=30001,n=0,point=-1,max=-1,j=0,n2=0;
    int len;
    while(1)
    {
        scanf("%s",vote);
        if(vote[0]=='!') break;
        else
        {
            len=strlen(vote);
            for(i=0; i<len; i++)
            {
                switch(vote[i])
                {
                case 'A':
                    if(s[0]>=0) ++s[0];
                    break;
                case 'B':
                    if(s[1]>=0) ++s[1];
                    break;
                case 'C':
                    if(s[2]>=0) ++s[2];
                    break;
                case 'D':
                    if(s[3]>=0) ++s[3];
                    break;
                case 'E':
                    if(s[4]>=0) ++s[4];
                    break;
                case 'F':
                    if(s[5]>=0) ++s[5];
                    break;
                case 'G':
                    if(s[6]>=0) ++s[6];
                    break;
                }
            }
            min=30001;
            for(i=0; i<7; i++) if(min>s[i]&&s[i]>=0) min=s[i];
            for(i=0; i<7; i++) if(min==s[i]&&s[i]>=0)
                {
                    ++n;
                    point=i;
                }
            if(n==1&&n2<6)
            {
                s[point]=-1;
                ++n2;
            }
            n=0;
        }
    }
    printf("%d",7-n2);
    for(j=0; j<7; j++)
    {
        max=-1;
        for(i=0; i<7; i++)
        {
            if(max<s[i]&&s[i]>=0)
            {
                max=s[i];
                point=i;
            }
        }
        if(point!=-1)
        {
            printf("\n%c %d",point+65,s[point]);
            s[point]=-1;
        }
        point=-1;
    }
    return 0;
}
