//thuat toan Euclid
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
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main(){
	int m,n;
	cout<<"enter two numbers: ";
	cin>>m>> n;
	cout << "UCLL("<<m<<","<<n<<"):"<< Euclid(m, n) << endl;
	
	return 0;
}


