// 1.5
#include<iostream>

using namespace std;

bool isPrime(int a){
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

int* findPrimes(int n, int& size){
	int* primes = new int[n+1];// cap phat mang dong chua cac so nt
	size = 0;
	for(int i = 2; i<=n;i++){
		if(isPrime(i)){
			primes[size] = i;
			size++;
		}
	}
	return primes;
}

int showArr(int* a, int size){
	for(int i = 0; i < size; i++){
		cout<<"a["<<i<<"]"<<" = "<<a[i]<<endl;
	}
}

int main(){
	int n;
	cout<<"Tim cac so nguyen to cua n"<<endl;
	cout<<"nhap n: ";
	cin>>n;
	
	int size;
	int* primes = findPrimes(n, size);
	
	cout<<"Cac so nguyen to <= n: "<<endl;
	showArr(primes, size);
	
	delete[] primes; // giai phong bo nho
	
	return 0;
} 
