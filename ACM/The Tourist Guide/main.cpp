#include<stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

long n,R,C1,C2,P,W[100][100],s,d,t;

long min(long x,long y){
     long mi;
     if(x<y) mi=x;
     else mi=y;
     return mi;
}

long max(long x,long y){
     long mx;
     if(x>y)  mx=x;
     else  mx=y;
     return mx;
}


void F_W(){
     long k,i,j;
     for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
                W[i][j]=max(W[i][j],min(W[i][k],W[k][j]));
}

int main(){
    long i,j,mod,count=0,div=0,mutex=0;
    freopen("viajes.txt","r",stdin);
    while(1){
             scanf("%ld %ld",&n,&R);
             if(n<=0&&R<=0) break;
             else if(count)printf("\n\n");
             for(i=1;i<=n;i++)
             for(j=1;j<=n;j++)
                 W[i][j]=0;
             for(i=1;i<=R;i++){
                               scanf("%ld %ld %ld",&C1,&C2,&P);
                               if((C1<1&&C1>n)||C2<1&&C2>n||P<1){
                                                                 mutex=1;
                                                                 break;
                               }
             W[C1][C2]=P;
             W[C2][C1]=P;
             }
    if(mutex)
    break;
    F_W();
    scanf("%ld %ld %ld",&s,&d,&t);
    mod=t%(W[s][d]-1);
    div=t/(W[s][d]-1);
    if(count!=0)
    printf("\n");
    printf("Scenario #%ld\n",++count);
    if(mod==0)
    printf("Minimum Number of Trips = %ld\n",div);
    else
    printf("Minimum Number of Trips = %ld\n",++div);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
