#define DEBUG

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	string line;
	int key;

	cout<<"Enter a line to encrypt:"<<endl;
	getline(cin,line);

	cout<<endl<<"Enter an key (integer) to encrypt with: ";
	cin>>key;

	for (int i=0;i<line.size();i++)
		line[i]^=key++;

	cout<<endl<<"Your encrypted line:"<<endl<<endl;
	cout<<line;

	#ifdef DEBUG
	cout<<endl<<endl;
	system("pause");
	#endif

	return 0;
}
