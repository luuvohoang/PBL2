#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class date{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        int getNgay(){
            return ngay;
        }
        void setNgay(int NGAY){
            ngay = NGAY;
        }
        int getThang(){
            return thang;
        }
        void setThang(int THANG){
            thang = THANG;
        }
        int getNam(){
            return nam;
        }
        void setNam(int NAM){
            nam = NAM;
        }
};

class NhanSu{
    protected:
        
        string maNV;
        string hoTen;
        date namSinh;
        string gioiTinh;
        string donVi;
        string chucVu;
        double heSo;
        double luong;
        double phuCap;
        double thucLinh;
        date ngayVaoLam;
    public:
        static int countnv;
        virtual void DocFile(ifstream &);
        virtual void Nhap();
        virtual void Xuat();
        virtual void XuatFile(ofstream &); 
        void TimKiem();
};