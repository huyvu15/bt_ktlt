// 2.3 thao tac voi mang

#include<iostream>
#include<string>

using namespace std;

void nhapXau(string *A, int n){
    for (int i = 0; i < n; ++i) {
        cout << "Nhap xau thu " << i + 1 << ": ";
        getline(cin, A[i]);
    }
}

void inXau(string *A, int n){
	for (int i = 0; i < n; ++i) {
        cout << A[i] << endl; 
    }
}

bool isWhiteSpace(char c){
	// 1 ky tu la khoang trang neu la 't': tab
	return c == ' ' || c == '\t' || c == '\n';
}


void removeSpace(char *&s){
	int count = 0;
	int i = 0;
	int len = sizeof(s);
	// dem khoang trang
	for(i = 0; i<len; i++){
		if(isWhiteSpace(s[i])){
			count++;
		}else{
			break;
		}
	}
	// xoa khoang trang
	for(i = 0; i<= len - count; i++){
		s[i] = s[i + count];		
	}
	
	i = len - 1;
	while(isWhiteSpace(s[i])){
		s[i] = '\0';
		i--;
	}
}

void removeSpaceFull(string *A, int n){
    for(int i = 0; i<n; i++){
        char *s = &A[i][0]; // Chuyen doi tu string sang char *
        removeSpace(s);
    }
}


void tinhchinh(string& s) {
    bool capitalizeNext = true;
    
    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) {
            if (capitalizeNext) {
                s[i] = toupper(s[i]);
                capitalizeNext = false;
            } else {
                s[i] = tolower(s[i]);
            }
        } else {
            capitalizeNext = true;
        }
    }
}

void full(string *A, int n){
	for(int i = 0; i< n; i++){
		tinhchinh(A[i])	;
	}
}

int CountString(string source, string target)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < source.length())
    {
        if (source[i] == target[j])
            j++;
        else
            j = 0;
        if (j == target.length())
        {
            count++;
            j = 0;
        }
        i++;
    }
    return count;
}


int main(){
	int n;
	cout<<"nhap vao so xau: "; cin>>n;
	cin.ignore();// doc xau thi ko doc ky tu xuong dong
	
	string *A = new string[n];
	
	nhapXau(A, n);
	removeSpaceFull(A, n);
	full(A, n);
	inXau(A, n);
	
	string h = "Tu";
	for (int i = 0; i < n; i++)
	{
	    int count = CountString(A[i], h);
	    cout << "So luong tu trong xau " << i + 1 << ": " << count << endl;
	}
	return 0;
}
