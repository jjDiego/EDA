#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>

using namespace std;

const int NUM = 1000;
const int num = 125;

int first[num], second[num];

void init()
{
     for(int i = 97; i < 123; i++)
     {
         first[i] = 0;
         second[i] = 0;
     }
}


int main(int argc, char *argv[])
{
    int length;
    char a[NUM],b[NUM];
    while(cin.getline(a,NUM,'\n') && cin.getline(b,NUM,'\n'))
    {
        init();

        length = strlen(a);
        for(int i = 0; i < length; i++)
            first[a[i]]++;

        length = strlen(b);
        for(int i = 0; i < length; i++)
            second[b[i]]++;

        for(int i = 97; i < 123; i++)
        {
            if(first[i] >= second[i] && second[i] > 0)
            {
                for(int j = 0; j < second[i]; j++)
                    cout << char(i);
            }
            if(second[i] > first[i] && first[i] > 0)
            {
                for(int j = 0; j < first[i]; j++)
                    cout << char(i);
            }
        }
        cout << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
