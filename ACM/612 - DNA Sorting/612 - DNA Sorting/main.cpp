#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int calc_measure(string str)  
{  
    int sum = 0;  
    int i, j, len = (int)str.length();  
  
    for(i=1; i<len; i++) {  
        j = i;  
        while((j>0) && (str[j]<str[j-1])) {  
            swap(str[j], str[j-1]);  
            j--;  
            sum++;  
        }  
    }  
  
    return sum;  
} 


bool cmp (pair<string,int> x, pair<string,int> y)
{
    if ( x.second < y.second ) return true;
    return false;
}

int main ()
{
	pair<string, int> par;
    int testCase;
    scanf ("%d", &testCase);
    bool blank = false;
	string str;
	vector<pair<string,int>> a;

    while ( testCase-- ) {
        int n, m;
        scanf ("%d %d", &n, &m);

        for ( int i = 0; i < m; i++ ) {
		cin >> str;
		par.first = str;
		par.second = calc_measure(par.first);
		a.push_back(par);
		//cout << a[i].first << endl;
    }
		
		//partial_sort(a.begin(),a.end(),a.end(),cmp);
        stable_sort(a.begin(),a.end(),cmp);
		if ( blank ) printf ("\n");
        blank = true;

        for ( int i = 0; i < m; i++ )
           cout << a[i].first << endl;
    }

	return 0;
}
