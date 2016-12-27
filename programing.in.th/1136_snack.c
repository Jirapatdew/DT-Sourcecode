#include <stdio.h>
#include <stdlib.h>

int main()
{
    int one[1000005]= {0};
    int two[1000005]= {0};
    int a,b,aa,bb,i,pa=0,pb=0,pass;
    long long a_sum=0,b_sum=0,a_bar,b_bar,total=0;
    scanf("%d%d",&a,&b);
    for(i=0; i<a; i++)
    {
        scanf("%d",&one[i]);
        a_sum+=one[i];
    }
    for(i=0; i<b; i++)
    {
        scanf("%d",&two[i]);
        b_sum+=two[i];
    }
    a_bar=a_sum/a;
    if(a_sum%a!=0) a_bar++;
    b_bar=b_sum/b;
    if(b_sum%b!=0) b_bar++;
    aa=a;
    bb=b;
    while(1)
    {
        pass=0;
        if(a_bar>=b_bar)
        {
            if(aa==1) break;
            for(i=pa; i<a; i++)
            {
                if((b_sum%b!=0&&b_bar<=one[i]&&one[i]<a_bar)||(b_sum%b==0&&b_bar<one[i]&&one[i]<a_bar))
                {
                        aa--;bb++;
                        b_sum+=one[i];a_sum-=one[i];
                        a_bar=a_sum/aa; if(a_sum%aa!=0) a_bar++;
                        b_bar=b_sum/bb; if(b_sum%bb!=0) b_bar++;
                        pa=i+1;total++;pass=1;
                        break;
                }
            }

        }
        if(a_bar<=b_bar)
        {
            if(bb==1) break;
            for(i=pb; i<b; i++)
            {
                if((a_sum%a!=0&&a_bar<=two[i]&&two[i]<b_bar)||(a_sum%a==0&&a_bar<two[i]&&two[i]<b_bar))
                {
                        aa++;bb--;
                        a_sum+=two[i];b_sum-=two[i];
                        a_bar=a_sum/aa; if(a_sum%aa!=0) a_bar++;
                        b_bar=b_sum/bb; if(b_sum%bb!=0) b_bar++;
                        pb=i+1;total++;pass=1;
                        break;
                }
            }
        }
        if(pass==0) break;
    }
    printf("%lld",total);
    return 0;
}
