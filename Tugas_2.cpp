#include <iostream>
using namespace std;

int faktorial (int n);

int main () {
	int hasil = faktorial (5);
	cout<<hasil;
	return 0;
}

int faktorial (int n) {
	for (int i=n;i>0;i--) {
		if (i == 1 ) {
			return 1;
		}
		else {
			return n * faktorial (n-1);
		}
	}
}