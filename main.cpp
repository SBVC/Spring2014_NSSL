#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	string line,data;
	int key=0; //default key of zero

	cout<<"Enter data to encrypt (hitting enter twice stops input):"<<endl;
	do {
		getline(cin,line);
		data+=line;
	}while(line.length()!=0);

	cout<<endl<<"Enter an key (integer) to encrypt with: ";
	cin>>key;
	#ifdef DEBUG
	cout<<"Key used: "<<key<<endl;
	#endif // DEBUG

	for (int i=0;i<data.size();i++) {
		data[i]^=key++;
		#ifdef DEBUGverbose
		cout<<"Char:"<<line[i]<<"\t"<<"Key:"<<key<<endl;
		#endif // DEBUG
	}

	cout<<endl<<"Your encrypted data:"<<endl<<endl;
	cout<<data;

	#ifdef DEBUG
	cout<<endl<<endl;
	system("pause");
	#endif // DEBUG

	return 0;
}
