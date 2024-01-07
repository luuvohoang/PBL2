#include "ChucVu.h"

int ChucVu::countCV = 0;

void ChucVu::NhapCV(NhanSu *a){
    this->MaCV += a->getMaCV();
    if(MaCV == "01") this->TenCV += "Giam Doc";
    if(MaCV == "02") this->TenCV += "Pho Giam Doc";
    if(MaCV == "03") this->TenCV += "Truong Phong";
    if(MaCV == "04") this->TenCV += "Pho Phong";
    if(MaCV == "05") this->TenCV += "Nhan Vien";
    // cout << a->getMaDV() <<"3 " <<this->TenDV << endl;
}
bool ChucVu::check( NhanSu* b){
    string s = this->getMaCV1();
    string ss = b->getMaCV();
    if(  s == ss){
        // string s = this->getMaDV1();
        // cout << s << "2";
        return 1;
    }
    else return 0;
}
void ChucVu::CapNhat(NhanSu* a){
    this->SL_CV++;
}
void ChucVu::Xuat(ofstream &fileout){
    fileout <<"\t\t|"<<this->MaCV;
    fileout <<"\t\t\t|" <<this-> TenCV;
    if(TenCV.length() < 12) {
        int l = TenCV.length();
        while(l < 12){
            fileout << " ";
            l++;
        }
    }
    fileout << "\t\t|" <<this-> SL_CV;
    fileout << "\t\t\t\t\t\t|" <<this-> MaxCV << "\n";
}
