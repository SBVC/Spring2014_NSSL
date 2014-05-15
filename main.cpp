#define DEBUG
//#define DEBUGverbose


#include <iostream>
#include <cstdlib>
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
		cin>>input;
		//data=NSSL(input,key);
		NSSL(input,key);
		//
	}while(input.length()!=true);

	#ifdef DEBUG
	cout<<endl<<endl;
	system("pause"); // doesn't work in Linux needs fix
	#endif // DEBUG

	return 0;
}
