#include<iostream.h>
#include<vector>
#include<queue>
#include<stdlib.h>

using namespace std;

#define maxn 130
//struct ss Team[maxn];

int Capitales[maxn], N, M;
vector<int>A[100];

struct ss {
	int team;
	int numbers;
};//Team[130];

struct ss Team[130];

int com(const void *a, const void *b) {
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return y->numbers - x->numbers;
}

void Assi() {
	int i, j, k, t;
	qsort(Team,N,sizeof(ss),com);
	for(i = 0; i<N; i++) {
		t = Team[i].team;
		k = Team[i].numbers;
		for(j = 1; j<= M && k; j++) {
			if(!Capitales[j] ) continue;
			k --;
			A[t].push_back(j);
			Capitales[j] --;
		}
		if(k) {
			cout<<"0\n";
			return;
		}
	}
	cout<<"1\n";
	for(i = 1; i<= N; i++) {
		j = 0;
		for(k = 0; k<A[i].size(); k++){
			if(j++) cout<<" ";
			cout<<A[i][k];
		}
		cout<<endl;
	}
}

int main () {
	//freopen("h.txt","r",stdin);
	int i, n;
	while(cin>>N>>M) { 
		if(!N && !M) break;
		for(i = 0; i<N; i++) {
			cin>>Team[i].numbers;
			Team[i].team = i+1;
		}
		for(i = 1; i<= M; i++) 
			cin>>Capitales[i];
		Assi();
		for(i = 1; i<= N; i++)
			A[i].clear();

	}
}
