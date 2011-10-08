#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string code;
	while(cin>>code, code!="#")
	{
		int i=code.length()-1;
		while(i!=0)
		{
			if(code[i-1]<code[i])
				break;
			--i;
		}
		if(!i)
			cout<<"No tiene sucesor"<<endl;
		else
		{
			int j=0;
			for(j=i+1; j<code.length(); ++j)
				if(code[j]<=code[i-1])
					break;
			swap(code[j-1], code[i-1]);
			sort(code.begin()+i, code.end());
			cout<<code<<endl;
		}
	}
	return 0;
	//system("PAUSE");
    //return EXIT_SUCCESS;
}
