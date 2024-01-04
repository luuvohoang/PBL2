#pragma once 
#include<bits/stdc++.h>
using namespace std;


class PhoGiamDoc
{
protected:
    double HSLuongPhoGiamDoc = 6.78;
    double phuCap_PGD;
    
public:
    static string ma_PGD;
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
    void setMa_PGD(string ma){
        this->ma_PGD = ma;
    }
    double getLuongPGD(){
        return HSLuongPhoGiamDoc;
    }
};


