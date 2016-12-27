#include <stdio.h>
#include <stdlib.h>

int queue[20005]={0};
int p=0,st=0;
int q_empty()
{
    if(p==st) return 1;
    else return 0;
}
void enqueue(int a)
{
    queue[p]=a;
    p++;
}
int dequeue()
{
    st++;
    return queue[st-1];
}
int main()
{
    long long total=0;
    int i,m,n,x,j,tmp;
    int emp;
    int rate[105]= {0};
    int weight[20005]= {0};
    int garage[105]= {0};
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++) scanf("%d",&rate[i]);
    for(i=0; i<m; i++) scanf("%d",&weight[i]);
    emp=n;
    for(i=0; i<2*m; i++)
    {
        scanf("%d",&x);
        if(x>0)
        {
            if(emp>0)
            {
                for(j=0; j<n; j++)
                {
                    if(garage[j]==0)
                    {
                        garage[j]=x;
                        emp--;
                        break;
                    }
                }
            }
            else enqueue(x);
        }
        else
        {
            x*=-1;
            for(j=0; j<n; j++)
            {
                if(garage[j]==x)
                {
                    garage[j]=0;
                    tmp=j;
                    emp++;
                    total+=(long long)rate[j]*(long long)weight[x-1];
                    break;
                }
            }
            while(q_empty()==0&&emp>0)
            {
                x=dequeue();
                garage[tmp]=x;
                emp--;
            }
        }
    }
    printf("%d",total);
    return 0;
}
