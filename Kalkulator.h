#ifndef KALKULATOR_H_INCLUDED
#define KALKULATOR_H_INCLUDED

//Berfungsi sebagai Penghitungan kalkulator secara infix.



#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2

#define TRUE		1
#define FALSE	 	0

//sebagai tokenize untuk ADT Tree dan ADT Stack
typedef union
{
	double num;
	char opr;
} Data;

//sebagai fungsi-fungsi operasi dalam kalulator
double term();
/*Deskripsi : Menghitung operasi perkalian dan pembagian
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi perkalian dan pembagian
Author : Ryrie Ceisha Ramadhanty*/

double sum();
/*Deskripsi : Menghitung operasi penjumlahan dan pengurangan
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi penjumlahan dan pengurangan
Author : Ryrie Ceisha Ramadhanty */

double factor();
/*Deskripsi : Menghitung operasi dengan tanda buka tutup kurung, positif dan negatif
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi sesuai urutan kaidah operasi matematika
Author : Ryrie Ceisha Ramadhanty */

double powerof();
/*Deskripsi : Menghitung operasi perpangkatan dan perakaran
IS : data yang dimasukan user berupa operasi matematika
FS : Menjalankan operasi perpangkatan dan perakaran
Author : Ryrie Ceisha Ramadhanty */

double trigono();
/* Deskripsi : Menghitung operasi trigonometri menggunakan sin, cos dan tan
IS: Data yang dimasukan berupa operasi matematika
FS:Menjalankan operasi trigonometri
Author : Ryrie Ceisha Ramadhanty*/

//double logaritma();

void CheckAndGetChar(char tmp);
/*Deskripsi : Memeriksa simbol operasi matematika
IS : Mengecek seluruh operasi pada inputan
FS : Menampilkan peringatan ketika inputan salah atau menjalankan operasi ketika inputan benar
Author : Ryrie Ceisha Ramadhanty */

void GotError();
/*Deskripsi : Memeriksa inputan jika terjadi error
IS : Menunggu pemberitahuan dari procedure checkandgetchar untuk mengetahui operasi salah atau tidak
FS : Menampilkan pesan error saat operasi yang dimasukkan salah
Author : Ryrie Ceisha Ramadhanty */

void gotoxy(int x,int y);
/* Deskripsi : Menampilkan tampilan awal loading saat akan memasuki menu
IS:tampilan kosong
FS:tampilan loading sebelum memasuki tampilan menu
Author : Ryrie Ceisha Ramadhanty*/

void loading(int x,int y);
const static Data dummy_data = {0};
#endif // BANTUAN_H_INCLUDED
