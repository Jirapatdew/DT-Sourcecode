/*
TASK: Map
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 1000
#define MAX_COLUMN 1000
typedef struct partial{
	struct partial *direction[4];
	int idx;
} Part;
typedef struct{int r,c;} Coordinate;
Part relationGraph[MAX_ROW*MAX_COLUMN];
Part map[MAX_ROW][MAX_COLUMN];
int nr,nc,maxR,minR,maxC,minC;
/*
direction
	1
2		0
	3
*/
void countDirection(Part* current,int fromDirection,Coordinate currentCoor){
	int i;
	if(current==NULL) return;
	switch(fromDirection){
		case 0: currentCoor.c -=1; break;
		case 1: currentCoor.r +=1; break;
		case 2: currentCoor.c +=1; break;
		case 3: currentCoor.r -=1; break;
	}
	if(currentCoor.c>maxC) maxC = currentCoor.c;
	if(currentCoor.c<minC) minC = currentCoor.c;
	if(currentCoor.r>maxR) maxR = currentCoor.r;
	if(currentCoor.r<minR) minR = currentCoor.r;
	for(i=0;i<4;i++){
		if(i!=fromDirection){
			countDirection(current->direction[i],(i+2)%4,currentCoor);
		}
	}
}
void fillMap(Part* current,int fromDirection,Coordinate currentCoor){
	int i;
	if(current==NULL) return;
	switch(fromDirection){
		case 0: currentCoor.c -=1; break;
		case 1: currentCoor.r +=1; break;
		case 2: currentCoor.c +=1; break;
		case 3: currentCoor.r -=1; break;
	}
	map[currentCoor.r][currentCoor.c] = *current;
	for(i=0;i<4;i++){
		if(i!=fromDirection){
			fillMap(current->direction[i],(i+2)%4,currentCoor);
		}
	}
}
int main(){
	int i,j,a,b;
	char direction[2];
	scanf("%d%d",&nr,&nc);
	for(i=0;i<nr*nc;i++){
		for(j=0;j<4;j++){
			relationGraph[i].direction[j]=NULL;
		}
		relationGraph[i].idx = i;
	}
	//input and construct tree (or graph)
	for(i=0;i<nr*nc-1;i++){
		scanf("%d%s%d",&a,direction,&b);
		if(direction[0]=='U'){
			 relationGraph[a].direction[3] = &relationGraph[b];
			 relationGraph[b].direction[1] = &relationGraph[a];
		}
		else{
			relationGraph[a].direction[0] = &relationGraph[b];
			relationGraph[b].direction[2] = &relationGraph[a];
		}
	}
	//traverse in a tree to find coodinate of reference node (relationGraph[0])
	Coordinate currentCoor;
	currentCoor.r=currentCoor.c = 0;
	for(i=0;i<4;i++){
		countDirection(relationGraph[0].direction[i],(i+2)%4,currentCoor);
	}
	currentCoor.r=-minR;
	currentCoor.c=-minC;
	map[-minR][-minC]=relationGraph[0];
	//put linked tree in table
	for(i=0;i<4;i++){
		fillMap(relationGraph[0].direction[i],(i+2)%4,currentCoor);
	}
	for(i=0;i<nr;i++){
		for(j=0;j<nc;j++)
			printf("%d ",map[i][j].idx);
		printf("\n");
	}
	return 0;
}
