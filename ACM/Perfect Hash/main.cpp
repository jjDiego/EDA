#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN(a, b) (a>b?b:a)

int W[15], tw;
char str[200];


int dif(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}


int Valores(char ss[]) {
	int i, j, k = 1, d = 0, l;
	l = strlen(ss);
	for(i = l-1; i>=0; i--) {
		j = ss[i] - 'a' + 1;
		d += j*k;
		k *= 32;
	}
	return d;
}

void Insertar() {
	char *p;
	tw = 0;
	p = strtok(str," ");
	while(p) {
		W[tw++] = Valores(p);
		p = strtok(NULL, " ");
	}
}

int Solver(int n) {
	int i, j, x, y;
	for(i = 0; i+1<tw; i++) {
		for(j = i+1; j<tw; j++){
			x = n/W[i];
			y = n/W[j];
			x = x%tw;
			y = y%tw;
			if(x == y) return 1;
		}
	}
	return 0;
}

int Next(int n) {
	int i, j, max = -1000000, x, p, q;
	for(i = 0; i+1<tw; i++) {
		for(j = i+1; j<tw; j++) {
			p = (n/W[i]) % tw;
			q = (n/W[j]) % tw;
			if(q != p) continue;
			x = MIN( ((n/W[i])+1)*W[i] , ((n/W[j])+1)*W[j] );
			if(x> max) max = x;
		}
	}
	return max;
}

void Calcular() {
	int min, ok;
	qsort(W,tw,sizeof(int),dif);
	min = W[0];
	ok = Solver(min);
	while(ok) {
		min = Next(min);
		ok = Solver(min);
	}
	printf("%d\n\n",min);
}

int main() {
	//freopen("c:\\h.txt","r",stdin);
	while(gets(str)) {
		puts(str);
		Insertar();
		Calcular();
	}
	/*system("PAUSE");
    return EXIT_SUCCESS;*/
}
