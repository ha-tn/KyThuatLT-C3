#include <iostream>
using namespace std;
//const int MAX = 10;
void nhapToaDoDiem( int &x1, int &y1, int &x2, int &y2) {
	do {
		cout << "Nhap toa do diem dau: " << endl;
		cout << "x= ";
		cin >> x1;
		cout << "y1= ";
		cin >> y1;
	} while (x1 > 10 && x1 < 0 && y1>10 && y1 < 0);

	do {
		cout << "Nhap toa do diem dich: " << endl;
		cout << "x= ";
		cin >> x2;
		cout << "y1= ";
		cin >> y2;
	} while (x2 > 10 && x2 < 0 && y2>10 && y2 < 0);
	cout << "Toa do cua 2 diem la : ";
	cout << "dau[" << x1 << "][" << y1 << "]\t";
	cout << "dich["<<x2<<"]["<<y2<<"]\t"<<endl;
}
bool kiemTraToaDo(int& x1, int& y1, int& x2, int& y2) {
	if (x1 > x2 || y1 > y2)
		return false;
	return true;
}
int tinhGiaiThua(int &x) {
	int tich = 1;
	for (int i = x; i > 0;i--) {
		tich = tich * i;
	}
	return tich;
}

int tinhSoDuongDi(int& x1, int& y1, int& x2, int& y2) {
	int soLuong = 0;
	int hieuX = x2 - x1;
	int tongXY = hieuX + (y2 - y1);
	soLuong = tinhGiaiThua(tongXY)/ tinhGiaiThua(hieuX);
	return soLuong;
}

int main(){
	//int a[MAX][MAX];
	int x, y, x2, y2;
	
	nhapToaDoDiem(x, y, x2, y2);
	bool flag = kiemTraToaDo(x, y, x2, y2);
	if (flag == false)
		cout << "Khong tim thay duong di";
	else
		cout << "so duong di tu diem dau --> dich la: " << tinhSoDuongDi(x, y, x2, y2);

	return 0;

}