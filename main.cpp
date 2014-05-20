#define DEBUG

#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "class.h"
#include <fstream>
using namespace std;

int main();
bool openFileAndDecrypt(string filename,NSSL data);

int main() {
	char in;
	string input,text,filename;
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
				cout<<"Your key is: "<<data.getKey()<<"\n";
				in='0';
				break;
			case 'e': case 'E':
				cout<<"Enter your key: ";
				cin>>key; //can you pipe straight into a function? replace this with that if possible
				//cin>>data.setKey(); //or//data.setKey(cin); //??
				data.setKey(key);
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
				//flush cin here?
				//cin.clear(); cin.ignore(100000,'\n');
				getline(cin,filename);
				if (openFileAndDecrypt(filename,data)) {
					in='0';}
				else {
					goto neverUseLabelsAndGotos;
				}
				break;
			case 'e': case 'E':
				//make ending done with "/done" on a line by itself instead of an empty line
				//prompt (as below) for text until empty message,
				//then encrypt and output to a file
				cout<<"Enter text to be encrypted: (type /done on a line by itself to exit)"<<endl;
				//input="something"; //to keep it from somehow being /done already (this isn't needed)
				do {
                    cout<<"# ";
                    getline(cin,input); //does this give newlines?
                    if (input=="/done") break;
                    text+=input+"\n";
				}while(input!="/done"); //change to true
				data.encrypt(text);
				//now save it to file
				cout<<"Encrypted. ";
            labelsAreReallyBad:
                cout<<"Enter filename to output to: ";
                //flush cin here as well most likely
                //cin.clear(); cin.ignore(100000,'\n');
				getline(cin,filename);
				{ofstream file(filename.c_str());
				if (file.is_open()){
                    file<<data.getData();
                    file.close();
                    cout<<"Output complete.\n";
				} else {
				    cout<<"File error: Could not open file.";
				    goto labelsAreReallyBad;
				}}
				//display message about finished
				in='0';
				break;
			default:
				/*do nothing actually*/;
		}
	}while(in!='0');

	cout/*<<"\n\n"*/<<"Press any key to exit . . . "<<endl;
	getch();

	//THIS IS EXIT OF PROGRAM, REMOVE BELOW WHEN IT HAS BEEN ADDED TO APPROPRIATE PLACE

	/*do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		NSSL data(input,key);

		#ifdef DEBUG
		cout<<"  "; data.printEncrypted();
		cout<<"  "; data.printDecrypted();
		#endif // DEBUG

	}while(input.size()!=0); //continue until null input*/

	return 0;
}

bool openFileAndDecrypt(string filename,NSSL data){
	string line;
	ifstream file(filename.c_str());
	if (file.is_open()){
		while(getline(file,line)){
			data.addData(line+"\n"); //this may need a +"\n" added to it to work properly
		}
		file.close();
		//decrypt and display
		data.printDecrypted();
		return true;
	}
	cout<<"Error: File did not open."<<endl;
	return false;
}
