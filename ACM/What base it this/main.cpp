#include <cstdlib>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 38

using namespace std;

char abc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int val[200];
char X[MAXN],Y[MAXN];
char chr1[250],chr2[250];
int a,b;

long long elevar_a(int b, int p) {
   int i, j;
   long long k = 1;
   for(i = 1; i<=p; i ++)
     k *= b;
   return k;
}


struct ST {
      long long box;
      int bases;
} V[MAXN],W[MAXN];

int  MAX(char x[])  {
   int i,mx = 0,j;
   for(i = 0;x[i]; i++) {
     j = x[i];
     if(mx<val[j])
       mx = val[j];
   }
   if(mx == 0) mx = mx+1;
   return mx;

}

void get_val()  {
   int i,j;
   for(i = 0; abc[i]; i ++) {
     j = abc[i];
     val[j] = i;
   }
}



long long numero(char x[],int base) {

     int i,j,L,m,p = 0;
     long long sum = 0,f;
     L = strlen(x) - 1;
     for(i = L; i>=0; i --)  {
       j = x[i];
       m = val[j];
       f = elevar_a(base,p) * m;
       sum += f;
       p++;
    }
    return sum;
}


void base1(char x[])  {

	 int i,max;
	 a = 0;
	 max = MAX(x);
	 for(i = max+1; i<= 36; i ++) {
	    V[a].box = numero(x,i);
	    V[a].bases = i;
	    a ++;
	 }
}

void base2(char x[])  {
	 int i,max;
	 b = 0;
	 max = MAX(x);
	 for(i = max+1; i<= 36; i ++) {
	   W[b].box  = numero(x,i);
	   W[b].bases = i;
	   b ++;
	}

}

int comparar()  {

      int i,j;
      for(i = 0; i<a; i ++) {
	for(j = 0; j<b; j ++) {
	  if(V[i].box == W[j].box) {
	    cout<< chr1 << "(base " << V[i].bases << ") = "<<chr2<<" (base "<<W[j].bases<<")"<<endl;
	    return 1;
	  }
	 if(V[i].box < W[b].box) break;
       }
     }
     return 0;

}

int main()  {

      int i,j;
      get_val();
      while(scanf("%s%s",X,Y) != EOF) {
	    strcpy(chr1,X);
	    strcpy(chr2,Y);
	    base1(X);
	    base2(Y);
	    j = comparar();
	    if(j == 0)
	     cout<<chr1<<" is not equal to "<<chr2<<" in any base 2..36"<<endl;

	    for(i = 0; i<=36; i ++) {
	      V[i].box = 0;
	      V[i].bases = 0;
	      W[i].box = 0;
	      W[i].bases = 0;
	    }
      }
      system("PAUSE");
    return EXIT_SUCCESS;
}
