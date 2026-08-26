#include <iostream>
using namespace std;
void nhapMang(int *a, int n) {
	for (int i = 0;i < n;i++) {
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	cout << endl;
}
void xuatMang(int* a, int n) {
	for (int i = 0;i < n;i++) {
		cout<< a[i]<<"\t";
	}
	cout << endl;
}

//Câu a: Liệt kê ác số nguyên tố trong mảng
//Kiem tra so co phai la so nguyen to hay khong
bool checkSoNT(int n) {
	if (n<=1)
		return false;
	for (int i = 2; i <= sqrt(n);i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
//Liet ke cac so nguyen to trong mang
void lietKeSoNT(int *a, int n) {
	cout << "Cac so nguyen to co trong mang la:" << endl;
	for (int i = 0; i < n; i++) {
		//neu là số nguyên tố thì xuất a[i]
		if (checkSoNT(a[i]) == true)
			cout << a[i]<<"\t";
	}
	cout << endl;
}

//Cau b: Liet ke cac so doi xứng trong mảng

//thuật toán đảo ngược số
int daoNguocSo(int n) {
	int soMoi = 0;
	int thuong = n;
	while(thuong > 0) {
		int du = thuong % 10;
		thuong = thuong / 10;
		soMoi = soMoi * 10 + du;
	}
	return soMoi;
}

bool checkSodoiXung(int n) {
	//số có 1 chữ số cũng là số đối xứng, mà số âm thì không phải
	if (n < 0)
		return false;
	if (n < 10 && n >= 0)
		return true;
	//khi n>10 thi phải dùng thuật toán kiểm tra
	if (n == daoNguocSo(n))
		return true;
	return false;
}
//liet ke cac so doi xung
void lietKeSoDoiXung(int* a, int n) {
	cout << "Cac so doi xung trong mang la:" << endl;
	for (int i = 0; i < n; i++) {
		//neu là số doi xung thì xuất a[i]
		if (checkSodoiXung(a[i]) == true)
			cout << a[i] << "\t";
	}
}
int main() {
	int n;
	do {
		cout << " Nhap (n>=10) n= ";
		cin >> n;
	} while (n < 10);

	// cap phat vung nho nac danh
	int* a = new int[n];

	nhapMang(a, n);
	xuatMang(a, n);
	lietKeSoNT(a, n);
	lietKeSoDoiXung(a, n);
	//xoa mang con tro de giai phong vung nho
	delete[] a;
	return 0;
}