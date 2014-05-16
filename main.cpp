#define DEBUG

#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "class.h"
using namespace std;

int main() {
    char in;
	string input;
	long key=1337;

	cout<<"Welcome to Secret Note program."<<endl;

	do {
        cout<<"(G)enerate a key or (E)nter a key?"<<endl;
        in=getch();
        switch(in){
            case 'g': case 'G':
                key=NSSL::generateKey();
                in='0';
                break;
            case 'e': case 'E':
                //prompt for key, set key
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
                //open a file, decrypt it with the key we have
                break;
            case 'e': case 'E':
                //prompt (as below) for text until empty message,
                //then encrypt and output to a file
                break;
            default:
                /*do nothing actually*/;
        }
	}while(true);

	do {
		cout<<"# "; //prompt for input
		getline(cin,input);

		NSSL data(input,key);

		#ifdef DEBUG
		data.printEncrypted();
		data.printDecrypted();
		#endif // DEBUG

	}while(input.length()!=0); //continue until null input

	#ifdef DEBUG
	cout<<"\n"<<endl;
	//system("pause"); //replaced with coded version cause Linux support
	cout<<"Press any key to continue . . . ";
	getch();
	#endif // DEBUG

	return 0;
}
