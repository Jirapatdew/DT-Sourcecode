#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,m,i,j,k,b=0,c=3,x[12][6][7],a=1;
    scanf("%d%d",&d,&m);
    for(i=0; i<12; i++)
        for(j=0; j<6; j++)
            for(k=b; k<7; k++) x[i][j][k]=-1;
    for(i=0; i<12; i++)
    {
        b=c;
        for(j=0; j<6; j++)
        {
            for(k=b; k<7; k++)
            {
                if(i==1)
                {
                    if(a==29) continue;
                    c=k+1;
                    x[i][j][k]=a;
                    ++a;
                }
                else if(i==3||i==5||i==8||i==10)
                {
                    if(a==31) continue;
                    c=k+1;
                    x[i][j][k]=a;
                    ++a;
                }
                else
                {
                    if(a==32) continue;
                    c=k+1;
                    x[i][j][k]=a;
                    ++a;
                }
            }
            b=0;
        }
        a=1;
    }
    for(j=0; j<6; j++)

        for(k=0; k<7; k++)

            if(d==x[m-1][j][k])
            {
                if(k==0) printf("Monday");
                else if(k==1) printf("Tuesday");
                else if(k==2) printf("Wednesday");
                else if(k==3) printf("Thursday");
                else if(k==4) printf("Friday");
                else if(k==5) printf("Saturday");
                else if(k==6) printf("Sunday");
            }
    return 0;
}
