//#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class NSSL{
    protected:
        string dataKey;
        string encryptedData;
    public:
        NSSL(string input,long key);
        bool encrypt(string input,long key);
        string decrypt();
        bool printEncrypted();
        bool printDecrypted();
};

NSSL::NSSL(string input,long key){
    encrypt(input,key);
}
bool NSSL::encrypt(string input,long key){
    ostringstream long2string;
    long2string<<key;
    dataKey=long2string.str();
    //dataKey = static_cast<ostringstream*>( &(ostream() << key) )->str();
    for (int i=0;i<input.length();i++){
        for (int j=0;j<dataKey.length();j++){
            encryptedData[i]^=dataKey[j];
            i++;
            if (i==input.length()) return true;
        }
    }
    return true;
}
string NSSL::decrypt(){
    string tmp;
    for (int i=0;i<encryptedData.length();i++){
        for (int j=0;j<dataKey.length();j++){
            tmp[i]^=dataKey[j];
            i++;
            if (i==encryptedData.length()) return tmp;
        }
    }
    return tmp;
}
bool NSSL::printEncrypted(){
    cout<<encryptedData;
    return true;
}
bool NSSL::printDecrypted(){
    cout<<"totally not broked";
    //cout<<decrypt();
    return true;
}

//below here is old
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
