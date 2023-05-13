#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int n;
    char input;

    do {
        cout << "Menu:" << endl;
        cout << "1. Ch?n 1" << endl;
        cout << "2. Ch?n 2" << endl;
        cout << "..." << endl;
        cout << "n. Ch?n n" << endl;
        cout << "Nh?p l?a ch?n c?a b?n: ";
        cin >> input;

        if (isdigit(input)) {
            n = input - '0';
            cout << "Ğã ch?n " << n << endl;
        } else {
            cout << "Kı t? không h?p l?. K?t thúc chuong trình." << endl;
            break;
        }
    } while (true);

    return 0;
}

