//#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
class secretData{
	protected:
		long dataKey;
		short key;
		string encryptedData;
		int test;
		int input;
		string unencryptedData;
	public:
		bool encrypt(string input,long dataKey);
		void printEncryptedData();
		void printData();
		void generateKey();
		void setKey();
		void main();
		void choose();
		void encryptMessage();
		void decrypt();
};

void secretData::main(){
	//This is the start of the program
	cout<<"Please enter 1 to generate a new key or 2 to enter your provided key:"<<endl;
	cout<<"# "; //prompt for input
	cin >> input;
	
	switch (input)
	{
	case 1 : generateKey(); //this should call secretData::generateKey(); when 1 is entered
		break;
	case 2 : setKey(); //this should call secretData::setKey(); when 2 is entered
		break;
   	default   : main(); //this should call secretData::main(); when anything else is entered
	}
}

void secretData::choose(){
	//This is the start of the program
	cout<<"Please enter 1 to encrypt a new message or 2 to decrypt a past message"<<endl;
	cout<<"# "; //prompt for input
	cin >> input;
	
	switch (input)
	{
	case 1 : encryptMessage(); //this should call secretData::encryptMessage(); when 1 is entered
		break;
	case 2 : decrypt(); //this should call secretData::decrypt(); when 2 is entered
		break;
   	default   : choose(); //this should call secretData::main(); when anything else is entered
	}
}
void secretData::decrypt() {
  string line;
  ifstream myfile ("example.txt");
  encryptedData = "";
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
      encryptedData += line;
	}
    myfile.close();
  }
  else cout << "Unable to open file"; 
  encrypt(encryptedData,dataKey);
  cout << encryptedData << endl;
}

void secretData::generateKey(){
	//code should generate a number between 1111 and 9999
	srand((unsigned)time(0)); 
	short random_integer; 
	short lowest=1111, highest=9999; 
	short range=(highest-lowest)+1; 
	random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
	key = random_integer; //set dataKey to new random number
	dataKey=(key * 1254785104821482321); 
	cout << "Your new key is now: " << key << endl; //tell user the new number
	cout << "Your real key is: " << dataKey << endl;
	encryptMessage();
}

void secretData::encryptMessage(){
	cout<<"Please enter your secret message."<<endl;
	cout<<"# "; //prompt for input
	cin >> unencryptedData;
	encrypt(unencryptedData,dataKey);
	cout << encryptedData << endl;
	//cout << "test" << endl;
	//encrypt(encryptedData,dataKey);
	//cout << encryptedData << endl;

  ofstream myfile;
  myfile.open ("example.txt");
  myfile << encryptedData; //<< "<<= \n The key is " << dataKey;
  myfile.close();
}
void secretData::setKey(){
	do {
		cout<<"Enter your key now:" << endl;
		cout<<"# "; //prompt for input
		cin >>input;

		if (input >= 1111 ) {
			if (input <= 9999) {
				test = 1;
			}
		}
		else {
		 cout<<"sorry your key is invalid. please try again!";
		 test = 0;
		}
	}while(test=0);
	key=input;
	dataKey=(key * 1254785104821482321); 
	cout<<"key accepted";
	choose();
}

bool secretData::encrypt(string input,long dataKey){
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
/*
string secretData::encrypt(){
	do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		text.encrypt(input,key);
		cout<<"  ";text.printEncryptedData(); //temporary
		cout<<"  ";text.printData(); // temporary as well
	}while(input.length()!=0); //continue until null input
	}*/