#include "NhanSu.h"
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
//      g++ XuLy.cpp NhanSu.cpp DonVi.cpp ChucVu.cpp -o aa
int NhanSu::countnv = 0;

void NhanSu :: TinhLuong(){
    if(this->getMaCV() == "01"){
        ThucLinh += LuongCoBan * HSLuongGiamDoc;
    }
    if(this->getMaCV() == "02"){
        ThucLinh += LuongCoBan * HSLuongPhoGiamDoc;
    }
    if(this->getMaCV() == "03"){
        ThucLinh += LuongCoBan * HSLuongTruongPhong;
    }
    if(this->getMaCV() == "04"){
        ThucLinh += LuongCoBan * HSLuongPhoPhong;
    }
    if(this->getMaCV() == "05"){
        ThucLinh += LuongCoBan * HSLuongNhanVien;
    }
}

void NhanSu :: DocFile(ifstream &filein){
    char a;
    filein >> a;
    string mnv;
    getline(filein, mnv, ',');
    maNV = a + mnv;
    // cout << maNV << endl;
    string ten;
    filein >> a;
    getline(filein, ten, ',');
    hoTen = a + ten;
    // cout << hoTen << endl;
    int ngay, thang, nam;
    filein >> ngay;
    namSinh.setNgay(ngay);
    filein >> a;
    filein >> thang;
    namSinh.setThang(thang);
    filein >> a;
    filein >> nam;
    namSinh.setNam(nam);
    filein >> a;
    // cout <<ngay<<"/" << thang <<"/" << nam << endl;
    string gt;
    getline(filein, gt, ',');
    gioiTinh = gt;
    // cout << gioiTinh << endl;
    int ngay1, thang1, nam1;
    filein >> a;
    filein >> ngay1;
    ngayVaoLam.setNgay(ngay1);
    filein >> a;
    filein >> thang1;
    ngayVaoLam.setThang(thang1);
    filein >> a;
    filein >> nam1;
    ngayVaoLam.setNam(nam1);
}   

void NhanSu :: Nhap(string s){
    int flag = 1;
    int d, m ,y;
    maNV = s;
    // cin >> maNV;
    cout << "\t\t\t\t Ten Nhan Vien: ";
    // char ten[50];
    string ten;
    getline(cin, ten);
    getline(cin, ten);
    hoTen = ten;
    cout << "\t\t\t\t Ngay sinh: ";
    string ntns;
    cin >> ntns;
    int flags = 1;
    int hold = 0;
    do{
        if(d>31||d<1||m<=0||m>12||y<=1950||y>=2000)
        cout<<"\t\t\t\tNgay thang nam khong hop le\n\t\t\t\tNhap lai!"<<endl;
      
     cout << "\t\t\t\t Ngay sinh: ";
    cin >> ntns;
     flags = 1;
     hold = 0;
    for(int i=0;i<ntns.length();i++){
        if(ntns[i]!='/'){
            hold*=10, hold+=ntns[i]-48;
        }
        else {
            if(flags == 1){
                d=hold;
                namSinh.setNgay(hold);
            }
            else if(flags == 2){
                m=hold;
                namSinh.setThang(hold);
            }
            hold = 0;
            flags++;
        }
    }
    y=hold;
    namSinh.setNam(hold);
    }while(d>31||d<1||m<=0||m>12||y>=2000||y<=1950);

    cout << "\t\t\t\t Gioi Tinh: ";
    string gt;
    cin >> gt;
    gt[0] = toupper(gt[0]);
   for(int i=1; i<gt.length(); i++)
    {
      gt[i]=tolower(gt[i]);
      
    }
     gioiTinh+=gt;
do{
   cout<<"\t\t\t\tGioi tinh khong dung\n\t\t\t\tNhap lai!"<<endl;
     cin >> gt;
    gioiTinh+=" ";
    gt[0] = toupper(gt[0]);
     
   for(int i=1; i<gt.length(); i++)
    {
      gt[i]=tolower(gt[i]);
    }
    gioiTinh+=gt;

}while(gioiTinh!=" Nam"&&gioiTinh!=" Nu");

    cout << "\t\t\t\t Ngay vao lam: ";
    string nvl;
    cin >> nvl;
    flags = 1;
    hold = 0;
    for(int i=0;i<nvl.length();i++){
        if(nvl[i]!='/'){
            hold*=10, hold+=nvl[i]-48;
        }
        else {
            if(flags == 1){
                ngayVaoLam.setNgay(hold);
            }
            else if(flags == 2){
                ngayVaoLam.setThang(hold);
            }
            hold = 0;
            flags++;
        }
    }
    ngayVaoLam.setNam(hold);
    cout << "\n\t\t\t\t Thanh cong them nhan vien !\n";
}
void NhanSu :: Xuat(){
    cout <<"\n\t\t\t\t Ma: " << maNV;
    cout <<"\n\t\t\t\t Ho ten: " << hoTen;
    cout << "\n\t\t\t\t Ngay thang nam sinh: " << namSinh.getNgay() <<"/" << namSinh.getThang() <<"/" << namSinh.getNam();
    cout << "\n\t\t\t\t Gioi Tinh:" << gioiTinh;
    char a = maNV[1];
    string s;
    if(a == '1') s = "Ke Toan";
    else if(a == '2') s = "Nhan Su";
    else s = "Ki Thuat";
    cout << "\n\t\t\t\t Don vi: " << s;
    a = maNV[3];
    if(a == '1') s = "Giam Doc";
    else if(a == '2') s = "Pho Giam Doc";
    else if(a == '3') s = "Truong Phong";
    else if(a == '4') s = "Pho Phong";
    else s = "Nhan Vien";
    cout << "\n\t\t\t\t Chuc vu: " <<  s;
    cout << "\n\t\t\t\t Ngay vao lam: " << ngayVaoLam.getNgay() <<"/" << ngayVaoLam.getThang() <<"/" << ngayVaoLam.getNam();
}
void NhanSu :: XuatFile(ofstream &fileout){
    fileout <<" |"<<maNV;
    fileout <<"\t\t|" << hoTen;
    if(hoTen.length() < 20) {
        int l = hoTen.length();
        while(l < 20){
            fileout << " ";
            l++;
        }
    }
    fileout << "\t|" << namSinh.getNgay() <<"/" << namSinh.getThang() <<"/" << namSinh.getNam();
    fileout << "\t|" << gioiTinh << "  ";
    if(gioiTinh[0] == 'N'&&gioiTinh[1]=='u') {
        int l = 2;
        while(l < 8){
            fileout << " ";
            l++;
        }
    }
    char a = maNV[1];
    string s;
    if(a == '1') s = "Ke Toan";
    else if(a == '2') s = "Nhan Su";
    else s = "Ki Thuat";
    fileout  << "\t\t |" << s;
    a = maNV[3];
    if(a == '1') s = "Giam Doc";
    else if(a == '2') s = "Pho Giam Doc";
    else if(a == '3') s = "Truong Phong";
    else if(a == '4') s = "Pho Phong";
    else s = "Nhan Vien";
    fileout  << "\t|" <<  s;
    if(s.length() < 12) {
        int l = s.length();
        while(l < 12){
            fileout <<  " ";
            l++;
        }
    }
    fileout << "\t|" << ngayVaoLam.getNgay() <<"/" << ngayVaoLam.getThang() <<"/" << ngayVaoLam.getNam() << "\n";
}

