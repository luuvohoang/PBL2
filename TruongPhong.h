#pragma once 
#include<bits/stdc++.h>
using namespace std;

class TruongPhong
{
private:
    double HSLuongTruongPhong = 5.45;
    double phuCap_TP;
    string ma_TP;
public:
    TruongPhong(/* args */);
    ~TruongPhong();
    void setTP(double HSLuong)
    {
        this->HSLuongTruongPhong = HSLuong;
    }
    void setPC_TP(double phuCap)
    {
        this->phuCap_TP = phuCap;
    }
    double getLuongTP(){
        return HSLuongTruongPhong;
    }
};


