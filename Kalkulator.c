#include "Kalkulator.h"
#include "Stack.h"
#include "Tree.h"
//Berfungsi sebagai Penghitungan kalkulator secara infix.

#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>

char token; // variable for reading a charactor
Root *root;
Stack *st;

void GotError(){
	puts("Error.\nperiksa kembali masukan anda.");
	exit(1);
}/*Deskripsi : Memeriksa inputan jika terjadi error
IS : Menunggu pemberitahuan dari procedure checkandgetchar untuk mengetahui operasi salah atau tidak
FS : Menampilkan pesan error saat operasi yang dimasukkan salah
Author : Ryrie Ceisha Ramadhanty */


void CheckAndGetChar(char tmp){
	if(tmp != token){
		GotError();
	}
	token = getchar();
}/*Deskripsi : Memeriksa simbol operasi matematika
IS : Mengecek seluruh operasi pada inputan
FS : Menampilkan peringatan ketika inputan salah atau menjalankan operasi ketika inputan benar
Author : Ryrie Ceisha Ramadhanty */

/* Push data stack dengan metode postfix 
 * Menghitung operasi penjumlahan dan pengurangan
 */
 
double sum()
{
	double temp = term();
	Data datum;
	while(token == '+' || token == '-')
	{
		if(token == '+')
		{
			datum.opr = '+';
			CheckAndGetChar('+');
			temp += term();
			push(st, datum, TRUE);
		}
		else if(token == '-')
		{
			datum.opr = '-';
			CheckAndGetChar('-');
			temp -= term();
			push(st, datum, TRUE);
		}
	}
	return temp;
}/*Deskripsi : Menghitung operasi penjumlahan dan pengurangan
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi penjumlahan dan pengurangan
Author : Ryrie Ceisha Ramadhanty */

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
double term()
{
	double temp = powerof();
	Data datum;
	while(token == '*' || token == '/')
	{
		if(token == '*')
		{
			datum.opr = '*';
			CheckAndGetChar('*');
			temp *= factor();
			push(st, datum, TRUE);
		}
		else if(token == '/')
		{
			datum.opr = '/';
			CheckAndGetChar('/');
			temp /= factor();
			push(st, datum, TRUE);
		}
	}
	return temp;
}/*Deskripsi : Menghitung operasi perkalian dan pembagian
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi perkalian dan pembagian
Author : Ryrie Ceisha Ramadhanty*/

/** \brief
 * push data in the stack with the method of post-fix
 * regards factor as a number
 */
double factor()
{
	double temp = 0.0;
	Data datum;
	if(token == '('){
		// start with new sum again
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(token == '-'){
		// negation
		CheckAndGetChar('-');
		datum.opr = '-';
		temp = -factor();
		push(st, datum, TRUE);
		return temp;
	}
	else if(token == '+'){
		// there is no meaning, but just exception dealing
		CheckAndGetChar('+');
		return factor();
	}
	else if(isdigit(token)){
		ungetc(token, stdin);
		scanf("%lf", &temp);
		datum.num = temp;
		push(st, datum, FALSE);
		token = getchar();
	}
	else GotError();
	return temp;
}/*Deskripsi : Menghitung operasi dengan tanda buka tutup kurung, positif dan negatif
IS : data yang dimasukan user berupa operasi matematika
FS : menjalankan operasi sesuai urutan kaidah operasi matematika
Author : Ryrie Ceisha Ramadhanty */

double powerof(){
	double temp=trigono();
	Data datum;
	

	if(token == 'v'){
		CheckAndGetChar('v');
		datum.opr = 'v';
		temp = sqrt(factor());
		push(st, datum, TRUE);
	}
	//cek untuk operasi pangkat 
		if(token == '^'){
			datum.opr = '^';
			CheckAndGetChar('^');
			temp = pow(temp,factor());
			push(st, datum,TRUE);
		}

	return temp;	
}/*Deskripsi : Menghitung operasi perpangkatan dan perakaran
IS : data yang dimasukan user berupa operasi matematika
FS : Menjalankan operasi perpangkatan dan perakaran
Author : Ryrie Ceisha Ramadhanty */

double trigono(){
	double temp=factor();
	Data datum;
	

	if(token == 's'){
		CheckAndGetChar('s');
		datum.opr = 's';
		temp = sin(factor()/57.2958);
		push(st, datum, TRUE);
	}
	//cek untuk operasi trigonometri
		if(token == 'c'){
			datum.opr = 'c';
			CheckAndGetChar('c');
			temp = cos(factor()/57.2958);
			push(st, datum,TRUE);
		}
	if(token == 't'){
			datum.opr = 't';
			CheckAndGetChar('t');
			temp = tan(factor()/57.2958);
			push(st, datum,TRUE);
		}
	return temp;	
}/* Deskripsi : Menghitung operasi trigonometri menggunakan sin, cos dan tan
IS: Data yang dimasukan berupa operasi matematika
FS:Menjalankan operasi trigonometri
Author : Ryrie Ceisha Ramadhanty*/

//double logaritma(){ //masih belum bisa sesuai yang diharapkan
//	double temp=powerof();
//	Data datum;
//	
//	//cek log
//	if(token == 'l'){
//		CheckAndGetChar('l');
//		datum.opr = 'l';
//		temp = log(powerof()/57.295779513);
//		push(st, datum, TRUE);
//	}
//	//cek log10
//		if(token == 'L'){
//			datum.opr = 'L';
//			CheckAndGetChar('L');
//			temp = log10(powerof()/57.295779513);
//			push(st, datum,TRUE);
//		}
//	//cek eks
//	if(token == 'e'){
//			datum.opr = 'e';
//			CheckAndGetChar('e');
//			temp = exp(powerof());
//			push(st, datum,TRUE);
//		}
//	return temp;	
//}

//==================================UI=======================================// by A7
void gotoxy(int x,int y){
	
	HANDLE handle;
	COORD coord;
	coord.X =x;
	coord.Y =y;
	handle  = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}/* Deskripsi : Menu inteface ketka program dijalannkan
IS:tampilan kosong
FS:tampilan menu program
Author : Ryrie Ceisha Ramadhanty*/

void loading(int x,int y){
	system("COLOR 50");
	system("cls");
	int i;
	gotoxy(x,y-1);printf("Sabar...");
	
	
	for(i=x;i<=x+19;i++){
	    gotoxy(i,y);printf("%c",196);
		gotoxy(i,y+1);printf("%c",196);	
	}
	for(i=y;i<=y+1;i++){
	    gotoxy(x,i);printf("%c",179);
		gotoxy(x+19,i);printf("%c",179);	
	}
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+19,y);printf("%c",191);
	gotoxy(x,y+1);printf("%c",192);
	gotoxy(x+19,y+1);printf("%c",217);
	for ( i = x; i<=x+19;i++){
		gotoxy(i,y);printf("%c",220);
		gotoxy(i,y+1);printf("%c",223);
		Sleep(20);
	}
	system("cls");
}/* Deskripsi : Menampilkan tampilan awal loading saat akan memasuki menu
IS:tampilan kosong
FS:tampilan loading sebelum memasuki tampilan menu
Author : Ryrie Ceisha Ramadhanty*/


