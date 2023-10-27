#include<iostream>
#include <fstream>
#include "NhanSu.h"
#include <string>
using namespace std;

void Menu(NhanSu *ds[], int &n){
    
    ifstream filein;
    filein.open("NhanSu.txt", ios_base::in);
    // fileout.open("DanhSachNhanVien.txt", ios_base::out);

    while (true){
        cout << "\n\n\t\t\t\t================ MENU  ==============";
        cout << "\n\n\t\t\t\t 1. Doc thong tin nhan vien";
        cout << "\n\t\t\t\t 2. Xuat thong tin nhan vien";
        cout << "\n\t\t\t\t 0. Ket thuc";
        cout << "\n\n\t\t\t\t=====================================";

        int luachon;
        cout << "\n\n\t\t\t\tNhap lua chon: ";
        cin >> luachon;
  
        if(luachon == 1){
            filein >> n;
            // nhanvien *x = NULL; 
            for(int i = 0; i < n; i++){
                NhanSu *x = new NhanSu();
                x->DocFile(filein);
                ds[i] = x;
            }
            cout << "\n\t\t\t\tDa Doc Thong Tin Nhan Vien !\n";
        }
        else if(luachon == 2){
            for(int i=0;i<n;i++){
                cout << "\n\t\t\t\t" <<i+1<<".  NHAN VIEN THU " << i+1 << endl;
                ds[i]->Xuat();
                cout << "\n\t\t\t\t=====================================";
            }
                cout << "\n\t\t\t\t=====================================";
        }
        else {
            break;
        }
        // break;
    }
    filein.close();
}

int main(){
    NhanSu *ds[10000];
    int n = 0;
    Menu(ds, n);
}