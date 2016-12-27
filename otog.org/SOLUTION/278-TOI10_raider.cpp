
/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
queue<int> qX,qY,step;
int data[115][115]= {0},temp[115][115]={0};
int main()
{
    int m,n,posX,posY,X,Y,walk;
    scanf("%d%d",&m,&n);
    for(X=1; X<=m; X++)
    {
        for(Y=1; Y<=n; Y++)
        {
            scanf("%d",&data[X][Y]);
        }
    }
    if(data[((m-1)/2)][1]==1)
    {
        qX.push(((m-1)/2));
        qY.push(1);
        step.push(1);
    }
    if(data[((m-1)/2)+1][1]==1)
    {
        qX.push(((m-1)/2)+1);
        qY.push(1);
        step.push(1);
    }
    if(data[((m-1)/2)+2][1]==1)
    {
        qX.push(((m-1)/2)+2);
        qY.push(1);
        step.push(1);
    }
    while(not qX.empty())
    {
        posX=qX.front();
        posY=qY.front();
        walk=step.front();
        qX.pop();
        qY.pop();
        step.pop();
        if(posX==((m-1)/2)+1&&posY==n)
        {
            printf("%d",walk);
            break;
        }
        walk++;
        if(posX%2==0)
        {
            if(data[posX][posY-1]!=0&&walk%data[posX][posY-1]==0&&walk!=temp[posX][posY-1])
            {
                qX.push(posX);
                qY.push(posY-1);
                step.push(walk);
                temp[posX][posY-1]=walk;
            }
            if(data[posX-1][posY-1]!=0&&walk%data[posX-1][posY-1]==0&&walk!=temp[posX-1][posY-1])
            {
                qX.push(posX-1);
                qY.push(posY-1);
                step.push(walk);
                temp[posX-1][posY-1]=walk;
            }
            if(data[posX-1][posY]!=0&&walk%data[posX-1][posY]==0&&walk!=temp[posX-1][posY])
            {
                qX.push(posX-1);
                qY.push(posY);
                step.push(walk);
                temp[posX-1][posY]=walk;
            }
            if(data[posX+1][posY]!=0&&walk%data[posX+1][posY]==0&&walk!=temp[posX+1][posY])
            {
                qX.push(posX+1);
                qY.push(posY);
                step.push(walk);
                temp[posX+1][posY]=walk;
            }
            if(data[posX][posY+1]!=0&&walk%data[posX][posY+1]==0&&walk!=temp[posX][posY+1])
            {
                qX.push(posX);
                qY.push(posY+1);
                step.push(walk);
                temp[posX][posY+1]=walk;
            }
            if(data[posX+1][posY-1]!=0&&walk%data[posX+1][posY-1]==0&&walk!=temp[posX+1][posY-1])
            {
                qX.push(posX+1);
                qY.push(posY-1);
                step.push(walk);
                temp[posX+1][posY-1]=walk;
            }
        }
        else
        {
            if(data[posX][posY-1]!=0&&walk%data[posX][posY-1]==0&&walk!=temp[posX][posY-1])
            {
                qX.push(posX);
                qY.push(posY-1);
                step.push(walk);
                temp[posX][posY-1]=walk;
            }
            if(data[posX-1][posY]!=0&&walk%data[posX-1][posY]==0&&walk!=temp[posX-1][posY])
            {
                qX.push(posX-1);
                qY.push(posY);
                step.push(walk);
                temp[posX-1][posY]=walk;
            }
            if(data[posX-1][posY+1]!=0&&walk%data[posX-1][posY+1]==0&&walk!=temp[posX-1][posY+1])
            {
                qX.push(posX-1);
                qY.push(posY+1);
                step.push(walk);
                temp[posX-1][posY+1]=walk;
            }
            if(data[posX][posY+1]!=0&&walk%data[posX][posY+1]==0&&walk!=temp[posX][posY+1])
            {
                qX.push(posX);
                qY.push(posY+1);
                step.push(walk);
                temp[posX][posY+1]=walk;
            }
            if(data[posX+1][posY+1]!=0&&walk%data[posX+1][posY+1]==0&&walk!=temp[posX+1][posY+1])
            {
                qX.push(posX+1);
                qY.push(posY+1);
                step.push(walk);
                temp[posX+1][posY+1]=walk;
            }
            if(data[posX+1][posY]!=0&&walk%data[posX+1][posY]==0&&walk!=temp[posX+1][posY])
            {
                qX.push(posX+1);
                qY.push(posY);
                step.push(walk);
                temp[posX+1][posY]=walk;
            }
        }
    }
    return 0;
}

