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
        void encrypt(string input,long key);
        string decrypt();
        void printEncrypted();
        void printDecrypted();
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
    cout<<"  "<<encryptedData<<endl;
}
void NSSL::printDecrypted(){
    cout<<"  "<<decrypt()<<endl;
}
