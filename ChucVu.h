#pragma once
#include "NhanSu.h"
class ChucVu : public NhanSu
{
protected:
    string MaCV;
    string TenCV;
    int SL_CV = 1;
    const int MaxCV = 20;
public:
    static int countCV;
    string getMaCV1(){
        return MaCV;
    }
    virtual void NhapCV(NhanSu*);
    virtual void CapNhat(NhanSu*);
    bool check(NhanSu*);
    virtual void Xuat(ofstream &);
};


