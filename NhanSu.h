#pragma once
#include<bits/stdc++.h>
using namespace std;

class date
{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        const date& operator=(const date& d){
            if(this != &d)
            {
                this->ngay = d.ngay;
                this->thang = d.thang;
                this->nam = d.nam;
            }
            return *this;
        }
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
// struct date{
//     int ngay;
//     int thang;
//     int nam;
// };
class NhanSu
{
    protected:       
        string maNV;
        string hoTen;
        date namSinh;
        string gioiTinh = "";
        string donVi;
        string chucVu;
        double heSo;
        double luong;
        double phuCap;
        date ngayVaoLam;

        long double ThucLinh = 0;
        double LuongCoBan = 1800000;
        double HSLuongGiamDoc = 8.56;
        double HSLuongPhoGiamDoc = 6.78;
        double HSLuongTruongPhong = 5.45;
        double HSLuongPhoPhong = 4.32;
        double HSLuongNhanVien = 3.63;
    public:
        static int countnv;
        
        virtual void DocFile(ifstream &);
        virtual void Nhap(string);
        virtual void Xuat();
        virtual void XuatFile(ofstream &); 
        virtual void TimKiem(NhanSu*);
        virtual void TimKiemNS(string);
        virtual void TinhLuong();
        const NhanSu& operator=(const NhanSu&);
        string getMaDV(){
            string x;
            x += maNV[0];
            x += maNV[1];
            return x;
        }
        string getHoTen(){
            return hoTen;
        }
        string getMaNV(){
            return maNV;
        }
        string getMaCV(){
            string x;
            x += maNV[2];
            x += maNV[3];
            return x;
        }
        
        string getGT(){
            return gioiTinh;
        }
        double getLuong(){
            return ThucLinh;
        }
            
        int& operator[]( int&);
};
