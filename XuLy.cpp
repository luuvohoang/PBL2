#include<iostream>
#include <fstream>
#include "NhanSu.h"
#include <string>
using namespace std;
void NhanSu :: Xuat (){
    cout <<"\n Ma: " << maNV;
    cout <<"\n Ho ten: " << hoTen;
    cout << "\n Ngay thang nam sinh: " << namSinh.getNgay() <<"/" << namSinh.getThang() <<"/" << namSinh.getNam();
    cout << "\n Gioi Tinh: " << gioiTinh;
    char a = maNV[1];
    string s;
    if(a == '1') s = "Ha Noi";
    else s= "Da Nang";
    cout << "\n Don vi: " << s;
    a = maNV[3];
    if(a == '1') s = "Giam Doc";
    else if(a == '2') s = "Pho Giam Doc";
    else if(a == '3') s = "Truong Phong";
    else if(a == '4') s = "Pho Phong";
    else s = "Nhan Vien";
    cout << "\n Chuc vu: " <<  s;
}
void Menu(NhanSu *ds[], int &n){
    
    ifstream filein;
    filein.open("NhanSu.txt", ios_base::in);
    // fileout.open("DanhSachNhanVien.txt", ios_base::out);

    while (true){
        cout << "\n\n\t\t ====== MENU ======";
        cout << "\n 1. Doc thong tin nhan vien";
        cout << "\n 2. Xuat thong tin nhan vien";
        cout << "\n 0. Ket thuc";
        cout << "\n\n\t\t ====== END ======";

        int luachon;
        cout << "\n Nhap lua chon: ";
        cin >> luachon;
        // int n;
        // filein >> n;
        // cout << n;
        if(luachon == 1){
            filein >> n;
            // nhanvien *x = NULL; 
            for(int i = 0; i < n; i++){
                NhanSu *x = new NhanSu();
                x->DocFile(filein);
                ds[i] = x;
            }
        }
        else if(luachon == 2){
            for(int i=0;i<n;i++){
                cout << "\n\n\t NHAN VIEN THU " << i+1 << endl;
                ds[i]->Xuat();
            }
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