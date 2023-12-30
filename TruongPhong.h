#include <iostream>
using namespace std;
#pragma one 

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
};

TruongPhong::TruongPhong(/* args */)
{
}

TruongPhong::~TruongPhong()
{
}
