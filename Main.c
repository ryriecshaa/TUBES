#include "Tree.h"
#include "Stack.h"
#include "Kalkulator.h"
#include <math.h>
//Berfungsi sebagai main program dari kalukaltor yang memanggil ADT Stack,ADT Kalkulator, dan ADT Tree

char token; // variabel untuk membaca karakter 
Root *root;
Stack *st;


int main(){
	char Pengulangan;
	double value;
	StackNode tmp;
	loading(30,12);
	system("color 20");
	do{
	TreeNode *tn = NULL;
	root = make_root_node();
	st = make_stack();
	system("cls");
	printf("\t\t\t|========================================================|\n");
    printf("\t\t\t|=================| KALKULATOR SEDERHANA |==========v1.0=|\n");
    printf("\t\t\t|========================================================|\n");
	printf("\t\t\t|________________________________________________________|\n");
	printf("\t\t\t|===================| OPERASI BILANGAN |=================|\n");
    printf("\t\t\t|  (+)Pertambahan	(-)Pengurangan    (*)Perkalian   |\n\n");
    printf("\t\t\t|  (/)Pembagian	        (v)Perakaran      (^)Perpangkatan|\n\n");
    printf("\t\t\t|========================================================|\n");
	printf("\t\t\tMasukan Angka dan operasi bilangan contoh : \n\t\t\t((1+2)*(3-4))\n\t\t\t\n");
	printf("\t\t\tMasukkan Angka : ");
    token = getchar();
    value = sum();
	
	while(!isEmpty_stack(st)){
		// Mengeluarkan dari stack dan memasukan ke tree
		tmp = pop(st);
		while(tmp.isChar){
			// operator
			tn = make_child(tn, tmp.datum, tmp.isChar);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// number
	tn = make_child(tn, tmp.datum, tmp.isChar);
		if(root->root == NULL)	root->root = tn;
	}
	
    /// Print
    printf("\t\t\tprefix : ");
    traversal(root, PREORDER);
    printf("\n");
    printf("\t\t\tinfix : ");
    traversal(root, INORDER);
    printf("\n");
    printf("\t\t\tpostfix : ");
    traversal(root, POSTORDER);
    printf("\n");
    printf("\t\t\tHasil kalkulasi : %g\n", value);
    printf("");

    //Menghapus Tree
     remove_all_tree_nodes(root);
    
    //Pengulangan aplikasi jika diperlukan
    printf("\t\t\tUlangi Program? y/n \n");
    scanf("%c",&Pengulangan);
   
    if(Pengulangan=='y'||Pengulangan=='Y'){
    	system("cls");    	
	}
	else{
		exit(1);
	}

    fflush(stdin);
    system("COLOR 4B");
}	
 	while (1);
    return 0;

}

