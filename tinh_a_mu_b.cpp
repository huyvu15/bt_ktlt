// ham tinh a^b
#include<iostream>

using namespace std;

int fun(int x, int y)
{
 if (y == 0) return 0;
 return (x + fun(x, y-1));
}


int fun2(int a, int b)
{
 if (b == 0) return 1;
 return fun(a, fun2(a, b-1));
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<fun2(a, b);
	return 0;
}
