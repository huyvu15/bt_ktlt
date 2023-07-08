#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("Bai3_3.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot create/open the file." << endl;
        return 1;
    }

    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    float number;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap so phan tu thu " << i + 1 << ": ";
        cin >> number;
        file.write(reinterpret_cast<char*>(&number), sizeof(float));
    }

    file.close();

    // M? và d?c d? li?u t? file
    ifstream readFile("Bai3_3.bin", ios::binary);
    if (!readFile.is_open()) {
        cout << "Error: Cannot open the file." << endl;
        return 1;
    }

    float readNumber;
    while (readFile.read(reinterpret_cast<char*>(&readNumber), sizeof(float))) {
        cout << readNumber << endl;
    }

    readFile.close();

    return 0;
}

