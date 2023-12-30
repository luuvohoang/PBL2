#include <iostream>
using namespace std;
#pragma one 

class NhanVien
{
protected:
    double HSLuongNhanVien = 3.63;
    double phuCap_NV;
    string ma_NV;
public:
    NhanVien(/* args */);
    ~NhanVien();
    void setLNV(double HSLuong)
    {
        this->HSLuongNhanVien = HSLuong;
    }
    void setPC(double phuCap)
    {
        this->phuCap_NV = phuCap;
    }
};

NhanVien::NhanVien(/* args */)
{
}

NhanVien::~NhanVien()
{
}
