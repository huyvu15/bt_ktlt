// 2.1: find the number has two digit when dao trat tu cua 2 so do
// se thu duoc 1 so nguyen to cung nhau

#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int daotrattu(int a){
	// vi du 15
	int c,d;
	c = a / 10;
	d = a - c * 10;
	return d*10 + c;
//	return (a - (a/10) * 10) + (a/10);
	
}

int main(){
	int i = 0;
	int count =0;
	cout<<"Cac so can tim la: "<<endl;
	for(i = 0; i< 100; i++){
		if(gcd(daotrattu(i), i) == 1){
			cout<<i<<"    ";
			count++;	
		}
			
	}
	cout<<endl;
	cout<<"tim duoc "<<count<< " so";

	
	return 0;
}
