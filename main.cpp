
#include <iostream>
#include<cstdlib>
#include<conio.h>

//nama : LESTA NABILA
//nim : 1121031047
//kelas : Informatika A
using namespace std;

struct TNode{
    int data;
    TNode *Next;
}; TNode *head, *tail;

void init(){
    head=NULL;
    tail=NULL;
}

int isEmpty(){
    if(tail==NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertDepan(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data=databaru;
    baru->Next=NULL;
    if(isEmpty()==1){
        head=tail=baru;
        tail->Next=NULL;
    }else{
        baru->Next=head;
        head=baru;
    }
    cout<<"Input Data Berhasil";
}

void insertBelakang(int data){
    TNode *baru;
    baru = new TNode;
    baru->data=data;
    baru->Next=NULL;
    if(isEmpty()==1){
            head=baru;
            tail=baru;
            tail->Next=NULL;
    }else{
        tail->Next=baru;
        tail=baru;
    }
    cout<<"\n Input Data Berhasil"<<endl;
}

void hapusDepan(){
    TNode *hapus;
    int d;
    if(isEmpty()==0){
        if(head!=tail){
            hapus=head;
            d=hapus->data;
            head=head->Next;
            delete hapus;
        }else{
            d=tail->data;
            head=tail=NULL;
        }
        cout<<d<<"Terhapus";
    }else cout <<"Data Masih Kosong\n";
}

void hapusBelakang(){
    TNode *bantu, *hapus;
    int d;
    if(isEmpty()==0){
        bantu=head;
        if(head!=tail){
            while (bantu->Next!=tail){
                bantu=bantu->Next;
            }
            hapus=tail;
            tail=bantu;
            d=hapus->data;
            delete hapus;
            tail->Next=NULL;
        }else{
            d=tail->data;
            head=tail=NULL;
        }
        cout<<d<<"Terhapus";
    }else cout <<"Data Masih Kosong\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
    if(isEmpty()==0){
        cout<<"depan :";
        while(bantu!=NULL){
            cout<<bantu->data<<"->";
            bantu=bantu->Next;
        }
    }else if(isEmpty()==0){
        cout<<"belakang :";
        while(bantu!=NULL){
            cout<<bantu->data<<"->";
            bantu=bantu->Next;
        }
    }
    cout<<"\n Data Masih Kosong"<<endl;
}

main(){
    int pil,data,databaru;
    init();
    do{
        system("cls");
        cout<<endl;
        cout<<"PROGRAM LINKED LIST"<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampil Data"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"\nMasukkan Pilihan : ";cin>>pil;
        switch(pil){
            case 1:system("cls");{
                cout<<"nTambah Depan"<<endl;
                cout<<"Masukkan Data :";cin>>databaru;
                    insertDepan(databaru);
                    break;
            }
            case 2:system("cls");{
                cout<<"\nTambah Balakang"<<endl;
                cout<<"Masukkan Data :";cin>>data;
                insertBelakang(data);
                break;
            }
             case 3:system("cls");{
                cout<<"\nData Depan telah Terhapus:"<<endl;
                hapusDepan();
                break;
             }
             case 4:system("cls");{
                cout<<"\nData Belakang Telah Terhapus:"<<endl;
                hapusBelakang();
                break;
             }
             case 5:system("cls");{
                cout<<"\nTampilkan Data:"<<endl;
                tampil();
                break;
             }
             case 0:system("cls");{
                return 0;
                break;
             }default:
                 system("cls");{
                 cout<<"Pilihan tidak Tersedia"<<endl;
                 }
        }getch();
    }while(pil!=7);

}


