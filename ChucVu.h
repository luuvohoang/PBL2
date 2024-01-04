#pragma once
#include "NhanSu.h"
class ChucVu : public NhanSu
{
protected:
    vector<pair<string,string>> MaCV;
    int SL_CV = 1;
    const int MaxCV = 20;
public:
    static int countCV;
    virtual void CapNhat(NhanSu*);
    virtual void DocFileCV(ifstream &);
    virtual void NhapCV(NhanSu*);
    bool check(NhanSu*);
    virtual void XuatCV(ofstream &);
};


