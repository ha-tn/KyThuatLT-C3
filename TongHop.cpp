#include <iostream>
using namespace std;
//De 1
//cau 1
void input(int& n)
{
    while (true)
    {
        cout << "Nhap n: ";
        cin >> n;
        if (2 <= n && n <= 20)
            break;
        else
            cout << "Vui long nhap so nguyen duong trong khoang [2, 20]!" << endl;
    }
}
void vematranxoanoc(int a[][20], int n)
{
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int value = 1;
    while (top <= bottom && left <= right) {

        // 1. Đi từ trái sang phải
        for (int j = left; j <= right; j++) {
            a[top][j] = value;
            value++;

        }
        top++;

        // 2. Đi từ trên xuống dưới
        for (int i = top; i <= bottom; i++) {
            a[i][right] = value;
            value++;
        }
        right--;

        // 3. Đi từ phải sang trái
        for (int j = right; j >= left; j--) {
            a[bottom][j] = value;
            value++;
        }
        bottom--;

        // 4. Đi từ dưới lên trên
        for (int i = bottom; i >= top; i--) {
            a[i][left] = value;
            value++;
        }
        left++;
    };
    cout << "\nMa tran xoan oc:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

}
//////////////////////////////////////////////////////

//cau 2
int soDuongDi(int xA, int yA, int xB, int yB) {
    // Đã đến B
    if (xA == xB && yA == yB) {
        return 1;
    }

    // Đi quá B
    if (xA > xB || yA > yB) {
        return 0;
    }

    // Đi sang phải hoặc đi lên
    return soDuongDi(xA + 1, yA, xB, yB) + soDuongDi(xA, yA + 1, xB, yB);
}
void nhaptoado(int& x, int& y) {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
}
//check A có đi tới B theo hướng đông bắc hay không
bool checktoado(int xA, int yA, int xB, int yB) {
    if (xA > xB || yA > yB) {
        return false;
    }
    return true;
}
bool checkKhungLuoi(int x, int y) {
    return x >= 0 && x < 10 &&
        y >= 0 && y < 10;
}
void inputtoado(int& xA, int& yA, int& xB, int& yB) {

    do {
        cout << "Nhap toa do diem A:" << endl;
        nhaptoado(xA, yA);

        cout << "Nhap toa do diem B:" << endl;
        nhaptoado(xB, yB);

        if (!checkKhungLuoi(xA, yA) ||
            !checkKhungLuoi(xB, yB)) {

            cout << "Toa do phai nam trong khung luoi 10x10!"
                << endl;
        }
        else if (!checktoado(xA, yA, xB, yB)) {

            cout << "A phai nam ve phia Tay Nam cua B!"
                << endl;
        }

    } while (!checkKhungLuoi(xA, yA) ||
        !checkKhungLuoi(xB, yB) ||
        !checktoado(xA, yA, xB, yB));
}
//////////////////////////////////////////////////////

//cau 3
bool laSoNguyenTo(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool laSoDoiXung(int n) {
    int banDau = n;
    int dao = 0;

    while (n > 0) {
        int chuSo = n % 10;
        dao = dao * 10 + chuSo;
        n = n / 10;
    }

    return banDau == dao;
}
void nhapn(int& n) {
    do {
        cout << "Nhap so luong phan tu (n >= 10): ";
        cin >> n;
    } while (n < 10);
}

void inputArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}
void outsonguyento(int* a, int n) {
    cout << "Cac so nguyen to trong mang la: ";
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
void outsodoiXung(int* a, int n) {
    cout << "Cac so doi xung trong mang la: ";
    for (int i = 0; i < n; i++) {
        if (laSoDoiXung(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
//////////////////////////////////////////////////////

int main()
{
    //cau 1
    int n;
    int arr[20][20];

    input(n);
    vematranxoanoc(arr, n);

    //cau 2
    int xB, yB, xA, yA;
    inputtoado(xA, yA, xB, yB);

    cout << "So duong di: "
        << soDuongDi(xA, yA, xB, yB);
    cout << endl;

    //cau 3
    int m;
    nhapn(m);
    int* a = new int[m];
    inputArray(a, m);
    outsonguyento(a, m);
    outsodoiXung(a, m);

    delete[] a;
    return 0;
}

