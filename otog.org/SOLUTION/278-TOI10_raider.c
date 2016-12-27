/*
TASK: Raider
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 400
#define MAX_COLUMN 400
#define QCAP 20000000
#define MAX_MOVE 100000
int r,c,sr,sc,tr,tc,marker=1;
int grid[MAX_ROW][MAX_COLUMN],passed[MAX_ROW][MAX_COLUMN];
typedef struct {
	int r,c,step;
} Position;
int qSize =0,qh = 0,qt = 0;
Position q[QCAP];
int enqueue(int nextR,int nextC,int nStep){
	if(nStep>MAX_MOVE){
		printf("over max step");
		return 1;
	}
	if(qSize>=QCAP-1){
		printf("OVERFLOW");
		return 1;
	}
	if(nextR==tr&&nextC==tc&&nStep%grid[nextR][nextC]==0){return 1;}
	if(nextR<0||nextR>=r||nextC<0||nextC>=c){
		return 0;//
	}
	else if(grid[nextR][nextC]!=0&&nStep%grid[nextR][nextC]==0&&(passed[nextR][nextC]<nStep||!marker)){
		Position temp;
		temp.r = nextR;
		temp.c = nextC;
		temp.step = nStep;
		q[qt]=temp;
		qt=(qt+1)%QCAP;
		qSize++;
		passed[nextR][nextC]=nStep;
		return 0;
	}//
	return 0;
}
Position dequeue(){
	Position temp =q[qh];
	qh=(qh+1)%QCAP;
	qSize--;
	return temp;
}
void preprocess(){
	int i,j;
	scanf("%d%d",&r,&c);
	sr = tr = r/2,sc = 0,tc = c-1;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&grid[i][j]);
			passed[i][j]=0;
		}
	}
	enqueue(sr,sc,1);
	enqueue(sr-1,sc,1);
	enqueue(sr+1,sc,1);
}
int main(){
	preprocess();
	Position temp;
	int isDone=0;
	while(qSize>0&&!isDone){
		temp = dequeue();
		if(temp.r%2!=0){
				isDone =enqueue(temp.r-1,temp.c,temp.step+1)||enqueue(temp.r+1,temp.c,temp.step+1)||
						enqueue(temp.r,temp.c+1,temp.step+1)||enqueue(temp.r-1,temp.c-1,temp.step+1)||
						enqueue(temp.r+1,temp.c-1,temp.step+1)||enqueue(temp.r,temp.c-1,temp.step+1);
		}
		else{
				isDone=	enqueue(temp.r,temp.c+1,temp.step+1)||enqueue(temp.r-1,temp.c+1,temp.step+1)||
						enqueue(temp.r+1,temp.c+1,temp.step+1)||enqueue(temp.r+1,temp.c,temp.step+1)||
						enqueue(temp.r-1,temp.c,temp.step+1)||enqueue(temp.r,temp.c-1,temp.step+1);
		}
	}
	if(isDone)
		printf("%d\n",temp.step+1);
	else
		printf("Imposible %d",temp.step);
	return 0;
}
