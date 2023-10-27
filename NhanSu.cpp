#include "NhanSu.h"
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

void NhanSu :: DocFile(ifstream &filein){
    char a;
    filein >> a;
    string mnv;
    getline(filein, mnv, ',');
    maNV = a + mnv;
    // cout << maNV << endl;
    string ten;
    filein >> a;
    getline(filein, ten, ',');
    hoTen = a + ten;
    // cout << hoTen << endl;
    int ngay, thang, nam;
    filein >> ngay;
    namSinh.setNgay(ngay);
    filein >> a;
    filein >> thang;
    namSinh.setThang(thang);
    filein >> a;
    filein >> nam;
    namSinh.setNam(nam);
    filein >> a;
    // cout <<ngay<<"/" << thang <<"/" << nam << endl;
    string gt;
    getline(filein, gt, ',');
    gioiTinh = gt;
    // cout << gioiTinh << endl;
    int ngay1, thang1, nam1;
    filein >> a;
    filein >> ngay1;
    ngayVaoLam.setNgay(ngay1);
    filein >> a;
    filein >> thang1;
    ngayVaoLam.setThang(thang1);
    filein >> a;
    filein >> nam1;
    ngayVaoLam.setNam(nam1);
}   
void NhanSu :: Xuat(){
    cout <<"\n\t\t\t\t Ma: " << maNV;
    cout <<"\n\t\t\t\t Ho ten: " << hoTen;
    cout << "\n\t\t\t\t Ngay thang nam sinh: " << namSinh.getNgay() <<"/" << namSinh.getThang() <<"/" << namSinh.getNam();
    cout << "\n\t\t\t\t Gioi Tinh:" << gioiTinh;
    char a = maNV[1];
    string s;
    if(a == '1') s = "Ha Noi";
    else s = "Da Nang";
    cout << "\n\t\t\t\t Don vi: " << s;
    a = maNV[3];
    if(a == '1') s = "Giam Doc";
    else if(a == '2') s = "Pho Giam Doc";
    else if(a == '3') s = "Truong Phong";
    else if(a == '4') s = "Pho Phong";
    else s = "Nhan Vien";
    cout << "\n\t\t\t\t Chuc vu: " <<  s;
    cout << "\n\t\t\t\t Ngay vao lam: " << ngayVaoLam.getNgay() <<"/" << ngayVaoLam.getThang() <<"/" << ngayVaoLam.getNam();
}