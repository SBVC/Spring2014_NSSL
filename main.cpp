#define DEBUG
//#define DEBUGverbose


#include <iostream>
#include <cstdlib>
#include "class.h"
#include <ctime>
using namespace std;

int main() {
	string input;
	secretData text;
	short key=0; //default key of zero

	cout<<"Welcome to Secret Note program."<<endl;
	secretData sd;
	sd.main();
	
	//this is where we would connect to a server/client or whatever
	//cout<<"Enter a key for this communication: "; //this will be changed probably
	//cin>>key; //this is a horrible way to get input but whatever

	#ifdef DEBUG
	cout<<endl<<endl;
	system("pause");
	#endif // DEBUG

	return 0;
}
