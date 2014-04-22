#include <string>
#include <iostream>
using namespace std;

class data{
	protected:
		string data;
	public:
		int encrypt(string input,int key);
};

int data::encrypt(string input,int key){
	for (int i=0;i<input.size();i++){
		data[i]^=key++;
		#ifdef DEBUGverbose
		cout<<"Char:"<<input[i]<<"\t"<<"Key:"<<key<<"\n";
		#endif // DEBUG
	}
}
