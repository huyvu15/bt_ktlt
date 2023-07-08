#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Nguoi {
    string hoTen;
    int tuoi;
    double luong;
};

void ghiNguoiVaoTep(const string& tenTep, const vector<Nguoi>& danhSach) {
    ofstream tep(tenTep.c_str(), ios::binary | ios::out);

    if (!tep) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }

    for (size_t i = 0; i < danhSach.size(); ++i) {
        tep.write(reinterpret_cast<const char*>(&danhSach[i]), sizeof(Nguoi));
    }

    tep.close();
}

void docNguoiTuTep(const string& tenTep, vector<Nguoi>& danhSach) {
    ifstream tep(tenTep.c_str(), ios::binary | ios::in);

    if (!tep) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    }

    Nguoi nguoi;
    while (tep.read(reinterpret_cast<char*>(&nguoi), sizeof(Nguoi))) {
        danhSach.push_back(nguoi);
    }

    tep.close();
}

string timNguoiCoLuongCaoNhat(const vector<Nguoi>& danhSach) {
    double luongCaoNhat = 0;
    string tenNguoi;

    for (size_t i = 0; i < danhSach.size(); ++i) {
        const Nguoi& nguoi = danhSach[i];
        if (nguoi.luong > luongCaoNhat) {
            luongCaoNhat = nguoi.luong;
            tenNguoi = nguoi.hoTen;
        }
    }

    return tenNguoi;
}

double tinhLuongTrungBinh(const vector<Nguoi>& danhSach) {
    double tongLuong = 0;
    int soNguoi = danhSach.size();

    if (soNguoi == 0) {
        return 0;
    }

    for (size_t i = 0; i < danhSach.size(); ++i) {
        const Nguoi& nguoi = danhSach[i];
        tongLuong += nguoi.luong;
    }

    return tongLuong / soNguoi;
}

void suaThongTinNguoi(const string& tenTep, int viTri) {
    fstream tep(tenTep.c_str(), ios::binary | ios::in | ios::out);

    if (!tep) {
        cout << "Khong the mo tep." << endl;
        return;
    }

    tep.seekp(viTri * sizeof(Nguoi));

    Nguoi nguoi;
    tep.read(reinterpret_cast<char*>(&nguoi), sizeof(Nguoi));

    cout << "Nhap thong tin moi cho nguoi thu " << viTri + 1 << ":" << endl;
    cout << "Ho ten: ";
    getline(cin >> ws, nguoi.hoTen);
    cout << "Tuoi: ";
    cin >> nguoi.tuoi;
    cout << "Luong: ";
    cin >> nguoi.luong;

    tep.seekp(viTri * sizeof(Nguoi));
    tep.write(reinterpret_cast<const char*>(&nguoi), sizeof(Nguoi));

    tep.close();
}

int main() {
    vector<Nguoi> danhSachNguoi;

    int soNguoi;
    cout << "Nhap so luong nguoi: ";
    cin >> soNguoi;

    cin.ignore();
    for (int i = 0; i < soNguoi; ++i) {
        Nguoi nguoi;
        cout << "Nhap thong tin nguoi thu " << i + 1 << ":" << endl;
        cout << "Ho ten: ";
        getline(cin, nguoi.hoTen);
        cout << "Tuoi: ";
        cin >> nguoi.tuoi;
        cout << "Luong: ";
        cin >> nguoi.luong;
        cin.ignore();
        danhSachNguoi.push_back(nguoi);
    }

    string tenTep = "danh_sach_nguoi.bin";
    ghiNguoiVaoTep(tenTep, danhSachNguoi);

    vector<Nguoi> danhSachNguoiDaGhi;
    docNguoiTuTep(tenTep, danhSachNguoiDaGhi);

    string tenNguoiCaoLuongNhat = timNguoiCoLuongCaoNhat(danhSachNguoiDaGhi);
    cout << "Ten nguoi co luong cao nhat: " << tenNguoiCaoLuongNhat << endl;

    double luongTrungBinh = tinhLuongTrungBinh(danhSachNguoiDaGhi);
    cout << "Luong trung binh: " << luongTrungBinh << endl;

    int viTriSua;
    cout << "Nhap vi tri ban ghi can sua: ";
    cin >> viTriSua;

    if (viTriSua >= 0 && viTriSua < danhSachNguoiDaGhi.size()) {
        suaThongTinNguoi(tenTep, viTriSua);
        cout << "Da sua thong tin nguoi thu " << viTriSua + 1 << endl;
    }
    else {
        cout << "Vi tri khong hop le." << endl;
    }

    return 0;
}
