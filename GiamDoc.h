#pragma once
#include<bits/stdc++.h>
using namespace std;


class GiamDoc
{
protected:
    double HSLuongGiamDoc = 8.56;
    double phuCap_GD;
    
public:
    static string ma_GD;
    GiamDoc(/* args */);
    ~GiamDoc();
    void setGD(double HSLuong)
    {
        this->HSLuongGiamDoc = HSLuong;
    }
    void setPC_GD(double phuCap)
    {
        this->phuCap_GD = phuCap;
    }
    void setMa_GD(string ma){
        this->ma_GD = ma;
    }
    double getLuongGD(){
        return HSLuongGiamDoc;
    }
};

