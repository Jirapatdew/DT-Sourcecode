#include <stdio.h>

using namespace std;

int main()
{
    int a[101]={0},b[101]={0};
    for(int i=0;i<30;i++)
    {
        scanf("%d",&b[i]);
    }
    if(b[0]%2==0)
    {
        if(b[2]%2==0)
        {
            if(b[3]%2==0) printf("no");
            else printf("yes");
        }
        else printf("yes");
    }
    else
    {
        if(b[1]%2==0)
        {
            if(b[2]%2==0) printf("yes");
            else
            {
                if(b[3]%2==0)
                {
                    if(b[4]%2==0) printf("no");
                    else printf("yes");
                }
                else
                {
                    if(b[0]%3==1) printf("no");
                    else printf("yes");
                }
            }
        }
        else
        {
            if(b[2]%2==0) printf("no");
            else printf("yes");
        }
    }
    return 0;
}
//-P--P-P-PP a[i]>2&&b[0]%3==1
//P--P-PP--- b[4]%2==0
//--PPP----- b[3]%2==0
//P--P-P---P b[2]%2==0
//PPP-PP-P-- b[1]%2==0
//PP-PP----P b[0]%2==0
//--PPP----- b[3]%2==0
