#include <iostream>
using namespace std;

//nhap diem A va B
void nhapDiem(int& xA, int& yA, int& xB, int& yB) {
	cout << " Nhap diem A ( x, y thuoc [0,10]):" << endl;
	cout << " x= ";
	cin >> xA;
	cout << "y = ";
	cin >> yA;
	cout << " Nhap diem B ( x, y thuoc [0,10]):" << endl;
	cout << " x= ";
	cin >> xB;
	cout << "y = ";
	cin >> yB;
}
//Kiem tra toan do diem A, B de phu hop voi yeu cau de bai. vif neu diem a nam ben phai B thi bai toan k chay dc
void checkToaDo(int& xA, int& yA, int& xB, int& yB) {
	while (xA < xB || yA < yB || xA > 10 || xB > 10 || yA > 10 || yB > 10 || xA < 0 || yA < 0 || xB < 0 || yB < 0 ||(xA==xB&&yA==yB)) {
		cout << "Diem A phai nam ben phai diem B, nam trong khung 10x10, va A khong trung voi B: " << endl;
		nhapDiem(xA, yA, xB, yB);
	}
}
int CheckDuongDi(int xA, int yA, int xB, int yB) {
	if (xA == xB && yA == yB)
		return 1;
	if (xA < xB || yA < yB)
		return 0;
	return CheckDuongDi(xA - 1, yA, xB, yB) + CheckDuongDi(xA, yA - 1, xB, yB);
}

int main() {
	int xA, yA, xB, yB;
	nhapDiem(xA, yA, xB, yB);
	checkToaDo(xA, yA, xB, yB);
	cout << " So duong di tu A --> B la: " << CheckDuongDi(xA, yA, xB, yB);
	return 0;
}