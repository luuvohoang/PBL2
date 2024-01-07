#include "DonVi.h"

int DonVi::countDV = 0;

void DonVi::NhapDV(NhanSu *a){
    this->MaDV += a->getMaDV();
    if(MaDV == "01") this->TenDV += "Ke Toan";
    if(MaDV == "02") this->TenDV += "Nhan Su";
    if(MaDV == "03") this->TenDV += "Ky Thuat";
    if(a->getGT().length() > 3)this->TiLeNam ++;
    else this->TiLeNu ++;
    this->ThucLinh += a->getLuong();
    // cout << a->getMaDV() <<"3 " <<this->TenDV << endl;
}
bool DonVi::check( NhanSu* b){
    string s = this->getMaDV1();
    string ss = b->getMaDV();
    if(  s == ss){
        // string s = this->getMaDV1();
        // cout << s << "2";
        
        return 1;
    }
    else return 0;
}
void DonVi:: CapNhat(NhanSu* a){
    this->SL_NV++;
    if(a->getGT().length() > 3)this->TiLeNam ++;
    else this->TiLeNu ++;
    this->ThucLinh += a->getLuong();
}
void DonVi::Xuat(ofstream &fileout){
    fileout <<"\t\t|"<<this->MaDV;
    fileout <<"\t\t\t|" <<this-> TenDV;
    fileout << "\t\t|" <<this-> SL_NV << "  ";
    fileout << "\t\t\t\t\t|" <<this-> MaxNV << "  \n";
}

void DonVi::XuatBangThongKe(ofstream &fileout){
    fileout << this->TenDV;
    if(TenDV.length() < 10) {
        int l = TenDV.length();
        while(l < 10){
            fileout << " ";
            l++;
        }
    }
    fileout << "\t\t|"<<this->SL_NV;
    fileout << "\t\t\t\t\t|" << fixed << setprecision(2) << TiLeNam*100/SL_NV;
    fileout << "\t\t|"<< fixed << setprecision(2) << TiLeNu*100/SL_NV;
    fileout << "\t\t|" << (unsigned long long)this->ThucLinh;
    fileout << "\n";
}