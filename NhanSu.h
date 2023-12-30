#pragma once
#include "NhanVien.h"
#include "PhoPhong.h"
#include "TruongPhong.h"
#include "PhoGiamDoc.h"
#include "GiamDoc.h"

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
class NhanSu : public NhanVien, public PhoPhong, public TruongPhong, public PhoGiamDoc, public GiamDoc
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
        date ngayVaoLam;
        long double ThucLinh = 0;
        double LuongCoBan = 1.8;

    public:
        static int countnv;
        virtual void DocFile(ifstream &);
        virtual void DocHSLuong(ifstream &);
        virtual void DocMaDV(ifstream &);
        virtual void DocMaCV(ifstream &);
        virtual void Nhap(string);
        virtual void Xuat();
        virtual void XuatFile(ofstream &); 
        virtual void TimKiem(NhanSu*);
        virtual void TimKiemNS(string);
        virtual void TinhLuong();
        virtual void ChangeNVL(string);
        virtual void ChangeNTNS(string);
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
        date getNgayVaoLam()
        {
            return ngayVaoLam;
        }
        date getNamSinh()
        {
            return namSinh;
        }
        void setHotenMoi(string hotenmoi)
        {
           this->hoTen.clear();
           this->hoTen += hotenmoi;
            // cout << this->hoTen;
        }
        int& operator[]( int&);
        void setMaDVmoi(string MaDVmoi)
        {
            maNV[0]=MaDVmoi[0];
            maNV[1]=MaDVmoi[1];
        }
        void setMaCVmoi(string maCVmoi)
        {
            maNV[2]=maCVmoi[0];
            maNV[3]=maCVmoi[1];
        }
        void getGioiTinh(string gioitinh)
        {
            this->gioiTinh=gioitinh;
        }
};