//#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NSSL{
	protected:
		string dataKey;
		string encryptedData;
	public:
		NSSL(){}
		NSSL(string input,long key);
		void encrypt(string input,long key);
		void addData(string input);
		string decrypt();
		void printEncrypted();
		void printDecrypted();
		static long generateKey();
};

NSSL::NSSL(string input,long key){
	encrypt(input,key);
}
void NSSL::encrypt(string input,long key){
	ostringstream long2string;
	long2string<<key;
	dataKey=long2string.str();
	encryptedData=input;
	for (int i=0;i<input.size();i++){
		for (int j=0;j<dataKey.size();j++){
			encryptedData[i]^=dataKey[j]^i;
			i++;
			if (i==input.size()) return;
		}
	}
}
void NSSL::addData(string input){
	encryptedData+=input;
}
string NSSL::decrypt(){
	string tmp=encryptedData;
	for (int i=0;i<encryptedData.size();i++){
		for (int j=0;j<dataKey.size();j++){
			tmp[i]^=dataKey[j]^i;
			i++;
			if (i==encryptedData.size()) return tmp;
		}
	}
	return tmp;
}
void NSSL::printEncrypted(){
	cout<<encryptedData<<endl;
}
void NSSL::printDecrypted(){
	cout<<decrypt()<<endl;
}
long NSSL::generateKey(){
	srand(time(NULL));
	long key=rand()*1254785104821482321;
	#ifdef DEBUG
	cout<<key<<endl;
	#endif // DEBUG
	return key;
}
