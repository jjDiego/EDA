/*
144
Student Grant
*/
#include<stdio.h>

int N, K, P;
int S[30];
void Cal() {
	int i, m = 0, d, c = 0;
	int rem = 0;
	while(1) {
		for(i = 1; i<= N; i++) {
			if(S[i] == -1) continue;
			if(rem == 0) {
				d = (m++)%K+1;
				if(S[i] + d >= 40) {
					printf("%3d",i);
					c++;
					if(c == N) return;
					rem = (S[i] + d) - 40;
					S[i] = -1;
				}
				else 
					S[i] += d;
				
				m %= K;
			}
			else {
				if(S[i] + rem >=40) {
					printf("%3d",i);
					c++;
					if(c == N) return;
					rem = (S[i] + rem) - 40;
					S[i] = -1;
				}
				else{
					S[i] += rem;
					rem = 0;
				}
			}

		}
	}
}

int main() {
	while(scanf("%d%d",&N,&K) == 2) {
		if(!N && !K) break;
		Cal();
		putchar('\n');
		for(int i = 1; i<= N; i++) S[i] = 0;
	}
	return 0;
}

