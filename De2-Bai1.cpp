// KTLT_BaiTapChuong3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int MAX = 20;

//void xuatMaTran(int a[MAX][MAX], int& n) {
//    int giaTri = 1;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0;j < n;j++) {
//            a[i][j] = giaTri;
//            cout << a[i][j] << "\t";
//            //cout << "a[" << i << "][" << j << "]: " << a[i][j];
//            giaTri++;
//        }
//        cout << endl;
//    }
//}


void maTranZigZag(int a[MAX][MAX], int& n) {
    int giaTri = 1;
    while (giaTri <= n * n)
    {
        for (int i = 0;i < n;i++) {
            if (i==0||i % 2 == 0) {
                for (int j = 0;j < n;j++) {
                    a[i][j] = giaTri;
                    giaTri++;
                }               
            }
            else {
                for (int j = n-1;j >=0;j--) {
                    a[i][j] = giaTri;
                    giaTri++;
                }
            }
        }
    }
}
void nhap(int& n)
{
    cout << " Nhap gia tri nguyen (n>1 && n<21): ";
    cin >> n;
    while (n < 2 || n>20)
    {
        cout << " Nhap sai. Nhap lai n (n>1 && n<21): ";
        cin >> n;
    }
}

void xuatMaTran(int a[MAX][MAX], int& n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    int a[MAX][MAX];
    nhap(n);
    maTranZigZag(a, n);
    xuatMaTran(a, n);
    return 0;
}

