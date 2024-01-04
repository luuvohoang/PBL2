#pragma once
#include<bits/stdc++.h>
using namespace std;


class GiamDoc
{
protected:
    double HSLuongGiamDoc = 8.56;
    double phuCap_GD;
    string ma_GD;
public:
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
    double getLuongGD(){
        return HSLuongGiamDoc;
    }
};

