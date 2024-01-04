#include "ChucVu.h"

int ChucVu::countCV = 0;

bool ChucVu::check( NhanSu* b){
    string s = this->getMaCV();
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

void ChucVu::NhapCV(NhanSu* a){
    MaCV[countCV].first = a->getMaCV();
    MaCV[countCV].second = a->getTenCV();
}

void ChucVu::DocFileCV(ifstream &filein){
    string s;
    filein >> s;
    string cv;
    filein >> cv;
    MaCV.push_back({s,cv});

} 
void ChucVu::XuatCV(ofstream &fileout){

    for(int i=0;i<countCV;i++){
        fileout <<" |" << this->MaCV[i].first;
        fileout <<"\t\t|" <<this->MaCV[i].second;
        if(chucVu.length() < 20) {
            int l = chucVu.length();
            while(l < 20){
                fileout << " ";
                l++;
            }
        }
        fileout << "\t|" <<this-> SL_CV << "  ";
        fileout << "\t|" <<this-> MaxCV << "  \n";
    }
    
}
