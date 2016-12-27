#include <stdio.h>
#include <stdlib.h>

int heap[300005]={0};//val >=1
int end=0;
void fixup(int k)
{
    int pr=(k-1)/2,temp;//pr=parent
    if(k!=0)//T = มีพ่อ
    {
        if(heap[k]>heap[pr])
        {
            temp = heap[k];
            heap[k]=heap[pr];
            heap[pr]=temp;
            fixup(pr);
        }
    }
}
void fixdown(int k)
{
    int temp;
    int lt=2*k+1;
    int rt=2*k+2;
    if(heap[lt]>heap[rt])//if no child heap[] จะเป็น 0 อยู่แล้วจึงไม่ต้องเขียนกรณีไม่มีลูก(เป็นไปตามกฎพ่อ>ลูก)
    {
        if(heap[k]<heap[lt])
        {
            temp = heap[k];
            heap[k]=heap[lt];
            heap[lt]=temp;
            fixdown(lt);
        }
    }
    else if(heap[k]<heap[rt])
    {
        temp = heap[k];
        heap[k]=heap[rt];
        heap[rt]=temp;
        fixdown(rt);
    }
}

void enqueue(int a)//a=val
{
    heap[end]=a;
    fixup(end);
    end++;
}
int dequeue()//dequeue index root
{
    int x;
    x=heap[0];
    end--;
    heap[0]=heap[end];
    heap[end]=0;
    fixdown(0);
    return x;
}
int main()
{
    int n,i;
    int val;
    char ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&ch);
        if(ch=='\n') scanf("%c",&ch);
        if(ch=='P') {scanf("%d",&val);enqueue(val);}
        else
        {
            if(end>0) printf("%d\n",dequeue());
            else printf("-1\n");
        }
    }
    return 0;
}
