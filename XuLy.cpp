#include<iostream>
#include <fstream>
#include "NhanSu.h"
#include <cstring> 
#include <string>
using namespace std;

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
        NhanSu::countnv++;
    }

    filein.close();

    while (true){
        cout << "\n\n\t\t\t\t================ MENU  ==============\n";
        cout << "\n\t\t\t\t 1. Nhap thong tin nhan vien"; // xong
        cout << "\n\t\t\t\t 2. Xuat thong tin nhan vien"; // xong
        cout << "\n\t\t\t\t 3. In bang thong ke theo don vi";                              
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
            
        }
        // xuat ra man hinh hoac file
        else if(luachon == 2){
            int luachonxuat;
            cout << "\n\t\t\t\t Chon che do xuat: ";
            cout << "\n\t\t\t\t 1. Xuat ra file";
            cout << "\n\t\t\t\t 2. Xuat ra man hinh";
            cout << "\n\t\t\t\t Nhap lua chon: ";
            cin >> luachonxuat;
            if(luachonxuat == 1){
                fileout.clear();
                fileout.open("DanhsachNhanSu.txt", ios_base::out);
                fileout << "DVi\t Ma Nhan Vien\tHo va Ten\t\t\t\tNam Sinh \t Gioi Tinh \t Don Vi \tChuc Vu \t\tNgay Vao Lam \n";
                for(int i = 0; i < NhanSu::countnv; i++){
                    fileout << i+1 << "\t";
                    ds[i]->XuatFile(fileout);
                }
                cout << "\n\t\t\t\t Da xuat du lieu ra file NhanVienOut.txt !\n";
                fileout.close();
            }
            else{
                cout << "\n\t\t\t\t\tDANH SACH NHAN VIEN" << endl;
                int n = NhanSu::countnv;
                for(int i=0;i<n;i++){
                    cout << "\n\t\t\t\t" <<i+1<<".  NHAN VIEN THU " << i+1 << endl;
                    ds[i]->Xuat();
                    cout << "\n\t\t\t\t=====================================";
                }
                cout << "\n\t\t\t\treturn to menu ...";
            }
            
        }
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
            // NhanSu s;
            // for(int i=0; i<NhanSu::countnv; i++)
            // {
                // s.TimKiem(*ds);
        
            // } 
            for(int i =0; i<NhanSu::countnv; i++)
            {

            ds[i]->Xuat();
            }
           


        }

        else {
            break;
        }
        // break;
    }
    filein.close();
}
int main(){
    NhanSu *ds[10000];
    int n = 0;
    Menu(ds, n);
}