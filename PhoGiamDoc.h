#include <iostream>
using namespace std;
#pragma one 

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
};

PhoGiamDoc::PhoGiamDoc(/* args */)
{
}

PhoGiamDoc::~PhoGiamDoc()
{
}
