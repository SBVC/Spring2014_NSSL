#define DEBUG

#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "class.h"
#include <fstream>
using namespace std;

int main();
bool openFileAndDecrypt(string filename);

int main() {
	char in;
	string input;
	string filename;
	long key;

	NSSL data;

	cout<<"Welcome to Secret Note program."<<endl;

	do {
		//this is ugly and should be rewritten better
		cout<<"(G)enerate a key or (E)nter a key?"<<endl;
		in=getch();
		switch(in){
			case 'g': case 'G':
				data.generateKey();
				cout<<"Your key is: "<<key<<"\n";
				in='0';
				break;
			case 'e': case 'E':
				cout<<"Enter your key: ";
				cin>>key;
				in='0';
				break;
			case '0':
				in='n'; //something other than 0 to keep user from skipping
			default:
				/*do nothing actually*/;
		}
	}while(in!='0');

	do {
		cout<<"(D)ecrypt from file or (E)ncrypt to file? [0 to exit]"<<endl;
		in=getch();
		switch(in){
			case 'd': case 'D':
				neverUseLabelsAndGotos:
				cout<<"Enter file name: ";
				getline(cin,filename);
				if (openFileAndDecrypt(filename)) {
					in='0';}
				else {
					goto neverUseLabelsAndGotos;
				}
				break;
			case 'e': case 'E':
				//make ending done with "/done" on a line by itself instead of an empty line
				//prompt (as below) for text until empty message,
				//then encrypt and output to a file
				in='0';
				break;
			default:
				/*do nothing actually*/;
		}
	}while(in!='0');

	cout<<"\n\n"<<"Press any key to exit . . . "<<endl;
	getch();

	//THIS IS EXIT OF PROGRAM, REMOVE BELOW WHEN IT HAS BEEN ADDED TO APPROPRIATE PLACE

	do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		NSSL data(input,key);

		#ifdef DEBUG
		cout<<"  "; data.printEncrypted();
		cout<<"  "; data.printDecrypted();
		#endif // DEBUG

	}while(input.size()!=0); //continue until null input

	return 0;
}

bool openFileAndDecrypt(string filename){
	NSSL data("blah",123); //this is bullshit
	//this assumes data is defined and accessible to it
	//it probably is neither, rewrite class to allow constructing uninitialized object
	//make data at beginning and accessible to everything
	string line;
	ifstream file(filename.c_str());
	//ifstream file;
	//file.open(filename);
	//ifstream file("test.txt");
	if (file.is_open()){
		while(getline(file,line)){
			//add to encrypted data
			data.addData(line); //this may need a +"\n" added to it to work properly
		}
		file.close();
		//decrypt and display
		data.printDecrypted();
		return true;
	}
	cout<<"Error: File did not open."<<endl;
	return false;
}
