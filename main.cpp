#define DEBUG

#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "class.h"
using namespace std;

int main() {
	string input;
	//secretData text;
	//short key=0; //default key of zero
	long key=1337; //temporary, needs to be able to be specified or generated

	cout<<"Welcome to Secret Note program."<<endl;

	do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		//text.encrypt(input,key);
		NSSL data(input,key);
		#ifdef DEBUG
		data.printEncrypted();
		//data.printDecrypted();
		#endif // DEBUG
		//cout<<"  ";text.printEncryptedData(); //temporary
		//cout<<"  ";text.printData(); // temporary as well
	}while(input.length()!=0); //continue until null input

	#ifdef DEBUG
	cout<<"\n"<<endl;
	//system("pause"); //replaced with coded version cause Linux support
	cout<<"Press any key to continue . . . ";
	getch();
	#endif // DEBUG

	return 0;
}
