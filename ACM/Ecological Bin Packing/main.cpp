#include<iostream>
#include<stdio.h>

using namespace std;

int Binario[4][4];
int MIN;
char colors[] = "BCG";
char C[5];


void Calcular(int a, int b, int c) {
    int x = 0;
	x += Binario[1][a] + Binario[2][a];
	x += Binario[0][b] + Binario[2][b];
	x += Binario[0][c] + Binario[1][c];
	if(x < MIN){
		 MIN = x;
	     C[0] = colors[a];	 
		 C[1] = colors[b];
		 C[2] = colors[c];
	     C[3] = 0;
	}

}

int main() {
    int a,b,c,d,e,f,g,h,i;
	while(scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i) == 9) {
	   Binario[0][0] = a;
       Binario[0][2] = b;
       Binario[0][1] = c;
       Binario[1][0] = d;
       Binario[1][2] = e;
       Binario[1][1] = f;
	   Binario[2][0] = g;
       Binario[2][2] = h;
       Binario[2][1] = i;
	   MIN = 1000000000;
	   Calcular(0,1,2);
	   Calcular(0,2,1);
	   Calcular(1,0,2);
	   Calcular(1,2,0);
	   Calcular(2,0,1);
	   Calcular(2,1,0);
	   printf("%s %d\n",C,MIN);
	}
	system("PAUSE");
    return EXIT_SUCCESS;
}
