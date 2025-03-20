/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* halaman.h */

#ifndef HALAMAN_H
#define HALAMAN_H

#include "antri.h"

void menuUtama();
/* Tujuan : Menampilkan menu utama aplikasi */
/* IS : Aplikasi dalam keadaan siap */
/* FS : Menu utama ditampilkan dan pengguna dapat memilih opsi */

void clearScreen();
/* Tujuan : Membersihkan layar sesuai dengan sistem operasi */
/* IS : Layar mungkin berisi tampilan sebelumnya */
/* FS : Layar menjadi bersih */

void tampilkanLayar(Queue *Q, Teller teller[MAX_TELLER]);
/* Tujuan : Menampilkan status teller dan daftar antrian dalam format kotak */
/* IS : Queue dan teller memiliki data */
/* FS : Tampilan status teller dan antrian ditampilkan di layar */

void tungguEnter();
/* Tujuan : Menunggu pengguna menekan Enter sebelum melanjutkan */
/* IS : Program dalam keadaan berjalan */
/* FS : Program berhenti sementara sampai pengguna menekan Enter */

#endif
