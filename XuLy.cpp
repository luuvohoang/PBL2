#include<iostream>
#include <fstream>
#include "NhanSu.h"
#include "DonVi.h"
#include "ChucVu.h"
#include <cstring> 
#include <string>
using namespace std;
NhanSu *ds[10000];
// NhanSu *ds1[10000];
string ma1, ma2;

string _tachten1nguoi ( string hoten)
{
    std::size_t space_pos = hoten.find_last_of(' ');
    std::string ten = hoten.substr(space_pos + 1);
    return ten;
}

string _tachho1nguoi(string hoten)
{

    std::size_t space_pos = hoten.find(' ');
    std::string ho_dem = hoten.substr(0, space_pos);
        return ho_dem;
}

// g++ XuLy.cpp NhanSu.cpp DonVi.cpp ChucVu.cpp -o a

void Xuat(){
    
    ifstream filein;
    ofstream fileout;
    // cap nhat file DanhSachNhanSu
    fileout.open("DanhsachNhanSu.txt", ios_base::out);
    fileout << "DVi\t |Ma Nhan Vien\t|Ho va Ten\t\t\t\t|Nam Sinh \t| Gioi Tinh \t |Don Vi \t|Chuc Vu \t\t|Ngay Vao Lam \n";
    for(int i = 0; i < NhanSu::countnv; i++){
        fileout << i+1 << "\t";
        ds[i]->XuatFile(fileout);
    }
    // cout << "\n\t\t\t\t Da xuat du lieu ra file DanhsachNhanSu.txt !\n";
    fileout.close();  


    // cap nhat file DonVi
    DonVi  *dsDV[1000];
    int countDV1 = 0;
    DonVi::countDV = 0;
    for(int i = 0; i < NhanSu::countnv;i++){
        int flag = 1, pos = 0;
        // cout << "++++" << DonVi::countDV << "++++" <<endl;
        for(int j = 0 ; j < DonVi::countDV; j++){
            if(dsDV[j]->check(ds[i])){
                flag = 0;
                pos = j;
                // cout << dsDV[j]->getMaDV1() <<"ff " << ds[i]->getMaDV() << '\n';
                // cout << pos;
            }
        }
        if(flag == 1){
            DonVi *a = new DonVi();
            a->NhapDV(ds[i]);
            dsDV[DonVi::countDV] = a;
            DonVi::countDV++;
        }
        else{
            dsDV[pos]->CapNhat(ds[i]);
        }
    }
    fileout.open("DonVi.txt", ios_base::out);
    fileout << "DVi\t|Ma DVi\t |Ten Don Vi\t|So luong Nhan Vien\t\t\t\t|So luong toi da \n";
    for(int i = 0; i < DonVi::countDV; i++){
        fileout << i+1 << "\t";
        dsDV[i]->Xuat(fileout);
    }
    // cout << "\n\t\t\t\t Da xuat du lieu ra file DonVi.txt !\n";
    fileout.close();  


    // cap nhat file ChucVu
    ChucVu  *dsCV[1000];
    int countCV1 = 0;
    ChucVu::countCV = 0;
    for(int i = 0; i < NhanSu::countnv;i++){
        int flag = 1, pos = 0;
        // cout << "++++" << DonVi::countDV << "++++" <<endl;
        for(int j = 0 ; j < ChucVu::countCV; j++){
            if(dsCV[j]->check(ds[i])){
                flag = 0;
                pos = j;
                // cout << dsDV[j]->getMaDV1() <<"ff " << ds[i]->getMaDV() << '\n';
                // cout << pos;
            }
        }
        if(flag == 1){
            ChucVu *a = new ChucVu();
            a->NhapCV(ds[i]);
            dsCV[ChucVu::countCV] = a;
            ChucVu::countCV++;
        }
        else{
            dsCV[pos]->CapNhat(ds[i]);
        }
    }
    fileout.open("ChucVu.txt", ios_base::out);
    fileout << "DVi\t\t|Ma CVu\t |Ten Chuc Vu\t\t\t\t|So luong toi da \n";
    for(int i = 0; i < ChucVu::countCV; i++){
        fileout << i+1 << "\t";
        dsCV[i]->Xuat(fileout);
    }
    // cout << "\n\t\t\t\t Da xuat du lieu ra file ChucVu.txt !\n";
    fileout.close();  


    //cap nhat file BangThongKe
    ofstream fileThongKe;
    fileThongKe.open("BangThongKe.txt", ios_base::out);
    fileThongKe << "Don Vi \t\t So Nhan Vien \t%Nam \t\t\t    %Nu \t\t\t    Tong Thuc Linh\n";
    for(int i = 0; i< DonVi::countDV;i++){
        dsDV[i]->XuatBangThongKe(fileThongKe);
    }
    fileThongKe.close();

}

