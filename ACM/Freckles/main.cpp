#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAXN 4952

struct point{
	int x, y;
	double dis;
	int parent, rank;
}P[MAXN];

struct ss {
	double x, y;
}pp[101];

int N, M;

double dist(double x1, double y1, double x2, double y2) {
	double a, b;
	a = (x1 - x2);
	b = (y1 - y2);
	return sqrt(a*a + b*b);
}

int com(const void *a, const void *b) {
	point *p = ( point *)a;
	point *q = ( point *)b;
	if( p->dis > q->dis) return 1;
	else if(p->dis < q->dis) return -1;
	return 0;
}

int Find(int n) {
	if( n != P[n].parent)
		P[n].parent = Find(P[n].parent);
	return P[n].parent;
}

void Link(int x, int y) {
	if(P[x].rank > P[y].rank)
		P[y].parent = x;
	else {
		P[x].parent = y;
		if(P[x].rank == P[y].rank)
			P[y].rank++;
	}
}

double MST() {
	int i, x, y;
	double Sum = 0.0;
	qsort(P,M,sizeof(P[0]),com);
	for(i = 0; i<N; i++){
		P[i].rank = 0;
		P[i].parent = i;
	}
	for(i = 0; i<M; i++) {
		x = Find(P[i].x);
		y = Find(P[i].y);
		if(x != y) {
			Link(x,y);
			Sum += P[i].dis;
		}
	}
	return Sum;
}

void Cal() {
	int i, j;
	double dis;
	M = 0;
	for(i = 0; i<N-1; i++) {
		for(j = i+1; j<N; j++) {
			dis = dist(pp[i].x,pp[i].y,pp[j].x,pp[j].y);
			P[M].dis = dis;
			P[M].x = i;
			P[M++].y = j;
		}
	}
	printf("%.2lf\n",MST());
}

int main() {
    int kase, i;
	
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d",&N);
		for(i = 0; i<N; i++)
			scanf("%lf%lf",&pp[i].x,&pp[i].y);
		Cal();
		if(kase) printf("\n");

	}

}
