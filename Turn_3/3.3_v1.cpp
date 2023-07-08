#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    // 1 - T?o file
    // 2 - M? file
    f = fopen("Bai3_3.bin", "wb");
    if (f == NULL) {
        printf("\nError: Cannot create/open the file.");
        exit(1);
    }

    // 3 - �?c v� ghi d? li?u
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    float number;
    for (int i = 0; i < n; ++i) {
        printf("Nhap so phan tu thu %d: ", i + 1);
        scanf("%f", &number);
        fwrite(&number, sizeof(float), 1, f);
    }

    // 4 - ��ng file
    fclose(f);

    // M? v� d?c d? li?u t? file
    f = fopen("Bai3_3.bin", "rb");
    if (f == NULL) {
        printf("\nError: Cannot open the file.");
        exit(1);
    }

    float readNumber;
    while (fread(&readNumber, sizeof(float), 1, f) == 1) {
        printf("%f\n", readNumber);
    }

    // ��ng file
    fclose(f);

    return 0;
}

