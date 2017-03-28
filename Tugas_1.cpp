#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//variabel global
float value, jumlah;
int total = 0;

//linked list untuk mengakomodir inputan yang sesuai dengan jumlah inputan user
typedef struct node
{
	float value;
	struct node *next;
} node;

node* create(float value)
{
	node *a = (node *)malloc(sizeof(int));
	a->value = value;
	a->next = NULL;
	return a;
}

//prototype
void display(node *start);
void input();
void release(node *mulai);
bool isWhitinRange(float x, int min, int max);
int getSize();
bool isEmpty();
float getAvg();
int getLulus();
int getTidakLulus();

//pointer global
node *head = NULL;

//program utama
int main(){
	input();
	if (!isEmpty())
		display(head);
	else
		cout << "\n\n Tidak ada data" <<endl<<endl<<endl<<endl;
		cout << "\n";
		cout <<"============================================================================"<<endl;
		cout <<"~~ Program ini dibuat untuk tugas Mata Kuliah Algoritma dan Pemrograman 2 ~~"<<endl;
		cout <<"                        ~ Farhan Hanifuddin ~"<<endl;
		cout <<"                          ~ NIM 16 111 197 ~"<<endl;
		cout <<"                         ~ Kelas TIF RM 16C ~"<<endl;
		cout <<"                  ~ Sekolah Tinggi Teknologi Bandung ~"<<endl;
		cout <<"============================================================================";
	release(head);
	return 0;
}

//prosedur input
void input(){	
	node *a = NULL;
	node *berikutnya = NULL;
	do {
		cout << "Masukan Nilai IP Mahasiswa : ";
		cin >> value;
		bool result = isWhitinRange(value, 0, 4);
		if (result){
			a = berikutnya;
			berikutnya = create(value);
			if (head == NULL)
				head = berikutnya;
			if (a != NULL)
				a->next = berikutnya;
			total++;
			jumlah += value;
		}
	} while(value != -999);
}

//prosedur tampil
void display(node *start){
	node *a = start;
	int no = 1;
	cout << "\n";
	cout <<"============================================================================"<<endl;
	cout << "Jumlah Nilai IP Mahasiswa yang valid \t\t: ";
	printf("%12i\n", getSize());
	cout << "\n";
	cout << "Nilai Rata Rata IP Mahasiswa \t\t\t:";
	printf("%14.2f\n", getAvg());
	cout << "\n";
	cout << "Jumlah Nilai IP Mahasiswa Yang Lulus \t\t:";
	printf("%12i\n", getLulus());
	cout << "\n";
	cout << "Jumlah Nilai IP Mahasiswa Yang Tidak Lulus \t:";
	printf("%12i\n", getTidakLulus());
	cout <<"============================================================================"<<endl;
}

//prosedur menghapus data di memori
void release(node *mulai){
	node *a = mulai;
	node *terus = NULL;
	while (a != NULL){
		terus = a->next;
		free(a);
		a = terus;
	}
}

//fungsi mengecek validitas nilai ip mahasiswa
bool isWhitinRange(float x, int min, int max){
	return (x >= min && x <= max);
}

int getSize(){
	return total;
}

bool isEmpty(){
	return (total == 0 && head == NULL);
}

float getAvg(){
	float avg = jumlah / total;
	return avg; 
}

//fungsi mencari banyak nilai ip yang lulus
int getLulus(){
	node *a = head;
	int lulus = 0;
	while (a != NULL){
		if (a->value >= 2.75)
			lulus++;
		a = a->next;
	}
	return lulus;
}

//fungsi mencari banyak nilai ip yang tidak lulus
int getTidakLulus(){
	node *a = head;
	int tdkLulus = 0;
	while (a != NULL){
		if (a->value < 2.75)
			tdkLulus++;
		a = a->next;
	}
	return tdkLulus;
}