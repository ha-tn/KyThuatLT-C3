#include <iostream>
using namespace std;

//nhap mang
void nhapMang(int* a, int n) {
	cout << "Nhap mang a: " << endl;
	for (int i = 0;i < n;i++) {
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

//xuat mang
void xuatMang(int* a, int n) {
	cout << "Mang duoc nhap la: " << endl;
	for(int i=0; i<n;i++){
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Cau a: Liet ke cac cap so co tong bang k, k nhap tu ban phim
void lietKe2SoBangK(int* a, int n) {
	int k;
	cout << "Nhap k= ";
	cin >> k;
	cout << "Vay cac cap so co tong bang " << k << " la: " << endl;
	//bool flag = false;
	for (int i = 0;i < n - 1;i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == k)
				cout << a[i] << "-" << a[j] << "\t";
		}
	}
	cout << endl;
}

//Caub: Liet ke cac so cap nguyen to cung nhau trong mang
// thêm 1 hàm check đó có phải là cặp số nguyên tố không
bool checkCapSoNT(int a, int b) {

	// thêm phần bắt buộc số <=0 thì sẽ sai luôn, khỏi chạy vòng lặp
	if (a <= 0 || b <= 0)
		return false;
	//ƯCLN của hai số không thay đổi khi ta lấy số lớn trừ đi số nhỏ.
	while (a != 1 && b != 1) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
		if (a == 0 || b == 0)
			return false;
	}
	return true;
}
void lietKeCapSoNT(int* a, int n) {
	cout << "Vay cac cap so nguyen to la: " << endl;
	for (int i = 0;i < n - 1;i++) {
		for (int j = i + 1; j < n; j++) {
			//neu 2 số a[i] và a[j] return = true thì xuất ra
			if (checkCapSoNT(a[i], a[j]) == true)
				cout << a[i] << "-" << a[j] << "\t";
		}
	}
}
int main() {
	int n;
	do {
		cout << "Nhap (n>=10) n= ";
		cin >> n;
	} while (n < 10);

	//cap phat bo nho nac danh cho mang so nguyen n
	int* a = new int[n];

	nhapMang(a, n);
	xuatMang(a, n);

	lietKe2SoBangK(a, n);
	lietKeCapSoNT(a, n);

	//xoa mang de tranh bo nho giu nhieu vung nho va khong duoc giai phong
	delete[] a;
	return 0;
}