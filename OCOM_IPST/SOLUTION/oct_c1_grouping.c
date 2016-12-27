#include <stdio.h>
#include <stdlib.h>

int p=0,dt=0;
int check(int a[],int k,int n)
{
    int x=1,sum=a[0],i;
    for(i=1;i<n;i++)
    {
        if(sum+a[i]>k)
        {
            sum=a[i];
            x++;
        }
        else sum+=a[i];
    }
    return x;
}
int binary(int a[],int low,int high,int key,int n)
{
    int mid=(low+high)/2;
    int x=0;
    if(low<=high)
    {
        x=check(a,mid,n);
        if(x<key&&p==0) binary(a,low,mid-1,key,n);
        else if(x>key&&p==0) binary(a,mid+1,high,key,n);
        else if(p==0&&x==key)
        {
            p=1;
            dt=mid;
            binary(a,mid,high,key,n);
        }
        else if(x<key&&p==1) binary(a,low,mid-1,key,n);
        else if(p==1&&x==key)
        {
            dt=mid;
            if(low!=high) binary(a,mid+1,high,key,n);
        }
    }
}
int main()
{
    int n,m,a[10005],maxa=0,maxk=0,sum=0,avg=0,i;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(maxa<a[i]) maxa=a[i];
        sum+=a[i];
    }
    maxk=2000000000;
    binary(a,maxa,maxk,m,n);
    if(p==1)printf("%d",dt);
    else printf("IMPOSSIBLE");
    return 0;
}
    //avg=sum/n;
    //maxk=sum+avg;
