/*
TASK: Cat Code
LANG: C++
AUTHOR: PeaTT~
*/
#include<cstdio>
#include<string>
using namespace std;
#define Hash 500009
#define HashSize 1<<19

int CatCode[1<<19],Code[1<<17],L,M,N,O,mask;
char data[1<<20];
bool used[1<<17];

void InHash(int num, int order){
    int now = num%Hash;
    int next = 1;
    while(CatCode[now]!=0){
        now += next;
        next <<= 1;
        now %= HashSize;
    }
    CatCode[now] = order;
    Code[order-1] = num;
}

int FindHash(int num){
    int now = num%Hash;
    int next = 1;
    while(CatCode[now]!=0){
        if(Code[CatCode[now]-1]==num)
            break;
        now += next;
        next <<= 1;
        now %= HashSize;
    }
    return CatCode[now];
}

int calnum(int from, int to){
    int sum, j;
    sum = data[from] - '0';
    for(j=from+1;j<to;j++){
        sum <<= 1;
        sum += (data[j]-'0');
    }
    return sum;
}

int recal(int next,int num){
    int now = num;
    now <<= 1;
    now &= mask;
    now += (data[next]-'0');
    return now;
}

void Show(bool result){
    if(result){
        for(int i=1;i<=L;i++){
            if(used[i])
                printf("%d ", i);
        }
        printf("\n");
    }
    else{
        printf("OK\n");
    }
}

int main(){
    int i,j,now,temp;
    bool result;
    scanf("%d%d ",&L,&M);
    mask = 1<<M;
    mask--;
    for(i=0;i<L;i++){
        gets(data);
        InHash(calnum(0,M), i+1);
    }
    scanf("%d",&N);
    for(j=0;j<N;j++){
        scanf("%d ", &O);
        gets(data);
        for(i=0;i<=L;i++){
            used[i] = false;
        }
        result = false;
        now = calnum(0,M-1);
        for(i=0;i<=(O-M);i++){
            now = recal(i+M-1,now);
            temp = FindHash(now);
            if(temp > 0){
                used[temp] = true;
                result = true;
            }
        }
        Show(result);
    }
	return 0;
}
