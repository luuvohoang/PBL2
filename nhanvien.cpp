#include "nhanvien.h"
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

void nhanvien :: DocFile(ifstream &filein){
    char a;
    filein >> a;
    string s;
    getline(filein, s, ',');
    maNV = a + s;
    // cout << maNV << endl;
    filein >> a;
    getline(filein, s, ',');
    hoTen = a + s;
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
    filein >> gioiTinh;
    cout << gioiTinh << endl;
}   