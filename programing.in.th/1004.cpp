#include<stdio.h>
#define SIZE 10000

struct student
{
    int c;
    int s;
};

struct student plate[SIZE];
struct queue
{
    int c;
    int s;
};

struct queue que[SIZE];
int main()
{
    char command='A';
    char free;
    int ns,nc,index=0,first,i,j,k,id,top=0,exit[SIZE];
    scanf("%d%d",&nc,&ns);
    for(j=0; j<ns; j++)
        scanf("%d%d",&plate[j].c,&plate[j].s);
    scanf("%c",&free);
    while(command!='X')
    {
        scanf("%c",&command);
        if(command=='D')
        {
            if((first>=0)&&(first<index))
            {
                exit[top]=que[first].s;
                que[first].s=0;
                que[first].c=0;
                first++;
                top++;
            }
            scanf("%c",&free);
        }
        else if(command=='E')
        {
            scanf("%d",&id);
            j=0;
            while(id!=plate[j].s)
                j++;
            if(index!=0)
            {
                if(plate[j].c!=que[index-1].c)
                {
                    i=index-2;
                    while((plate[j].c!=que[i].c)&&(i>=first))
                        i--;
                    if(plate[j].c==que[i].c)
                    {
                        k=index;
                        index++;
                        while(k-1>i)
                        {
                            que[k].c=que[k-1].c;
                            que[k].s=que[k-1].s;
                            k--;
                        }
                        que[k].c=plate[j].c;
                        que[k].s=id;
                    }
                    else
                    {
                        que[index].c=plate[j].c;
                        que[index].s=id;
                        index++;
                    }
                }
                else
                {
                    que[index].c=plate[j].c;
                    que[index].s=id;
                    index++;
                }
            }
            else
            {
                que[index].c=plate[j].c;
                que[index].s=id;
                index++;
                first=0;
            }
            scanf("%c",&free);
        }
    }
    for(j=0; j<top; j++)
        printf("%d\n",exit[j]);
    printf("0\n");
    return 0;
}
