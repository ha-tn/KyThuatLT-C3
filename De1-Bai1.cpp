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
void MaTranXoanOc(int a[MAX][MAX], int& n) 
{
    int giaTri = 1;
    int tren = 0;
    int phai = n - 1;
    int duoi = n - 1;
    int trai = 0;
    while (giaTri <= n * n)
    {
            //chay tu trai --> phai
            for (int i = trai; i <= phai;i++) {
                a[tren][i] = giaTri;
                giaTri++;
            }
            tren++;

            //chay tu tren--> duoi 
            for (int i = tren;i <= duoi;i++) {
                a[i][phai] = giaTri;
                giaTri++;
            }
            phai--;

            //chay tu phai--> trai
            for (int i = phai;i >= trai; i--) {
                a[duoi][i] = giaTri;
                giaTri++;
            }duoi--;

            //chay tu duoi--> tren
            for (int i = duoi;i >= tren;i--) {
                a[i][trai] = giaTri;
                giaTri++;
            }
            trai++;
     }

}

void nhap(int &n)
{
    cout << " Nhap gia tri nguyen (n>1 && n<21): ";
    cin >> n;
    while (n < 2 || n>20)
    {
        cout << " Nhap sai. Nhap lai n (n>1 && n<21): ";
        cin >> n;
    }
}

void xuatMaTran(int a[MAX][MAX], int& n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j]<<"\t";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    int a[MAX][MAX];
    nhap(n);
    MaTranXoanOc(a, n);
    xuatMaTran(a, n);
    return 0;
}

