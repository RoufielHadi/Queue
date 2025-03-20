/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* antri.h - Header untuk Sistem Antrian dengan VIP */

#ifndef ANTRI_H
#define ANTRI_H

#include "queue.h"

#define MAX_TELLER 3 // Jumlah teller yang tersedia

typedef struct {
    int id;
    int sedang_melayani;
} Teller;

/* *** Konstruktor *** */
void initAntrian(Queue *Q, Teller teller[MAX_TELLER]);
/* Tujuan: Inisialisasi antrian dan status teller */
/* IS: Queue belum terdefinisi, teller belum memiliki pelanggan */
/* FS: Queue kosong, teller siap melayani */

/* *** Operasi Antrian *** */
void ambilAntrian(Queue *Q, int *counter, int isVIP);
/* Tujuan: Menambahkan pelanggan ke antrian */
/* IS: Queue mungkin kosong atau berisi beberapa pelanggan */
/* FS: Pelanggan baru ditambahkan ke antrian dengan nomor unik */
/* Jika isVIP == 1, pelanggan dimasukkan ke dalam antrian prioritas */

void prosesAntrian(Queue *Q, Teller teller[MAX_TELLER]);
/* Tujuan: Memproses antrian dengan 3 teller */
/* IS: Teller mungkin kosong atau sedang melayani pelanggan */
/* FS: Jika teller kosong dan ada pelanggan, pelanggan dilayani oleh teller */

/* *** Tampilan Status *** */
void tampilkanStatusTeller(Teller teller[MAX_TELLER]);
/* Tujuan: Menampilkan status setiap teller */
/* IS: Teller mungkin kosong atau sedang melayani pelanggan */
/* FS: Status setiap teller ditampilkan di layar */

void tampilkanDaftarAntrian(Queue Q);
/* Tujuan: Menampilkan daftar antrian keseluruhan */
/* IS: Queue mungkin kosong atau berisi beberapa pelanggan */
/* FS: Daftar nomor antrian ditampilkan */

void kosongkanTellerBergantian(Teller teller[MAX_TELLER]);
/* Tujuan: Mengosongkan teller secara berurutan */
/* IS: Teller mungkin sedang melayani pelanggan */
/* FS: Salah satu teller yang sedang melayani menjadi kosong */

#endif

