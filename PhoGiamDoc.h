#pragma once 
#include<bits/stdc++.h>
using namespace std;


class PhoGiamDoc
{
protected:
    double HSLuongPhoGiamDoc = 6.78;
    double phuCap_PGD;
    string ma_PGD;
public:
    PhoGiamDoc(/* args */);
    ~PhoGiamDoc();
    void setPGD(double HSLuong)
    {
        this->HSLuongPhoGiamDoc = HSLuong;
    }
    void setPC_PGD(double phuCap)
    {
        this->phuCap_PGD = phuCap;
    }
    double getLuongPGD(){
        return HSLuongPhoGiamDoc;
    }
};


