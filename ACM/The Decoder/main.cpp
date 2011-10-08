#include<stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file;
    char ch;
    int d;
    file.open("file.txt");
    while(file.good()){
         ch = file.get();
         d=ch;
         if(d==10){
             printf("\n");
             continue;
         }
         printf("%c",d-7);
    }
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
 }

