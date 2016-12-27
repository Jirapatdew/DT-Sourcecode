#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,i=0,v=0,x=0,l=0,c=0,j;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        if(j/100>0) c+=(j/100);
        if(j%100>=90&&j%100<=99)
        {
            ++x;
            ++c;
        }
        else if(j%100>=40&&j%100<=49)
        {
            ++x;
            ++l;
        }
        a=(j/10)-((j/100)*10);
        if(a==5) ++l;
        else if(a==1) x+=1;
        else if(a==2) x+=2;
        else if(a==3) x+=3;
        else if(a==6)
        {
            x+=1;
            l+=1;
        }
        else if(a==7)
        {
            x+=2;
            l+=1;
        }
        else if(a==8)
        {
            x+=3;
            l+=1;
        }

        if(j%10==9)
        {
            ++i;
            ++x;
        }
        else if(j%10==4)
        {
            ++i;
            ++v;
        }
        a=j%10;
        if(a==5) ++v;
        else if(a==1) i+=1;
        else if(a==2) i+=2;
        else if(a==3) i+=3;
        else if(a==6)
        {
            i+=1;
            v+=1;
        }
        else if(a==7)
        {
            i+=2;
            v+=1;
        }
        else if(a==8)
        {
            i+=3;
            v+=1;
        }
    }
    printf("%d %d %d %d %d",i,v,x,l,c);
    return 0;
}
