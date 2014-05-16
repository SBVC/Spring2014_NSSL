#define DEBUG
//#define DEBUGverbose

#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "class.h"
using namespace std;

int main() {
	string input;
	secretData text;
	short key=0; //default key of zero

	cout<<"Welcome to Secret Note program."<<endl;

	//this is where we would connect to a server/client or whatever
	//cout<<"Enter a key for this communication: "; //this will be changed probably
	//cin>>key; //this is a horrible way to get input but whatever

	do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		text.encrypt(input,key);
		NSSL data(input,key);
		cout<<"  ";text.printEncryptedData(); //temporary
		cout<<"  ";text.printData(); // temporary as well
	}while(input.length()!=0); //continue until null input

	#ifdef DEBUG
	cout<<"\n"<<endl;
	//system("pause"); //replaced with coded version cause Linux support
	cout<<"Press any key to continue . . . ";
	getch();
	#endif // DEBUG

	return 0;
}
