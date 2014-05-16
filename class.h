//#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
using namespace std;

class secretData{
	protected:
		short dataKey;
		string encryptedData;
	public:
		bool encrypt(string input,short key);
		void printEncryptedData();
		void printData();
};

bool secretData::encrypt(string input,short key){
	dataKey=key; //save key before use
	encryptedData=input;
	for (int i=0;i<input.size();i++){
		encryptedData[i]^=key++;
		#ifdef DEBUGverbose
		cout<<"Char:"<<input[i]<<"\t"<<"Key:"<<key<<"\n";
		#endif // DEBUG
	}
	return true;
}

void secretData::printEncryptedData(){
	cout<<encryptedData<<endl;
}
void secretData::printData(){
	string tmp=encryptedData;
	short key=dataKey;
	for (int i=0;i<tmp.size();i++)
		tmp[i]^=key++;
	cout<<tmp<<endl;
}
