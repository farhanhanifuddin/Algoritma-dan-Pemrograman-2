#include <iostream>
using namespace std;

//prototype
void prosesBaca();
int prosesTambah();
int prosesKurang();
void prosesTampil();

//variabel global
	int a, b;

//program utama
int main (){
	prosesBaca();
	prosesTampil();
	return 0;
	}

//proses baca
void prosesBaca(){
	cout<<"Masukkan nila A : ";
	cin>>a;
	cout<<"Masukkan nilai B : ";
	cin>>b;
	}

//proses tambah
int prosesTambah(){
	return a+b;
	}

//proses kurang
int prosesKurang(){
	int hasil;
	hasil = a-b;
	return hasil;
	}

//proses Tampil
void prosesTampil(){
	cout<<"Hasil tambah : "<<prosesTambah()<<endl;
	cout<<"Hasil kurang : "<<prosesKurang()<<endl;
	}
