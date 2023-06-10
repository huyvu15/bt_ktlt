// so nguyen to cung nhau
#include<iostream>

using namespace std;

int Euclid(int m, int n){
	if( m < 0 || n < 0){
		cout<<"Data unexpected";
		return -1;	
	}else{
	int r = m;
	if(m < n){
		r = m;
		m = n;
		n = r;
	}
	while(n!=0){
		r = m % n ;
		m = n;
		n = r;
	  }
	  return m;
	}	
}

bool NTcungnhau(int a, int b){
	int m;
	m = Euclid(a, b);
	if(m == 1){
		return true;
	}
	return false;
}

int main(){
	int a, b;
	cout<<"Nhap 2 so a, b:";
	cin>>a>>b;
	cout<<boolalpha<<endl;
	if(NTcungnhau(a, b)){
		cout<<"Co nguyen to cung nhau";
	}else{
		cout<<"Khong nguyen to cung nhau";
	}
	
	return 0;
}
