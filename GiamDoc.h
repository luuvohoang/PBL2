#include <iostream>
using namespace std;
#pragma one 

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
};

GiamDoc::GiamDoc(/* args */)
{
}

GiamDoc::~GiamDoc()
{
}