void Menu(NhanSu *ds[], int &n){
    
    ifstream filein;
    ofstream fileout;
    
    filein.open("NhanSu.txt", ios_base::in);
    filein >> n;
    // nhanvien *x = NULL; 
    for(int i = 0; i < n; i++){
        NhanSu *x = new NhanSu();
        x->DocFile(filein);
        ds[i] = x;
        x->TinhLuong();
        NhanSu::countnv++;
    }
    filein.close();
    Xuat();

    while (true){
        cout << "\n\n\t\t\t\t================ MENU  ==============\n";
        cout << "\n\t\t\t\t 1. Nhap thong tin nhan vien"; // xong
        //cout << "\n\t\t\t\t 2. Xuat thong tin nhan vien"; // xong //khong can thiet
        //cout << "\n\t\t\t\t 3. In bang thong ke theo don vi"; // khong can thiet, tu dong cap nhat                    
        cout << "\n\t\t\t\t 2. Tim kiem nhan vien theo ten";  // xong
        cout << "\n\t\t\t\t 3. Tim kiem nhan vien theo ma"; //xong
        cout << "\n\t\t\t\t 4. Xoa nhan vien"; // xong
        cout << "\n\t\t\t\t 5. Xoa Chuc Vu"; 
        cout << "\n\t\t\t\t 6. Xoa Don Vi"; 
        cout << "\n\t\t\t\t 7. Sap xep";     //xong
        cout << "\n\t\t\t\t 8. Thay doi thong tin nhan vien";
        cout << "\n\t\t\t\t 0. Ket thuc";
        cout << "\n\n\t\t\t\t=====================================";

      
        
        int luachon;
        cout << "\n\n\t\t\t\t Nhap lua chon: ";
        cin >> luachon;
        // vector<NhanSu> a;
        if(luachon == 1){
            NhanSu *x = new NhanSu();
            int flag = 1;
            string s;
            do
            {
                cout << "\n\t\t\t\t Ma Nhan Vien: ";
                cin >> s;
                int flagg = 1;
                for(int i = 0 ; i < NhanSu::countnv;i++){
                    if(s == ds[i]->getMaNV()){
                        cout << "Ma da ton tai, moi nhap lai0 !\n";
                        flagg = 0;
                        break;
                    }
                }
                for(int i=0;i<s.length();i++){
                    if(s[i] - '0' < 0 || s[i] - '0' > 9){
                        cout << "Nhap ky tu khong hop le, moi nhap lai1 !\n";
                        flagg = 0;
                        break;
                    }
                }
                if(flagg == 0) continue;
                if(s.length()!=8){
                    cout << "Nhap do dai khong hop le, moi nhap lai2 !\n";
                }
                else if(s[0] != '0' || s[2] != '0'){
                    cout << "Nhap ma khong hop le, moi nhap lai3 !\n";
                }
                else if(s[1] - '0' < 1 || s[1] - '0' > 3){
                    cout << "Nhap don vi khong hop le, moi nhap lai4 !\n";
                }
                else if(s[3] - '0' < 1 || s[3] - '0' > 5){
                    cout << "Nhap chuc vu khong hop le, moi nhap lai5 !\n";
                }
                else {
                    flag = 0;
                }
            }while(flag == 1);
            x->Nhap(s);
            x->TinhLuong();
            cout << "\n\t\t\t\t Them Vao:";
            cout << "\n\t\t\t\t 1. Them Vao Dau";
            cout << "\n\t\t\t\t 2. Them Vao Cuoi";
            cout << "\n\t\t\t\t 3. Them Noi Chi Dinh";
            int choose;
            cout << "\n\t\t\t\t Nhap lua chon: ";
            cin >> choose;
            if(choose == 1){
                for(int i = NhanSu::countnv-1;i>=0;i--){
                    ds[i+1] = ds[i];
                }
                ds[0] = x;
                NhanSu::countnv++;
            }
            else if(choose == 2){
                ds[NhanSu::countnv] = x;
                NhanSu::countnv++;
            }
            else {
                cout << "\n\t\t\t\t Moi Nhap Vi Tri muon them: ";
                int pos;
                cin >> pos;
                if(pos > NhanSu::countnv){
                    pos = NhanSu::countnv;
                }
                else if(pos <= 0) pos = 1;
                pos --;
                for(int i = NhanSu::countnv;i>pos;i--){
                    ds[i] = ds[i-1];
                }
                
                ds[pos] = x;
                NhanSu::countnv++;
            }
            cout << "\n\t\t\t\t Da Doc Thong Tin Nhan Vien !\n";
            Xuat();
        }
        // xuat ra man hinh hoac file
        // xuat ra file
        // else if(luachon == 4){
            
        //     // bao gồm:
        //     // - theo đơn vị
        //     // +thông tin cá nhân
        //     // +thực lĩnh
        //     // +bảng thống kê
        // }
        else if(luachon == 2){
            fileout.open("TimKiemNhanVien.txt", ios_base::out);
            string s;
            cout << "Nhap ten can tim: ";
            getline(cin, s);
            getline(cin, s);
            for(int i=0;i<s.length();i++){
                s[i] = tolower(s[i]);
            }
            cout << "/"<<s<<"/" << endl;
            for(int i = 0; i < NhanSu::countnv;i++){
                
                ifstream fileinn;
                ofstream fileoutt;
                string ss = ds[i]->getHoTen();
                // cout << "/"<<ss<<"/" << endl;
                for(int i=0;i<ss.length();i++){
                    ss[i] = tolower(ss[i]);
                }
                // cout << "/"<<ss<<"/" << endl;
                for(int j =  0 ;j < min(ss.length()-s.length() + 1, ss.length());j++){
                    int flag = 1;
                    for(int i=0;i<s.length();i++){
                        if(s[i] != ss[i+j]){
                            // cout << s[i] << " " << ss[i] << endl;
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        // fileout << "DVi\t |Ma Nhan Vien\t|Ho va Ten\t\t\t\t|Nam Sinh \t| Gioi Tinh \t |Don Vi \t|Chuc Vu \t\t|Ngay Vao Lam \n";
                        ds[i]->XuatFile(fileout);
                        // cout << "\n\t\t\t\t Da xuat du lieu ra file DanhsachNhanSu.txt !\n";
                        break;
                    }
                }
                
            }
            cout << "/"<<s<<"/" << endl;
            fileout.close();  
        }
        else if(luachon == 3){
            fileout.open("TimKiemNhanVien.txt", ios_base::out);
            string s;
            cout << "Nhap ma can tim: ";
            getline(cin, s);
            getline(cin, s);
            int flagg = 1;
            // cout << "/"<<s<<"/" << endl;
            for(int i = 0; i < NhanSu::countnv;i++){
                
                ifstream fileinn;
                ofstream fileoutt;
                string ss = ds[i]->getMaNV();
                // cout << "/"<<ss<<"/" << endl;
                // for(int i=0;i<ss.length();i++){
                //     ss[i] = tolower(ss[i]);
                // }
                // cout << "/"<<ss<<"/" << endl;
                for(int j =  0 ;j < min(ss.length()-s.length() + 1, ss.length());j++){
                    int flag = 1;
                    for(int i=0;i<s.length();i++){
                        if(s[i] != ss[i+j]){
                            // cout << s[i] << " " << ss[i] << endl;
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        // fileout << "DVi\t |Ma Nhan Vien\t|Ho va Ten\t\t\t\t|Nam Sinh \t| Gioi Tinh \t |Don Vi \t|Chuc Vu \t\t|Ngay Vao Lam \n";
                        ds[i]->XuatFile(fileout);
                        flagg = 0;
                        // cout << "\n\t\t\t\t Da xuat du lieu ra file DanhsachNhanSu.txt !\n";
                        break;
                    }
                }
                
            }
            if(flagg == 1){
                fileout << "Khong tim thay nhan vien nao !"<< endl;
            }
            fileout.close();  
        }
        
        // xoa nhan vien
        else if(luachon == 4){
            string s;
            cout << "Nhap ten can xoa: ";
            getline(cin, s);
            getline(cin, s);
            int flagg = 0;
            for(int i=0;i<s.length();i++){
                s[i] = tolower(s[i]);
            }
            for(int i = 0; i < NhanSu::countnv;i++){

                string ss = ds[i]->getHoTen();
                // cout << "/"<<ss<<"/" << endl;
                for(int j=0;j<ss.length();j++){
                    ss[j] = tolower(ss[j]);
                }
                // cout << "/"<<ss<<"/" << endl;
                int flag = 1, pos = 0;
                // cout << ss.length() <<"Fuck"<<s.length() << endl;
                if(ss.length() != s.length()){
                    continue;
                }
                for(int j=0;j<s.length();j++){
                    if(s[j] != ss[j]){
                        // cout << s[i] << " " << ss[i] << endl;
                        flag = 0;
                        
                        break;
                    }
                }
                // cout << "balalal" << endl;
                if(flag == 1){
                    for(int j=i;j<NhanSu::countnv-1;j++){
                        ds[j] = ds[j+1];
                    }
                    
                    NhanSu::countnv --;
                    flagg = 1;
                    break;
                }           
            }
            // cout << "balalalalalallaa" << endl;
            if(flagg == 0){
                cout << "\t\t\t\t\t Nhap khong hop le !" << endl;
            }
            Xuat();
        }

        // xoa chuc vu
        else if(luachon == 5){
            
        }

        // xoa don vi
        else if(luachon == 7){

            string ten1, ten2;
            int cnt=NhanSu::countnv+1;
            int choice1, choice2, choice3;
             NhanSu *x = new NhanSu();
            cout<<"\n\t\t\t\t Chon kieu sap xep:";
            cout<<"\n\t\t\t\t 1. Sap xep theo ma nhan vien";
            cout<<"\n\t\t\t\t 2. Sap xep theo ten nhan vien";
            cout<<"\n\t\t\t\t 3. Sap xep theo tuoi nhan vien";
            cout<<"\n\t\t\t\t 4. Sap xep theo ma don vi";
            cout<<"\n\t\t\t\t 5. Sap xep theo ma chuc vu";
            cin>>choice1;
             while(choice1 !=1&&choice1!=2&&choice1!=3&&choice1!=4&&choice1!=5)
                {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice1;
                }
            if(choice1==1)
            {
                 
                cout<<"\n\t\t\t\t Sap xep theo thu tu:"<<endl;
                cout<<"\n\t\t\t\t 1. Giam dan"<<endl;
                cout<<"\n\t\t\t\t 2. Tang dan"<<endl;
                cin>>choice2;
                while(choice2 !=1&&choice2!=2)
                {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice2;
                }
              if(choice2==1)
              {
             for(int i=0; i<NhanSu::countnv; i++)
            {
                
                for(int j=i; j<NhanSu::countnv;j++)
                {
               long ma1=stol(ds[j]->getMaNV());
               long ma2=stol(ds[i]->getMaNV());
                  if(ma1>ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
                }
            }
               Xuat();
            }
          else if(choice2==2)
          {
               for(int i=0; i<NhanSu::countnv; i++)
            {
                
                for(int j=i; j<NhanSu::countnv;j++)
                {
               long ma1=stol(ds[j]->getMaNV());
               long ma2=stol(ds[i]->getMaNV());
                  if(ma1<ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
                }
            }
               Xuat();
          }

            }
            else if(choice1==2)
            {
                string ten1, ten2, ho1, ho2;
                cout<<"\n\t\t\t\t 1. Giam dan"<<endl;
                cout<<"\n\t\t\t\t 2. Tang dan"<<endl;
                cin>>choice2;
               while(choice2 !=1&&choice2!=2)
                  {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice2;
                }
                if(choice2==1)
                {
                       
                  for(int i = 0;i < NhanSu::countnv; i++) {
                 
                 for(int j = i+1; j < NhanSu::countnv; j++) {
                       ten1=_tachten1nguoi(ds[i]->getHoTen());
                       ten2=_tachten1nguoi(ds[j]->getHoTen());
            if(_stricmp(ten1.c_str(), ten2.c_str()) < 0) {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
            }
            else if(_stricmp(ten1.c_str(), ten2.c_str()) == 0)
            {
                ho1=_tachho1nguoi(ds[i]->getHoTen());
                ho2=_tachho1nguoi(ds[j]->getHoTen());
                if(_stricmp(ho1.c_str(), ho1.c_str()) < 0) {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
            }
        }
    }
            }    
               Xuat();
        }
         else if(choice2==2)
         {
                       
                  for(int i = 0;i < NhanSu::countnv; i++) {
                 
                 for(int j = i+1; j < NhanSu::countnv; j++) {
                       ten1=_tachten1nguoi(ds[i]->getHoTen());
                       ten2=_tachten1nguoi(ds[j]->getHoTen());
            if(_stricmp(ten1.c_str(), ten2.c_str()) > 0) {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
            }
            else if(_stricmp(ten1.c_str(), ten2.c_str()) == 0)
            {
                ho1=_tachho1nguoi(ds[i]->getHoTen());
                ho2=_tachho1nguoi(ds[j]->getHoTen());
                if(_stricmp(ho1.c_str(), ho1.c_str()) > 0) {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
            }
        }
    }
          }
             Xuat();
           }
        }
        if(choice1==3)
        {
              cout<<"\n\t\t\t\t 1. Giam dan"<<endl;
                cout<<"\n\t\t\t\t 2. Tang dan"<<endl;
                cin>>choice2;
               while(choice2 !=1&&choice2!=2)
                  {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice2;
                }
               if(choice2==1)
               {
                      
                  for(int i = 0;i < NhanSu::countnv; i++) {
                    
                 for(int j = i+1; j < NhanSu::countnv; j++) {
                         if(ds[i]->getNgayVaoLam().getNam() < ds[j]->getNgayVaoLam().getNam() )
                         {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
                         }
                         else if(ds[i]->getNgayVaoLam().getNam() == ds[j]->getNgayVaoLam().getNam())
                         {
                            if(ds[i]->getNgayVaoLam().getThang() < ds[j]->getNgayVaoLam().getThang() )
                            {
                                x=ds[i];
                                ds[i]=ds[j];
                                ds[j]=x;
                            }
                            else if(ds[i]->getNgayVaoLam().getThang() == ds[j]->getNgayVaoLam().getThang())
                            {
                                if(ds[i]->getNgayVaoLam().getNgay() < ds[j]->getNgayVaoLam().getNgay())
                                {
                                    x=ds[i];
                                    ds[i]=ds[j];
                                    ds[j]=x;
                                }
                            }
                         }
                 }
                  }
                     Xuat();
               }
               else if(choice2==2)
               {
                  for(int i = 0;i < NhanSu::countnv; i++) {
                    
                 for(int j = i+1; j < NhanSu::countnv; j++) {
                         if(ds[i]->getNgayVaoLam().getNam() > ds[j]->getNgayVaoLam().getNam() )
                         {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
                         }
                         else if(ds[i]->getNgayVaoLam().getNam() == ds[j]->getNgayVaoLam().getNam())
                         {
                            if(ds[i]->getNgayVaoLam().getThang() > ds[j]->getNgayVaoLam().getThang() )
                            {
                                x=ds[i];
                                ds[i]=ds[j];
                                ds[j]=x;
                            }
                            else if(ds[i]->getNgayVaoLam().getThang() == ds[j]->getNgayVaoLam().getThang())
                            {
                                if(ds[i]->getNgayVaoLam().getNgay() > ds[j]->getNgayVaoLam().getNgay())
                                {
                                    x=ds[i];
                                    ds[i]=ds[j];
                                    ds[j]=x;
                                }
                            }
                         }
                 }
                  }
                     Xuat();
               }        
        }
        else if(choice1 == 4)
           {
          string madv1;
          string madv2;
           cout<<"\n\t\t\t\t 1. Giam dan"<<endl;
                cout<<"\n\t\t\t\t 2. Tang dan"<<endl;
                cin>>choice2;
               while(choice2 !=1&&choice2!=2)
                  {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice2;
                }
        if(choice2==1)
        {
             for(int i = 0;i < NhanSu::countnv; i++) {
                      for(int j = i+1; j < NhanSu::countnv; j++) {
               if(ds[i]->getMaDV()<ds[j]->getMaDV())
               {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
               }
               else if(ds[i]->getMaDV() == ds[j]->getMaDV())
               {
                     long ma1=stol(ds[j]->getMaNV());
                      long ma2=stol(ds[i]->getMaNV());
                  if(ma1<ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
               }
                 }
        }
          
           Xuat();
        }
        else if(choice2==2)
        {
             for(int i = 0;i < NhanSu::countnv; i++) {
                      for(int j = i+1; j < NhanSu::countnv; j++) {
               if(ds[i]->getMaDV()>ds[j]->getMaDV())
               {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
               }
                 if(ds[i]->getMaDV()==ds[j]->getMaDV()){
                 long ma1=stol(ds[j]->getMaNV());
               long ma2=stol(ds[i]->getMaNV());
                  if(ma1>ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
                      }
                 }
        }
        Xuat();
        }
          
        }
        else if(choice1==5)
        {
           cout<<"\n\t\t\t\t 1. Giam dan"<<endl;
                cout<<"\n\t\t\t\t 2. Tang dan"<<endl;
                cin>>choice2;
               while(choice2 !=1&&choice2!=2)
                  {
                    cout<<"\n\t\t\t\t Vui long nhap dung so thu tu";
                    cin>>choice2;
                }
              if(choice2==1)
            {
             for(int i = 0;i < NhanSu::countnv; i++) {
                      for(int j = i+1; j < NhanSu::countnv; j++) {
               if(ds[i]->getMaCV()<ds[j]->getMaCV())
               {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
               }
               else if(ds[i]->getMaCV()==ds[i]->getMaCV())
               {
                  long ma1=stol(ds[j]->getMaNV());
               long ma2=stol(ds[i]->getMaNV());
                  if(ma1<ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
               }
                 }
        }
          
           Xuat();
        }
        else if(choice2==2)
        {
             for(int i = 0;i < NhanSu::countnv; i++) {
                      for(int j = i+1; j < NhanSu::countnv; j++) {
               if(ds[i]->getMaCV()>ds[j]->getMaCV())
               {
                           x=ds[i];
                           ds[i]=ds[j];
                           ds[j]=x;
               }
                else if(ds[i]->getMaCV()==ds[i]->getMaCV())
               {
                  long ma1=stol(ds[j]->getMaNV());
               long ma2=stol(ds[i]->getMaNV());
                  if(ma1>ma2)
                  {
                    x=ds[i];
                    ds[i]=ds[j];
                    ds[j]=x;
                  }
               }
                 }
        }
          
           Xuat();
        }
        }          
   }
        else if(luachon == 8)
        {
            int flag=1;
            cout<<"\n\t\t\t\t Thay doi thong tin theo: ";
            cout<<"\n\t\t\t\t 1. Ma nhan vien"<<endl;
            cout<<"\n\t\t\t\t 2. Ho ten nhan vien"<<endl;
            int choicex;
           cin>>choicex;
           while(choicex!=1&&choicex!=2)
           {
            cout<<"\n\t\t\t\t Nhap lai lua chon"<<endl;
            cin>>choicex;
           }
           if(choicex==1)
           {
            string s;
            int choice;
        
            cout << "\n\t\t\t\tNhap ma can tim: "<<endl;
           cin>>s;
            if(s.length()!=8)
            {
                cout<<"\n\t\t\t\t Nhap day du ma nhan vien!";
            }
            
           int a = s.length();
            // cout << "/"<<s<<"/" << endl;
            for(int i = 0; i < NhanSu::countnv;i++){
                string ss = ds[i]->getMaNV();
                // cout << "/"<<ss<<"/" << endl;
                // for(int i=0;i<ss.length();i++){
                //     ss[i] = tolower(ss[i]);
                // }
                // cout << "/"<<ss<<"/" << end;
                if(ss==s&&ss.length()==a)
                {
                    cout<<"\n\t\t\t\t Nhap thong tin muon thay doi:";
                    cout<<"\n\t\t\t\t 1. Ho ten nhan vien";
                    cout<<"\n\t\t\t\t 2. Ngay thang nam vao lam";
                    cout<<"\n\t\t\t\t 3. Ngay thang nam sinh";
                    cout<<"\n\t\t\t\t 4. Don vi nhan vien";
                    cout<<"\n\t\t\t\t 5. Chuc vu nhan vien";
                    cout<<"\n\t\t\t\t 6. Gioi tinh nhan vien";
                    cin>>choice;
                    while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6)
                    {
                        cout<<"\n\t\t\t\t Nhap lai lua chon";
                        cin>>choice;
                    }
                    if(choice==1)
                    {
                        cout<<"\n\t\t\t\t Nhap ho ten nhan vien moi: ";
                        string hotenmoi;
                        // cin >> hotenmoi;
                        cin.ignore();
                        // getline(cin, hotenmoi); 
                        getline(cin, hotenmoi);
                        
                        // cout << hotenmoi <<" 123" << endl;
                        ds[i]->setHotenMoi(hotenmoi);
                        Xuat();
                    }
                    if(choice == 2)
                    {
                        string nvl;
                        cout<<"\n\t\t\t\t Nhap ngay thang vao lam moi:"<<endl;
                        cin>>nvl;
                        ds[i]->ChangeNVL(nvl);
                        
                        while(ds[i]->getNgayVaoLam().getNgay()>31||ds[i]->getNgayVaoLam().getNgay()<0||
                        ds[i]->getNgayVaoLam().getThang()>12||ds[i]->getNgayVaoLam().getThang()<=0||
                        (ds[i]->getNgayVaoLam().getNam()-ds[i]->getNamSinh().getNam())<=18||
                        (ds[i]->getNgayVaoLam().getNam()-ds[i]->getNamSinh().getNam())>70)
                        {
                            cout<<"\n\t\t\t\t Nhap lai ngay thang vao lam:"<<endl;
                            cin>>nvl;              
                            ds[i]->ChangeNVL(nvl);
                        }
                        cout << "check";
                        Xuat();
                        // ds[i]->getNgayVaoLam().setNgay(ngaymoi);
                        // ds[i]->getNgayVaoLam().setThang(thangmoi);
                        // ds[i]->getNgayVaoLam().setNam(nammoi);
                    }
                    if(choice == 3)
                    {
                        string namsinh;
                        cout<<"\n\t\t\t\t Nhap ngay thang nam sinh moi:"<<endl;
                        cin>>namsinh;
                        ds[i]->ChangeNTNS(namsinh);
                        
                        while(ds[i]->getNamSinh().getNgay()>31||ds[i]->getNamSinh().getNgay()<0||
                        ds[i]->getNamSinh().getThang()>12||ds[i]->getNamSinh().getThang()<=0||
                        ds[i]->getNamSinh().getNam()<1900||ds[i]->getNamSinh().getNam()>2018)
                        {
                            cout<<"\n\t\t\t\t Nhap lai ngay thang nam sinh moi:"<<endl;
                            cin>>namsinh;              
                            ds[i]->ChangeNTNS(namsinh);
                        }
                        cout << "check";
                        Xuat();
                    }
                    if(choice == 4)
                    {
                        cout<<"\n\t\t\t\t Nhap ma don vi moi"<<endl;
                        string s;
                        cin>>s;
                        while(s.length()!=2||s[0] != '0'||s[1] - '0' < 1 || s[1] - '0' > 3)
                        {
                            cout << "Nhap ma don vi khong hop le, moi nhap lai !\n";
                            cin>>s;
                        }
                        ds[i]->setMaDVmoi(s);
                        Xuat();
                    }
                    if(choice == 5)
                    {
                    cout<<"\n\t\t\t\t Nhap ma chuc vu moi: ";
                        string s;
                        cin>>s;
                    while(s.length()!=2||s[0] != '0'||s[1] - '0' < 1 || s[1] - '0' > 5)
                        {
                            cout << "Nhap ma chuc vu khong hop le, moi nhap lai !\n";
                            cin>>s;
                        }
                        ds[i]->setMaCVmoi(s);
                        Xuat();

                    }
                    if(choice == 6)
                    {
                    cout<<"\n\t\t\t\t Nhap gioi tinh moi:"<<endl;
                    string gt;
                    cin >> gt;
                    for(int i=0;i<gt.length();i++){
                        gt[i] = tolower(gt[i]);
                    }
                    while(gt != "nam" && gt != "nu"){
                        cout<<"\t\t\t\t Nhap lai gioi tinh"<<endl;
                        cin >> gt;
                        for(int i=0;i<gt.length();i++){
                            gt[i] = tolower(gt[i]);
                        }
                    }
                    gt[0] = toupper(gt[0]);
                    // for(int i=1; i<gt.length(); i++)
                    // {
                    //   gt[i]=tolower(gt[i]);
                    
                    // }
                    ds[i]->getGioiTinh(gt);
                    Xuat();
                    }
                    flag=0;
                    } 
            }
            if(flag==1) cout<<"\n\t\t\t\t Khong co nhan vien co ma nhu da nhap";
           }
        }

        // else {
        //     cout<<ds[0]->getNgayVaoLam().getNam();
        //    cout<<ds[0]->getNamSinh().getNam();
        //     break;
        // }

        if(luachon == 0){
            break;
        }
        while(luachon<0&&luachon>=8)
        {
            cout<<"\n\t\t\t\t Nhap lai lua chon";
        }
        // break;
    
    }
    filein.close();
    }
int main(){
    int n = 0;
    Menu(ds, n);
}