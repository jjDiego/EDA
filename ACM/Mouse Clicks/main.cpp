#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int contR,contI;
int rr=0; int ii=0; int mm=0;


struct region{
       int a,b,c,d;
}R[100];

struct icon{
       int e,f;
}I[100];

struct Mouse{
       int a,b;
}M[10000];


/*void Verify(){
     for(int i = 0; i < rr; i++){
                  if(R[i].a <= a && R[i].c >= a && R[i].b <= b && R[i].d >= b){
                            cout<<
                  }
     }
}*/

int main(int argc, char *argv[]){
    int a,b,c,d;
    
    char *ch;
    
    //cin>>r;
    scanf("%c ",ch);
    while(*ch != 'A'){
        //scanf("%c ",ch);
        
        if(*ch == 'R'){
              scanf("%d %d %d %d",&a,&b,&c,&d);
              //cout<<"a = "<<a<<endl;
              R[rr].a = a;
              R[rr].b = b;
              R[rr].c = c;
              R[rr].d = d;
              //cout<<"R[0].b = "<<R[rr].b<<endl;
              rr++;
              cout<<"rr = "<<rr<<endl;
              //cout<<"es Region"<<endl;
        }
        if(*ch == 'I'){
              scanf("%d %d",&a,&b);
              //cout<<"b = "<<b<<endl;
              I[ii].e = a;
              I[ii].f = b;
              //cout<<"I[0].b = "<<I[ii].f<<endl;
              ii++;
              cout<<"ii = "<<ii<<endl;
              //cout<<"es Icono"<<endl;
        }
        if(*ch == 'M'){
              //cout<<"b = "<<b<<endl;
              M[mm].a = a;
              M[mm].b = b;
              //cout<<"I[0].b = "<<I[ii].f<<endl;
              mm++;
              cout<<"mm = "<<mm<<endl;
              //cout<<"es Icono"<<endl;
        }
        //if(*ch == '#')continue;
        scanf("%c ",ch);
        if(*ch == 'A')break;
    }
    int tam = rr;
    if(tam < ii)tam = ii;
    for(int i = 0; i < tam; i++){
          if(R[rr-i].a <= M[i].a && R[rr-i].c >= M[i].a && R[rr-i].b <= M[i].b && R[rr-i].d >= M[i].b){
                    cout<<"Region"<<endl;
          }
          if(I[ii].e <= M[i].a && I[ii].f>= M[i].b){
                    cout<<"   Icon"<<endl;
          }
          
     }
    //else cout<< "Introduzca bien los datos"<<endl<<endl;*/
    //scanf("%d",&i);
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
