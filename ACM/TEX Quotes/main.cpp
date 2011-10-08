#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

char text[1000000];

int main(){
    char c;
    ifstream infile;
    infile.open ("test.txt");
    
    int i,j = 0;
    
    if (infile.is_open()){
        while (infile.good()){
              c = infile.get();
               if(c =='"') {
                          j ++;
                          if(j % 2 != 0)printf("``");
                          else printf("''");
               }
	           else printf("%c",c);
        }
      infile.close();
   }
   else{cout << "Error opening file";}
   printf("\n");
   system("PAUSE");
   return EXIT_SUCCESS;
}
