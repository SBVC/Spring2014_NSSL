#include <string>
#include <bitset>
#include <iostream>
using namespace std;

int main() {
	string in;
	int key;
	string out;

	cout<<"Enter some text to encryptify or decryptify."<<endl;
	getline(cin,in);
	out=in;
	cout<<"Enter a key to use (integer): ";
	cin>>key;

	for (int i=0;i<in.size();i++) {
		key++;
		out[i]=in[i]^key;
	}

	cout<<"Your encryptified text:"<<endl<<endl;
	cout<<out<<endl<<endl;

	system("pause");
	return 0;
}