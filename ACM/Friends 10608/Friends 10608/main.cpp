#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

map<int,int> rango;
map<int,int> amigos;

void makeset(int x)
{
	amigos[x] = x;
	rango[x] = 0;
}

int find_set(int x)
{
    if(x != amigos[x])
        amigos[x] = find_set(amigos[x]);

    return amigos[x];
}

void union_set(int x, int y)
{
    int A = find_set(x), B = find_set(y);

    if(rango[A] > rango[B])
        amigos[B] = A;
    else
        amigos[A] = B;

    if(rango[A] == rango[B])
        rango[B] = rango[B] + 1;
}

int main()
{
    int t, N, M, A, B;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> N >> M;
        for(int j = 1; j <= N; j++)
            makeset(j);
        for(int j = 0; j < M; j++)
        {
            cin >> A >> B;
            union_set(A,B);
        }

        int* set = new int[N+1];
        for(int j = 1; j <= N; j++)
            set[j] = 0;

        for(int j = 1; j <= N; j++)
            set[find_set(j)]++;

        int max = 0;
        for(int j = 1; j <= N; j++)
        {
            if(set[j] > max)
                max = set[j];
        }
        cout << max << endl;
    }
	return 0;
}
