#include<stdio.h>
#include<iostream>


using namespace std;


int B, Max, In, Ed;
int Dg[60], st[2100], rank[60], pp[60];
int link[60][60];
char F[60];

struct ss {
	int u, v;
}ed[1002];

void Set(int min) {
	int i;
	for(i = min; i<= Max; i++) {
		rank[i] = 0;
		pp[i] = i;
	}
}

int Find(int n) {
	if(pp[n] != n) 
		pp[n] = Find(pp[n]);
	return pp[n];
}

void Link(int x, int y) {
	if(rank[x]>rank[y])
		pp[y] = x;
	else {
		pp[x] = y;
		if(rank[y]>rank[x])
			rank[y]++;
	}
}

void Recur(int n, int s) {
	int i;
	for(i = s; i<= Max; i++) {
		if(link[n][i]) {
			link[n][i]--;
			link[i][n]--;
			Recur(i,s);
		}
	}
	st[In++] = n;
}

int IsConnected(int min) {
	int i, tn = 0, x, y;
	Set(min);
	for(i = min; i<= Max; i++) {
		if(F[i]) tn++;
	}
	for(i = 0; i<Ed; i++) {
		x = Find(ed[i].u);
		y = Find(ed[i].v);
		if(x != y){
			Link(x,y);
			tn --;
		}
	}
	if(tn > 1) return 0;
	return 1;
}


void Cal(int min) {
	int i;
	for(i = min; i<= Max; i++) {
		if(Dg[i] % 2) {
			cout<<"algunos granos se perderian"<<endl;
			return;
		}
	}
	if(!IsConnected(min)) {
		cout<<"algunos granos se perderian"<<endl;
			return;
	}
	In = 0;
	Recur(min,min);
	for(i = 0; i<In-1; i++) cout<<st[i]<<" "<<st[i+1]<<endl;
}

void Free(int min) {
	int i, j;
	for(i = min; i<= Max; i++) {
		Dg[i] = 0;
		F[i]  = 0;
		for(j = min; j<= Max; j++)
		link[i][j] = 0;
	}

}

int main() {
	int i, u, v, min;
	int kase, k = 0;
	scanf("%d",&kase);
	while(kase--) {
		Max = Ed = 0;
		min = 100;
		scanf("%d",&B);
		for(i = 0; i<B; i++) {
			scanf("%d%d",&u,&v);
			ed[Ed].u = u;
			ed[Ed++].v = v;
			F[u] = F[v] = 1;
			if(u>Max) Max = u;
			if(v>Max) Max = v;
			if(min>u) min = u;
			if(min>v) min = v;
			link[u][v] ++;
			link[v][u] ++;
			Dg[u]++;
			Dg[v]++;
		}
		if(k++>0) printf("\n");
		cout<<endl;
		cout<<"Caso "<<k<<endl;;
		Cal(min);
		Free(min);
		cout<<endl;
	}
	cout<<endl;
	system("PAUSE");
	return 0;
	
    //return EXIT_SUCCESS;
}
