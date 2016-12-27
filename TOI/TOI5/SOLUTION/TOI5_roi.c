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
    double cost,var_cost[29],revenue[29][71],sellbook[29][71],price,profit[29][71],min[3]={0,0,100000};//revenue = รายได้,cost = ต้นทุนคงที่,var_cost = ต้นทุนผันแปร,profit = กำไร,sellbook = จำนวนหนังสือที่ขายได้
    int n=-1,i,j;
    scanf("%lf",&cost);
    for(i=1000;i<=15000;i=i+500)
    {
        price=100-((i-1000)/500);//ราคาต่อเล่ม
        var_cost[++n]=i*price;//ต้านทุนที่พิมพ์(ผันแปร)
    }
    for(i=0;i<29;i++)
    {
       for(j=74;j<=144;j++)
       {
           sellbook[i][j-74]=((100-(0.8569*exp(0.09*(j-100))))*(1000+(i*500)))/100;//จำนวนหนังสือที่ขายได้  = ((100-(0.8569*e(0.09*D)))*จำนวนหนังสือที่พิมพ์ )/100
           revenue[i][j-74]=sellbook[i][j-74]*j;//รายได้  = จำนวนหนังสือที่ขายได้ * ราคาขายหนังสือต่อเล่ม
           profit[i][j-74]=revenue[i][j-74]-(var_cost[i]+cost);//กำไร = รายได้  – ค่าใช้จ่ายรวม
           if(profit[i][j-74]>0&&profit[i][j-74]<min[2])//หาค่าน้อยที่สุด
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
/*double เวลา  scanf() ต้องใช้ "%lf" แต่เวลา printf() สามารถใช้ "%f"ได้*/
