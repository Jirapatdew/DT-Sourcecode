#include <stdio.h>

using namespace std;

int main()
{
    int b[101]={0};
    for(int i=0;i<30;i++) scanf("%d",&b[i]);
    if(b[0]%2==0)
    {
        if(b[1]%2==0)
        {
            if(b[2]%2==0)
            {
                if(b[3]%2==0) printf("yes");//1Y
                else printf("no");//1N
            }
            else printf("yes");//1Y
        }
        else
        {
            if(b[2]%2==0) printf("yes");//1Y
            else printf("no");//1N
        }
    }
    else
    {
        if(b[1]%2==0)
        {
            if(b[2]%2==0) printf("no");//1N
            else printf("yes");//1Y
        }
        else
        {
            if(b[2]%2==0) printf("yes");//2Y
            else printf("no");//1N
        }
    }
    return 0;
}

