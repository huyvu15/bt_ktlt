//  2.2: thao tac tren phan so

#include <stdio.h>

struct PhanSo {
    int tuSo;
    int mauSo;
};

struct PhanSo nhapPhanSo() {
    struct PhanSo ps;
    printf("Nhap tu so: ");
    scanf("%d", &ps.tuSo);
    printf("Nhap mau so: ");
    scanf("%d", &ps.mauSo);
    return ps;
}

void hienThiPhanSo(struct PhanSo ps) {
    printf("Phan so: %d/%d\n", ps.tuSo, ps.mauSo);
}

int timUCLN(int a, int b) {
    if (b == 0)
        return a;
    return timUCLN(b, a % b);
}

struct PhanSo rutGonPhanSo(struct PhanSo ps) {
    int ucln = timUCLN(ps.tuSo, ps.mauSo);
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
    return ps;
}

struct PhanSo congHaiPhanSo(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo tong;
    tong.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    tong.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGonPhanSo(tong);
}

struct PhanSo truHaiPhanSo(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo hieu;
    hieu.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    hieu.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGonPhanSo(hieu);
}

struct PhanSo nhanHaiPhanSo(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo tich;
    tich.tuSo = ps1.tuSo * ps2.tuSo;
    tich.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGonPhanSo(tich);
}

struct PhanSo chiaHaiPhanSo(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo thuong;
    thuong.tuSo = ps1.tuSo * ps2.mauSo;
    thuong.mauSo = ps1.mauSo * ps2.tuSo;
    return rutGonPhanSo(thuong);
}

int main() {
    struct PhanSo ps1, ps2, ketQua;
    int luaChon;

    printf("Nhap phan so thu nhat:\n");
    ps1 = nhapPhanSo();

    printf("Nhap phan so thu hai:\n");
    ps2 = nhapPhanSo();

    do {
        printf("===== MENU =====\n");
        printf("1. Hien thi phan so thu nhat\n");
        printf("2. Hien thi phan so thu hai\n");
        printf("3. Cong hai phan so\n");
        printf("4. Tru hai phan so\n");
        printf("5. Nhan hai phan so\n");
        printf("6. Chia hai phan so\n");
        printf("0. Ket thuc chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiPhanSo(ps1);
                break;
            case 2:
                hienThiPhanSo(ps2);
                break;
            case 3:
                ketQua = congHaiPhanSo(ps1, ps2);
                hienThiPhanSo(ketQua);
                break;
            case 4:
                ketQua = truHaiPhanSo(ps1, ps2);
                hienThiPhanSo(ketQua);
                break;
            case 5:
                ketQua = nhanHaiPhanSo(ps1, ps2);
                hienThiPhanSo(ketQua);
                break;
            case 6:
                ketQua = chiaHaiPhanSo(ps1, ps2);
                hienThiPhanSo(ketQua);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

        printf("\n");

    } while (luaChon != 0);

    return 0;
}

