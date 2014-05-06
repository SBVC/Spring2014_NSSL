//#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
using namespace std;

class secretData{
	protected:
		short dataKey;
		string encryptedData;
		int test;
	public:
		bool encrypt(string input,short key);
		void printEncryptedData();
		void printData();
		void generateKey();
		void setKey();
		void main();
};

void secretData::main{
	//This is the start of the program
	cout<<"Please enter 1 to generate a new key or 2 to enter your provided key:"<<endl;
	cout<<"# "; //prompt for input
	getline(cin,input);
	
	switch (input)
	case 1 : generateKey(); //this should call secretData::generateKey(); when 1 is entered
	case 2 : setKey(); //this should call secretData::setKey(); when 2 is entered
   	default   : main(); //this should call secretData::main(); when anything else is entered
}

short secretData::generateKey(){
	//code should generate a number between 1111 and 9999
	srand((unsigned)time(0)); 
	short random_integer; 
	short lowest=1111, highest=9999; 
	short range=(highest-lowest)+1; 
	random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
	dataKey = random_integer; //set dataKey to new random number
	cout << "Your new key is now: " dataKey << endl; //tell user the new number
	return null;
}

void secretData::setKey(){
	do {
		cout<<"Enter your key now:" << endl;
		cout<<"# "; //prompt for input
		getline(cin,input);

		if (input >= 1111 ) {
			if (input <= 9999) {
				test = 1;
			}
		}
		else {
		 cout<<"sorry your key is invalid. please try again!"
		 test = 0;
		}
	}while(test=0);
	dataKey=input;
	cout<<"key accepted"
	return = null;
	
}

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
