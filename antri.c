/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* antri.c - Implementasi Sistem Antrian dengan VIP */

#include "antri.h"
#include <stdio.h>

void initAntrian(Queue *Q, Teller teller[MAX_TELLER]) {
    CreateQueue(Q);
    for (int i = 0; i < MAX_TELLER; i++) {
        teller[i].id = i + 1;
        teller[i].sedang_melayani = 0; // Tidak ada pelanggan
    }
}

void ambilAntrian(Queue *Q, int *counter, int isVIP) {
    (*counter)++;
    printf("Nomor antrian %d telah ditambahkan ke antrian.\n", *counter);
    if (isVIP) {
        printf("[VIP] Antrian %d mendapat prioritas lebih tinggi!\n", *counter);
        EnqueueVIP(Q, *counter);
    } else {
        Enqueue(Q, *counter);
    }
}

void prosesAntrian(Queue *Q, Teller teller[MAX_TELLER]) {
    int pelanggan;
    for (int i = 0; i < MAX_TELLER; i++) {
        if (teller[i].sedang_melayani == 0 && !isEmptyQueue(*Q)) {
            Dequeue(Q, &pelanggan);
            teller[i].sedang_melayani = pelanggan;
            printf("Teller %d sedang melayani pelanggan %d.\n", teller[i].id, pelanggan);
        }
    }
}

void tampilkanStatusTeller(Teller teller[MAX_TELLER]) {
    printf("\nStatus Teller:\n");
    for (int i = 0; i < MAX_TELLER; i++) {
        if (teller[i].sedang_melayani == 0) {
            printf("Teller %d: Tidak ada pelanggan\n", teller[i].id);
        } else {
            printf("Teller %d: Melayani pelanggan %d\n", teller[i].id, teller[i].sedang_melayani);
        }
    }
}

void tampilkanDaftarAntrian(Queue Q) {
    printf("\nDaftar Antrian: ");
    TampilQueue(Q);
}

void kosongkanTellerBergantian(Teller teller[MAX_TELLER]) {
    for (int i = 0; i < MAX_TELLER; i++) {
        if (teller[i].sedang_melayani != 0) {
            printf("Teller %d selesai melayani pelanggan %d.\n", teller[i].id, teller[i].sedang_melayani);
            teller[i].sedang_melayani = 0;
            return; // Mengosongkan satu teller dalam satu panggilan fungsi
        }
    }
}
