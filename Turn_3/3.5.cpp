#include <iostream>
using namespace std;
struct PhanSo {
    int tuSo;
    int mauSo;
};

struct Node {
    PhanSo data;
    Node* left;
    Node* right;
};

// Hàm t?o m?t nút m?i v?i m?t phân s?
Node* taoNut(PhanSo phanSo) {
    Node* nutMoi = new Node;
    nutMoi->data = phanSo;
    nutMoi->left = NULL;
    nutMoi->right = NULL;
    return nutMoi;
}

// Hàm chèn m?t phân s? vào cây nh? phân
Node* chenNut(Node* root, PhanSo phanSo) {
    if (root == NULL) {
        return taoNut(phanSo);
    }

    if (phanSo.tuSo * root->data.mauSo < root->data.tuSo * phanSo.mauSo) {
        root->left = chenNut(root->left, phanSo);
    }
    else {
        root->right = chenNut(root->right, phanSo);
    }

    return root;
}

// Hàm tìm ki?m m?t phân s? trong cây nh? phân
Node* timNut(Node* root, PhanSo phanSo) {
    if (root == NULL || phanSo.tuSo * root->data.mauSo == root->data.tuSo * phanSo.mauSo) {
        return root;
    }

    if (phanSo.tuSo * root->data.mauSo < root->data.tuSo * phanSo.mauSo) {
        return timNut(root->left, phanSo);
    }
    else {
        return timNut(root->right, phanSo);
    }
}

// Hàm so sánh hai phân s?
int soSanhPhanSo(PhanSo phanSo1, PhanSo phanSo2) {
    int tich1 = phanSo1.tuSo * phanSo2.mauSo;
    int tich2 = phanSo2.tuSo * phanSo1.mauSo;

    if (tich1 < tich2) {
        return -1;
    }
    else if (tich1 > tich2) {
        return 1;
    }

    return 0;
}

// Hàm in ra m?t phân s?
void inPhanSo(PhanSo phanSo) {
    cout << phanSo.tuSo << "/" << phanSo.mauSo;
}

int main() {
    Node* goc = NULL;
    int n;
    cout << "nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ms, tuso;
        cout << "Nhap mau so "<<i+1<<" : ";
        cin >> ms;
        cout << "nhap tu so "<<i+1<<" : ";
        cin >> tuso;
        PhanSo x = { tuso,ms };
        goc = chenNut(goc, x);
    }
    int ms, ts;
    cout << "Nhap mau so cua phan so can tim: ";
    cin >> ms;
    cout << "Nhap tu so cua phan so can tim: ";
    cin >> ts;
    PhanSo phanSoTimKiem = { ts, ms };
    Node* ketQua = timNut(goc, phanSoTimKiem);

    if (ketQua != NULL) {
        cout << "Phan so tim thay trong cay: ";
        inPhanSo(ketQua->data);
        cout << endl;
    }
    else {
        cout << "Phan so khong tim thay trong cay." << endl;
    }

    return 0;
}

