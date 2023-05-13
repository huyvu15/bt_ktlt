// Phan so toi gian

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

int kiemtraphanso(int a, int b){
	int k ;
	
	k = Euclid(a, b);
	
	int m = a;
	int n = b;
	
	a = a / k;
	b = b / k;
	if( m = a && n == b){
		cout<<"Phan so da toi gian";
	}else{
	cout<< "Phan so chua toi gian"<<endl;
	cout<< "Phan so toi gian: " << a << "/" << b << endl;	
    }
	return a, b; 
}

int main(){
	int a, b;
	cout<<"Nhap vao tu, mau: ";
	cin>>a>>b;
	kiemtraphanso(a, b);
//    cout << "Simplified fraction: " << a << "/" << b << endl;
	
	return 0;
}
