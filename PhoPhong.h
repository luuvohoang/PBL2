#pragma once 
#include<bits/stdc++.h>
using namespace std;


class PhoPhong
{
protected:
    double HSLuongPhoPhong = 4.32;
    double phuCap_PP;
    string ma_PP;
public:
    PhoPhong(/* args */);
    ~PhoPhong();
    void setPP(double HSLuong)
    {
        this->HSLuongPhoPhong = HSLuong;
    }
    void setPC_PP(double phuCap)
    {
        this->phuCap_PP = phuCap;
    }
    double getLuongPP(){
        return HSLuongPhoPhong;
    }
};


