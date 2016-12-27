//แบบถึก >> ข้อนี้หมิกได้
#include<stdio.h>
int main()
{
    int a[2501],n,sum,i,j,max = 0,begin,end;
    scanf("%d",&n);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (i=1; i<=n; i++)
    {
        sum = a[i];
        for (j=i+1; j<=n; j++)
        {
            sum = sum+a[j];
            if (sum > 0)
            {
                if (sum > max)
                {
                    max = sum;
                    begin = i;
                    end = j ;
                }
            }
        }
    }
    if (max == 0) printf("Empty sequence");
    else
    {
        for (i=begin; i<=end; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n%d",max);
    }

    return 0;
}

