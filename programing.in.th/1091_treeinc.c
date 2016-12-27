#include <stdio.h>
#include <stdlib.h>
//use sort and dinamic by for i=1 to n
int list[300005]= {0};
int p_list[300005]= {0};
int val[300005]= {0};
int stack[300005][2]= {0};
int data[600005][2]= {0},p=1,num=0; //[0]=เมืองที่ [1]=link

void push(int a,int v)
{
    stack[num][0]=a;
    stack[num][1]=v;
    num++;
}
void pop()
{
    num--;
}
int is_emp()
{
    if(num==0) return 1;
    else return 0;
}
int main()
{
    int n,i,b,max=0,dt,a,v;
    scanf("%d",&n);
    for(i=1; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        data[p][0]=b;
        if(list[a]==0) list[a]=p;
        else data[p_list[a]][1]=p;
        p_list[a]=p;
        p++;
        data[p][0]=a;
        if(list[b]==0) list[b]=p;
        else data[p_list[b]][1]=p;
        p_list[b]=p;
        p++;
    }
    for(i=1; i<=n; i++)
    {
        if(list[i]>0)
        {
            push(i,1);
        }
        while(is_emp()==0)
        {
            pop();
            a=stack[num][0];
            v=stack[num][1];
            if(v>val[a])
            {
                val[a]=v;
                dt=list[a];
                while(dt>0)
                {
                    if(data[dt][0]>a) push(data[dt][0],v+1);
                    if(data[dt][1]==0) break;
                    else dt=data[dt][1];
                }
            }
        }
    }
    for(i=1; i<=n; i++) if(val[i]>max) max=val[i];
    printf("%d",max);

    return 0;
}
//ปล.code recursive ใช้ไม่ได้ ติด X 1 ตัว สาเหตุคือ stack overflow แก้โดยเขียน stack เอง
/*  int find(int a,int v)
    {
        int dt;
        if(v>val[a])
        {
            val[a]=v;
            dt=list[a];
            while(dt>0)
            {
                if(data[dt][0]>a) find(data[dt][0],v+1);
                if(data[dt][1]==0) return 0;
                else dt=data[dt][1];
            }
        }
        else return 0;
    }
    int main()
    {
        int n,i,a,b,max=0;
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            data[p][0]=b;
            if(list[a]==0) list[a]=p;
            else data[p_list[a]][1]=p;
            p_list[a]=p;
            p++;
            data[p][0]=a;
            if(list[b]==0) list[b]=p;
            else data[p_list[b]][1]=p;
            p_list[b]=p;
            p++;
        }
        for(i=1;i<=n;i++)
        {
            if(list[i]>0) find(i,1);//มีเมืองที่เชือม
        }
        for(i=1;i<=n;i++) if(val[i]>max) max=val[i];
        printf("%d",max);

        return 0;
    }*/
