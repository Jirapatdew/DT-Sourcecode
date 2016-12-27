/*
TASK: Monkey
LANG: C++
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <stdlib.h>
#define mx(a,b) ((a>b)?a:b)
struct z{
	int p,h;
}a[1000010];
int cmp(const void *p,const void *q)
{
	z *a=(z*)p,*b=(z*)q;
	if(a->h>b->h) return 1;
	if(a->h<b->h) return -1;
	if(a->p>b->p) return 1;
	return -1;
}
int v[200010];
int main()
{
	int m,n,k,i,p,q,h,now,coll,maxx=0,tmp;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=0;i<k;i++){
		scanf("%d %d",&p,&h);
		a[i].p=p; a[i].h=h;
	}
	qsort(a,k,sizeof(a[0]),cmp);
	for(i=k-1;i>=0;i--){
		p=a[i].p; q=p+1;
		tmp=v[p]; v[p]=v[q]; v[q]=tmp;
	}
	scanf("%d",&now);
	coll=v[now];
	for(i=0;i<k;i++){
		p=a[i].p; q=a[i].p+1;
		if(i>0&&a[i-1].h==a[i].h&&now-1==a[i-1].p+1&&now>1) maxx=mx(maxx,v[now-2]);
		else maxx=mx(maxx,v[now-1]);
		maxx=mx(maxx,v[now+1]);
		if(p==now) now=q;
		else if(q==now) now=p;
		tmp=v[p]; v[p]=v[q]; v[q]=tmp;
	}
	if(maxx>coll) printf("%d\nUSE\n",maxx);
	else printf("%d\nNO\n",coll);
	return 0;
}
