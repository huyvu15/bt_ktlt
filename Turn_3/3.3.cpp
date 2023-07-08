#include <stdio.h>

int main() {
    FILE *binaryFile; // con tr? t?p nh? ph�n
    double number; // s? th?p ph�n

    // Nh?p c�c s? th?p ph�n t? b�n ph�m v� ghi v�o t?p nh? ph�n
    printf("Nh?p c�c s? th?p ph�n (nh?p 0 d? k?t th�c):\n");

    // M? t?p nh? ph�n d? ghi
    binaryFile = fopen("numbers.txt", "wb");
    if (binaryFile == NULL) {
        printf("Kh�ng th? m? t?p nh? ph�n.\n");
        return 1;
    }

    while (1) {
        printf("? ");
        scanf("%lf", &number);

        if (number == 0) {
            break; // K?t th�c khi nh?p s? 0
        }

        // Ghi s? th?p ph�n v�o t?p nh? ph�n
        fwrite(&number, sizeof(double), 1, binaryFile);
    }

    fclose(binaryFile); // ��ng t?p nh? ph�n sau khi ghi

    // �?c t?p nh? ph�n v� in ra c�c s? d� nh?p
    printf("\nC�c s? d� nh?p t? t?p nh? ph�n:\n");

    // M? t?p nh? ph�n d? d?c
    binaryFile = fopen("numbers.txt", "rb");
    if (binaryFile == NULL) {
        printf("Kh�ng th? m? t?p nh? ph�n.\n");
        return 1;
    }

    while (fread(&number, sizeof(double), 1, binaryFile) == 1) {
        printf("%.2f\n", number);
    }

    fclose(binaryFile); // ��ng t?p nh? ph�n sau khi d?c

    return 0;
}

