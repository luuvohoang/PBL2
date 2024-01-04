#pragma once 
#include<bits/stdc++.h>
using namespace std;

class TruongPhong
{
private:
    double HSLuongTruongPhong = 5.45;
    double phuCap_TP;
    
public:
    static string ma_TP;
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
    void setMa_TP(string ma){
        this->ma_TP = ma;
    }
    double getLuongTP(){
        return HSLuongTruongPhong;
    }
};


