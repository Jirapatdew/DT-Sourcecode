#include <stdio.h>
#include <stdlib.h>

int a[200005][5]= {0};
int p=0;
void check(int k)
{
    int x=0,y=0,z=-1,temp0,temp1;
    if(2*k+1<p&&a[k][0]>a[2*k+1][0]&&2*k+2<p&&a[k][0]>a[2*k+2][0])
    {
        x=a[k][0]-a[2*k+1][0];
        y=a[k][0]-a[2*k+2][0];
        if(x>y) z=1;
        else z=2;
    }
    else if(2*k+1<p&&a[k][0]>a[2*k+1][0]) z=1;
    else if(2*k+2<p&&a[k][0]>a[2*k+2][0]) z=2;
    if(z>0)
    {
        temp0=a[k][0];
        temp1=a[k][1];
        a[k][0]=a[2*k+z][0];
        a[k][1]=a[2*k+z][1];
        a[2*k+z][0]=temp0;
        a[2*k+z][1]=temp1;
        check(2*k+z);
    }


}
void sort(int k)
{
    printf("%d\n",a[0][1]);
    a[0][0]=a[k][0];
    a[0][1]=a[k][1];
    check(0);

}
void heap(int k)
{
    int temp0,temp1;
    if(k>0)
    {
        if(a[(k-1)/2][0]>a[k][0])
        {
            temp0=a[k][0];
            temp1=a[k][1];
            a[k][0]=a[(k-1)/2][0];
            a[k][1]=a[(k-1)/2][1];
            a[(k-1)/2][0]=temp0;
            a[(k-1)/2][1]=temp1;
            heap((k-1)/2);
        }
    }
}
int main()
{
    int m,n,d,temp0,temp1;
    int i,y=-1;
    int ans[200005];
    char x;
    scanf("%d%d",&n,&m);
    d=m+n;
    for(i=0; i<d; i++)
    {
        scanf(" %c",&x);
        if(x=='T')
        {
            scanf("%d%d",&a[p][0],&a[p][1]);
            p++;
            heap(p-1);
        }
        else if(x=='P')
        {
            if(p>0)
            {
                p--;
                sort(p);
            }
            else
            {
                printf("0\n");
            }
        }
    }
    for(i=0; i<=y; i++) printf("%d\n",ans[i]);
    return 0;
}