void NhanSu::TimKiemNS(string s){
    int flag = 1;
    ifstream filein;
    ofstream fileout;
    string ss = this->hoTen;
    cout << "/"<<ss<<"/" << endl;
    for(int i=0;i<ss.length();i++){
        ss[i] = tolower(ss[i]);
    }
    cout << "/"<<ss<<"/" << endl;
    for(int j =  0 ;j < ss.length()-s.length();j++){
        for(int i=0;i<s.length();i++){
            if(s[i] != ss[i+j]){
                // cout << s[i] << " " << ss[i] << endl;
                flag = 0;
                break;
            }
        }
    }
    if(flag == 1){
        fileout.open("TimKiemNhanVien.txt", ios_base::out);
        // fileout << "DVi\t |Ma Nhan Vien\t|Ho va Ten\t\t\t\t|Nam Sinh \t| Gioi Tinh \t |Don Vi \t|Chuc Vu \t\t|Ngay Vao Lam \n";
        this->XuatFile(fileout);
        // cout << "\n\t\t\t\t Da xuat du lieu ra file DanhsachNhanSu.txt !\n";
        fileout.close();  
    }
}
void NhanSu::TimKiem(NhanSu *ds)
{
    int e=0, pt;
    string a;
    char op = tolower('A');
    cout<<"\nChon phuong thuc tim kiem:\n1. Tim kiem theo ten\n2. Tim kiem theo ma nhan vien\n3. Tim kiem theo don vi\n";
        cin>>pt;
        cout<<ds[1].maNV<<endl;
    // if(pt==1)
    // {
    //      cout<<"Nhap ten nhan vien can tim: "<<endl;
    //         cin>>a;
    //         for(int i = 0; i<NhanSu::countnv; i++)
    //     {
    //         if(tolower(a)==tolower(ds[i].hoTen))
    //         {
    //             e=1;
    //             ds[i].Xuat();
    //             cout<<endl;
    //         }
    //         else if((ds[i].hoTen).find(a)!= std::string::npos)
    //         {
    //              e=1;
    //             ds[i].Xuat();
    //             cout<<endl;
    //         }
    //         else e=0;
          
    //     }

    // }
        // if(pt==2)
        // {
             
        //     cout<<"Nhap ma nhan vien can tim: "<<endl;
        //     cin>>a;
        //     for(int i = 0; i<NhanSu::countnv; i++)
        // {
        //     if(a.compare(ds[i].maNV)==0)
        //     {
        //         e=1;
        //         ds[i].Xuat();
        //         cout<<endl;
        //     }
        //     else if((ds[i].maNV).find(a)!= std::string::npos)
        //     {
        //          e=1;
        //         ds[i].Xuat();
        //         cout<<endl;
        //     }
        //     else e=0;
          
        // }

       
        // }
        //  if(e==0) 
        // {
        //     cout<<"Khong co nhan vien"<<endl;
        //     e=1;
        // }
        

     
}

const NhanSu& NhanSu::operator=(const NhanSu& p){
    if(this != &p){
        // cout << "=" <<endl;
        this->maNV = p.maNV;
        this->hoTen = p.hoTen;
        this->namSinh = p.namSinh;
        this->gioiTinh = p.gioiTinh;
        this->donVi = p.donVi;
        this->chucVu = p.chucVu;
        this->heSo = p.heSo;
        this->luong = p.luong;
        this->phuCap = p.phuCap;
        this->ngayVaoLam = p.ngayVaoLam;
        this->ThucLinh = p.ThucLinh;
    }
    return *this;
}