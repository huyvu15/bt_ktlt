#include <stdio.h>

int main() {
    FILE *binaryFile; // con tr? t?p nh? phân
    double number; // s? th?p phân

    // Nh?p các s? th?p phân t? bàn phím và ghi vào t?p nh? phân
    printf("Nh?p các s? th?p phân (nh?p 0 d? k?t thúc):\n");

    // M? t?p nh? phân d? ghi
    binaryFile = fopen("numbers.txt", "wb");
    if (binaryFile == NULL) {
        printf("Không th? m? t?p nh? phân.\n");
        return 1;
    }

    while (1) {
        printf("? ");
        scanf("%lf", &number);

        if (number == 0) {
            break; // K?t thúc khi nh?p s? 0
        }

        // Ghi s? th?p phân vào t?p nh? phân
        fwrite(&number, sizeof(double), 1, binaryFile);
    }

    fclose(binaryFile); // Ðóng t?p nh? phân sau khi ghi

    // Ð?c t?p nh? phân và in ra các s? dã nh?p
    printf("\nCác s? dã nh?p t? t?p nh? phân:\n");

    // M? t?p nh? phân d? d?c
    binaryFile = fopen("numbers.txt", "rb");
    if (binaryFile == NULL) {
        printf("Không th? m? t?p nh? phân.\n");
        return 1;
    }

    while (fread(&number, sizeof(double), 1, binaryFile) == 1) {
        printf("%.2f\n", number);
    }

    fclose(binaryFile); // Ðóng t?p nh? phân sau khi d?c

    return 0;
}

