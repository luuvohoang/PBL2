#pragma once 
#include<bits/stdc++.h>
using namespace std;


class NhanVien
{
protected:
    double HSLuongNhanVien = 3.63;
    double phuCap_NV;
    
public:
    static string ma_NV;
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
    void setMa_NV(string ma){
        this->ma_NV = ma;
    }
    double getLuongNV(){
        return HSLuongNhanVien;
    }
};


