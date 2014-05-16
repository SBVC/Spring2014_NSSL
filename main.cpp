#define DEBUG
//#define DEBUGverbose


#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "class.h"
//#include <ctime>
using namespace std;

int main() {
	string input;
	long key=1337; //need to make keygen, steal Patrick's code
	//secretData text;
	//NSSL data;

	cout<<"Welcome to Secret Note program."<<endl;
	//secretData sd;
	//sd.main();

	//this is where we would connect to a server/client or whatever
	//cout<<"Enter a key for this communication: "; //this will be changed probably
	//cin>>key; //this is a horrible way to get input but whatever

	do {
		cout<<"# ";
		//cin>>input;
		getline(cin,input);
		data.encrypt(input,key);

        //#ifdef DEBUG
		data.printEncrypted();
		data.printDecrypted();
		//#endif

	}while(input.length()!=0);

	//#ifdef DEBUG
	cout<<"\n"<<endl;
	//system("pause"); // doesn't work in Linux needs fix
	cout<<"Press any key to continue . . . ";
	getchar();	cout<<"\b";
	//#endif

	return 0;
}
