#include<stdio.h>
#define maxn 102

int Prime[maxn], totalPrime;
char Fg[maxn];

void Seive() {
	int i, j;
	for(i = 2; i<maxn;) {
		for( j = i + i; j<maxn; j += i)
			Fg[j] = 1;
		for(i++; Fg[i]; i++);
	}
	Prime[0] = 2;
	totalPrime = 1;
	for(i = 3; i<maxn; i++) {
		if(Fg[i] == 0) {
			Prime[totalPrime++] = i;
		}
	}

}

int getFact(int n, int p) {
	int sum = 0, i, j;
	for(i = p; i<=n; i *= p){
		sum += n/i;
	}
	return sum;
}

void Cal(int n) {
	int count = 0, i, k, first = 1;
	char ss[] = " ";
	printf("%3d! =",n);
	for(i = 0; i<totalPrime && Prime[i] <= n; i++ ) {
		k = getFact(n,Prime[i]);
		if(count % 15 == 0) {

			if(first ) {
				printf("%3d",k);
				first = 0;
			}else {
				printf("\n");
				printf("%6s",ss);
				printf("%3d",k);
			}

		}else {
				printf("%3d",k);
		}
		count++;
		
	}
	printf("\n");
}
int main() {
	int n;
	Seive();
	//freopen("in.txt","w",stdin);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n) && n) {
		Cal(n);
	}
	return 0;
}
