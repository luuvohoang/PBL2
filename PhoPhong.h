#pragma once 
#include<bits/stdc++.h>
using namespace std;


class PhoPhong
{
protected:
    double HSLuongPhoPhong = 4.32;
    double phuCap_PP;
    
public:
    static string ma_PP;
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
    void setMa_PP(string ma){
        this->ma_PP = ma;
    }
    double getLuongPP(){
        return HSLuongPhoPhong;
    }
};


