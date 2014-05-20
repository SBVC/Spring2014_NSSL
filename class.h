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
		void encrypt(string input);
		void addData(string input);
		string getData();
		string decrypt();
		void printEncrypted();//dumb
		void printDecrypted();//dumb
		//static long generateKey();
		void generateKey();
		void setKey(long key);
		string getKey();
};

NSSL::NSSL(string input,long key){
	encrypt(input,key);
}
void NSSL::encrypt(string input,long key){
	setKey(key);
	encrypt(input);
}
void NSSL::encrypt(string input){
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
string NSSL::getData(){
    return encryptedData;
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
//long NSSL::generateKey(){
void NSSL::generateKey(){
	srand(time(NULL));
	long key=rand()*1254785104821482321;
	#ifdef DEBUG
	cout<<key<<endl;
	#endif // DEBUG
	//return key;
	setKey(key);
}
void NSSL::setKey(long key){
	ostringstream long2string;
	long2string<<key;
	dataKey=long2string.str();
}
string NSSL::getKey(){
	return dataKey;
}
