/*
The Postal Worker Rings Onece
117
*/
#include<stdio.h>
#include<string.h>

#define MAXN 100000
#define INF 21474836

int Link[30][30];
char st[MAXN];
int F[30];

void Ini(){
	int i, j;
	for(i = 0; i<27; i++) {
		for(j = 0; j<30; j++) 
			Link[i][j] = INF;
		Link[i][i] = 0;
	}
}


void Floyd() {
	int k , i , j, m;
	for(k = 0; k<27; k ++) {
		for(i = 0; i<27; i++) 
			for(j = 0; j<27; j++){
				m = Link[i][k]+Link[k][j];
				Link[i][j] = Link[i][j]>m ? m:Link[i][j];
			}
	}
}


void Cal(int sum) {
	int i, od1 = -1, od2 = -1;
	for(i = 0; i<30; i++)
		if(F[i] % 2) break;
	od1 = i;
	for(i = 29; i>=0; i--)
		if(F[i] % 2) break;
	od2 = i;
	if(od1 <0 && od2<0 ) {
		printf("%d\n",sum);
		return;
	}
	Floyd();
	printf("%d\n",sum+Link[od1][od2]);
		
}


int main() {
	int u, v, l, sum;
	while(scanf("%s",st) != EOF) {
		Ini();
		sum = 0;
		u = st[0] - 'a';
		l = strlen(st);
		sum += l;
		v = st[l-1] - 'a';
		Link[u][v] = Link[v][u] = l;
		F[u] ++;
		F[v] ++;
		while(1) {
			scanf("%s",st);
			if(!strcmp(st, "deadend"))
				break;
			u = st[0] - 'a';
			l = strlen(st);
			v = st[l-1] - 'a';
			Link[u][v] = Link[v][u] = l;
			sum += l;
			F[u] ++;
			F[v] ++;
		}
		Cal(sum);
		for(int i = 0; i<30; i++) F[i] = 0;

	}
	return 0;
}

