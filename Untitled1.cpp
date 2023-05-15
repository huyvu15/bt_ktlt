#include<iostream>

using namespace std;

void ToHopKe(int a[], int n, int k){
	int i, j, tmp = 0;
	for (i= 1;i<= k; i++)
	if (a[i]!= n-k+i) {tmp= 1;break;}
	if (tmp==0) return;
	i= k;
//	cout<<i;
	while (a[i]>= n-k+i) i--;
	a[i]= a[i] + 1;
	for (j= i+1;j <=k;j++) a[j]= a[i] + j - i;
	for (i= 1; i<= n; i++) printf("%d ", a[i]);
}

int main(){
	int n  = 5, k = 3;
	int a[] = {1, 3, 5};
	ToHopKe(a, n, k);
	return 0;
}
