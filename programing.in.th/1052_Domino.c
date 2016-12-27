#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,max=0,j,num=0,s,ch;
    char d;
    int xi[100001];
    int hi[100001];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&xi[i],&hi[i]);

    s=0;
    num=1;
    ch=xi[0]+hi[0];
    for(i=1;i<n;i++) //right
    {
       if(xi[i]<ch)
       {
           num++;
           if(ch<xi[i]+hi[i]) ch=xi[i]+hi[i];
       }
       else
       {
            if(max<num) {max=num;j=s;d='R';}
            s=i;
            num=1;
            ch=xi[i]+hi[i];
       }
    }
    if(max<num) {max=num;j=s;d='R';}

    s=n-1;
    num=1;
    ch=xi[n-1]-hi[n-1];
    for(i=n-2;i>=0;i--) //left
    {
       if(xi[i]>ch)
       {
           num++;
           if(ch>xi[i]-hi[i]) ch=xi[i]-hi[i];
       }
       else
       {
            if(max<num||(max==num&&s<=j)) {max=num;j=s;d='L';}
            s=i;
            num=1;
            ch=xi[i]-hi[i];
       }
    }
    if(max<num||(max==num&&s<=j)) {max=num;j=s;d='L';}

    printf("%d %c",j+1,d);
    return 0;
}
