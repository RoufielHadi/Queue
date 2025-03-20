/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "halaman.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

void tungguEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}

void tampilkanLayar(Queue *Q, Teller teller[MAX_TELLER]) {
    clearScreen();
    printf("********************************************\n");
    for (int i = 0; i < MAX_TELLER; i++) {
        printf("* Teller %d: ", teller[i].id);
        if (teller[i].sedang_melayani)
            printf("Melayani pelanggan %d ", teller[i].sedang_melayani);
        else
            printf("Kosong ");
        printf("                        *\n");
    }
    printf("********************************************\n");
    printf("\nDaftar Antrian: ");
    tampilkanDaftarAntrian(*Q);
}

void menuUtama() {
    int choice;
    Queue antrian;
    Teller teller[MAX_TELLER];
    int counter = 0;

    initAntrian(&antrian, teller);

    do {
        tampilkanLayar(&antrian, teller);
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Ambil Nomor VIP\n");
        printf("3. Proses Antrian\n");
        printf("4. Kosongkan Teller Bergantian\n");
        printf("5. Tampilkan Daftar Antrian\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                ambilAntrian(&antrian, &counter, 0);
                break;
            case 2:
                ambilAntrian(&antrian, &counter, 1);
                break;
            case 3:
                prosesAntrian(&antrian, teller);
                break;
            case 4:
                kosongkanTellerBergantian(teller);
                break;
            case 5:
                tampilkanDaftarAntrian(antrian);
                break;
            case 0:
                printf("Terima kasih telah menggunakan sistem antrian bank!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
        tungguEnter();
    } while (choice != 0);
}

