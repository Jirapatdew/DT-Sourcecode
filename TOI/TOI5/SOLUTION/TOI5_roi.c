/*
TASK: ROI
LANG: C
AUTHOR: Jirapat Atiwattanachai
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double cost,var_cost[29],revenue[29][71],sellbook[29][71],price,profit[29][71],min[3]={0,0,100000};//revenue = �����,cost = �鹷ع�����,var_cost = �鹷ع�ѹ��,profit = ����,sellbook = �ӹǹ˹ѧ��ͷ������
    int n=-1,i,j;
    scanf("%lf",&cost);
    for(i=1000;i<=15000;i=i+500)
    {
        price=100-((i-1000)/500);//�Ҥҵ������
        var_cost[++n]=i*price;//��ҹ�ع�������(�ѹ��)
    }
    for(i=0;i<29;i++)
    {
       for(j=74;j<=144;j++)
       {
           sellbook[i][j-74]=((100-(0.8569*exp(0.09*(j-100))))*(1000+(i*500)))/100;//�ӹǹ˹ѧ��ͷ������  = ((100-(0.8569*e(0.09*D)))*�ӹǹ˹ѧ��ͷ������ )/100
           revenue[i][j-74]=sellbook[i][j-74]*j;//�����  = �ӹǹ˹ѧ��ͷ������ * �ҤҢ��˹ѧ��͵������
           profit[i][j-74]=revenue[i][j-74]-(var_cost[i]+cost);//���� = �����  � �����������
           if(profit[i][j-74]>0&&profit[i][j-74]<min[2])//�Ҥ�ҹ��·���ش
           {
               min[0]=i;
               min[1]=j;
               min[2]=profit[i][j-74];
           }
       }
    }
    printf("%d\n",(int)(1000+(min[0]*500)));
    printf("%d\n",(int)min[1]);
    printf("%.2f\n",min[2]);
    return 0;
}
/*double ����  scanf() ��ͧ�� "%lf" ������ printf() ����ö�� "%f"��*/
