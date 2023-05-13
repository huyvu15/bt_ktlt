// kiem tra so nguyen to
#include<iostream>

using namespace std;

bool testSNT(int a){
	if(a < 2){
		return false;
	}
	for(int i = 2; i< a; i++){
		if(a%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int a;
	cout<<"enter a number: ";
	cin>>a;
	cout<<boolalpha; //in ra true or false thay vi 1, 0
	if(testSNT(a)){
		cout<<"La so nguyen to";
	}else{
		cout<<"Khong la so nguyen to";
	}

	return 0;
}
