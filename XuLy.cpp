#include<iostream>
#include <fstream>
#include "NhanSu.h"
#include "DonVi.h"
#include <cstring> 
#include <string>
using namespace std;
NhanSu *ds[10000];

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
    cout << "\n\t\t\t\t Da xuat du lieu ra file DanhsachNhanSu.txt !\n";
    fileout.close();  

    DonVi  *dsDV[1000];
    int countDV1 = 0;
    DonVi::countDV = 0;
    // cap nhat file DonVi
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
    cout << "\n\t\t\t\t Da xuat du lieu ra file DonVi.txt !\n";
    fileout.close();  
    // cap nhat file ChucVu



    //cap nhat file BangThongKe
    ofstream fileThongKe;
    fileThongKe.open("BangThongKe.txt", ios_base::out);
    fileThongKe << "Don Vi \t\t So Nhan Vien \t %Nam \t\t %Nu \t\t Tong Thuc Linh\n";
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
        cout << "\n\t\t\t\t 4. Them nhan vien";  // xong
        cout << "\n\t\t\t\t 5. Tim kiem nhan vien"; //TA
        cout << "\n\t\t\t\t 6. Sap xep";
        cout << "\n\t\t\t\t 7. Chen nhan vien"; // xong
        cout << "\n\t\t\t\t 8. Thay doi thong tin nhan vien"; 
        cout << "\n\t\t\t\t 9. Xoa nhan vien";//TA
        cout << "\n\t\t\t\t 0. Ket thuc";
        cout << "\n\n\t\t\t\t=====================================";

      
        
        int luachon;
        cout << "\n\n\t\t\t\t Nhap lua chon: ";
        cin >> luachon;
        
        

        if(luachon == 1){
            NhanSu *x = new NhanSu();
            x->Nhap();
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
                pos --;
                if(pos > NhanSu::countnv){
                    pos = NhanSu::countnv;
                }
                else if(pos < 0) pos = 0;
                for(int i = NhanSu::countnv-1;i>pos;i--){
                    ds[i+1] = ds[i];
                }
                ds[pos] = x;
                NhanSu::countnv++;
            }
            cout << "\n\t\t\t\t Da Doc Thong Tin Nhan Vien !\n";
            Xuat();
        }
        // xuat ra man hinh hoac file
        // xuat ra file
        else if(luachon == 3){
            
            // bao gồm:
            // - theo đơn vị
            // +thông tin cá nhân
            // +thực lĩnh
            // +bảng thống kê
        }
        else if(luachon == 4){

        }
        else if(luachon == 5){
            NhanSu s;
            for(int i=0; i<NhanSu::countnv; i++)
            {
                s.TimKiem(*ds);
        
            } 
            // for(int i =0; i<NhanSu::countnv; i++)
            // {

            // ds[i]->Xuat();
            // }
           


        }
        else if(luachon == 9){
            
        }
        else {
            break;
        }
        // break;
    }
    filein.close();
}
int main(){
    int n = 0;
    Menu(ds, n);
}