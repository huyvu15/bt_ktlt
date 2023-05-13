// 1.6: code menu
#include<iostream>

using namespace std;

int main(){
	int n;
	char input;
	do{
		cout<<"Menu: "<<endl;
		cout<<"1. Chon 1"<<endl;
		cout<<"2. Chon 2"<<endl;
		cout<<"...."<<endl;
		cout<<"n. Chon n"<<endl;
		cin>>input;
		
		if (isdigit(input)) {
			n = input - '0';
            cout << "Da chon " << n << endl<<endl;
        } else {
            break;
		}
	}while(1);
	
	return 0;
}
