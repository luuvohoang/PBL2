#pragma once
#include "NhanSu.h"
class DonVi : public NhanSu
{
protected:
    string MaDV;
    string TenDV;
    int SL_NV = 1;
    const int MaxNV = 20;
    double TiLeNam = 0;
    double TiLeNu = 0;
    double TongThucLinh = 0;
public:
    static int countDV;
    string getMaDV1(){
        return MaDV;
    }
    void setTiLeNam(double x){
        this->TiLeNam = x;
    }
    void setTiLeNu(double x){
        this->TiLeNu = x;
    }
    virtual void NhapDV(NhanSu*);
    virtual void CapNhat(NhanSu*);
    bool check(NhanSu*);
    virtual void Xuat(ofstream &);
    virtual void XuatBangThongKe(ofstream &);
};


