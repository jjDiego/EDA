 #include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 using namespace std;
 
 bool esMayor(char c){return c>='A' && c<='Z';}
 bool esMenor(char c){return c>='a' && c<='z';}
 char setMenor(char c){return (esMayor(c))?(c+32):c;}
 char setMayor(char c){return (esMenor(c))?(c-32):c;}
 
 string encode(string s) {
 	string res = "";
	for(int i =0 ; i < s.size(); i++){
 		if (esMayor(s[i])) {
 			res += (s[i]-'A'+1)*2;
 		}
 		else if (esMenor(s[i])) {
 			res += (s[i]-'a'+1)*2+1;
 		}
 	}
 	return res;
 }
 
 string decode(string s) {
	string res = "";
	for (int i=0; i<s.size(); i++){
 		if (s[i]%2==0) {
		res += (s[i]/2)+'A'-1;
 		}
 		else {
 			res += (s[i]-1)/2 + 'a'-1;
 		}
 	}
 	return res;
 }

 int main() {
	int _t;
	scanf("%d", &_t); _t;
 	string s;
 	while (_t--) {
 		cin >> s;
 		s = encode(s);
 		sort(s.begin(), s.end());
 		do {
 			string t = decode(s);
 			printf("%s\n", t.c_str());
 		}while (next_permutation(s.begin(), s.end()));
 	}
 	return 0;
 }