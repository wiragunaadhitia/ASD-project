#include <iostream>
#include "induk.h"

using namespace std;

int main()
{
    infotype_buku b;
    infotype_kategori k;
    int id_buku,id_kategori;//untuk search
    adr_buku P,Q,R;
    adr_kategori S,T,U;
    List_buku L1;
    createListBuku(L1);
    List_kategori L2;
    createListKategori(L2);
    bool idfound;// untuk meyakinkan id unik
    int pil,pil_menu;
    while(pil!=6)
    {
        menu();
        cout<<endl<<"Masukkan Pilihan menu : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            system("cls");
            cout<<"1. Buku 2. Kategori"<<endl<<"Inputkan Pilihan : ";
            cin>>pil_menu;
            if(pil_menu==1)
            {
                system("cls");
                if(L2.first!=Nil)
                {
                    idfound=false;
                    cout<<"Insert Judul Buku : ";
                    cin>>b.judul;
                    while (idfound!=true)
                    {
                        cout<<"Insert NISBN(id)  : ";
                        cin>>b.NISBN;
                        if(L1.first!=Nil)
                        {
                            R = findElmBuku(L1,b.NISBN);
                            if(R==Nil)
                            {
                                idfound=true;
                            }
                        }
                        else
                        {
                            idfound=true;
                        }
                    }
                    cout<<"Insert Penulis    : ";
                    cin>>b.penulis;
                    cout<<"Insert Harga      : ";
                    cin>>b.harga;
                    cout<<"Insert Stock      : ";
                    cin>>b.stock;
                    P = alokasibuku(b);
                    insertSortBuku(L1,P);
                    string nama_kategori;
                    idfound = false;
                    while(idfound==false)
                    {
                        cout<<"Berikut Data Kategori yang Tersedia"<<endl;
                        printInfo_kategori(L2);
                        cout<<"Buku ini akan dimasukkan sebagai kategori(input dengan nama kategori) : ";
                        cin>>nama_kategori;
                        cout<<endl;
                        set_kategori(L1,L2,b.NISBN,nama_kategori,idfound);//buku.cpp
                    }
                    system("cls");
                    cout<<"Data Berhasil Diinputkan!"<<endl;
                }
                else
                {
                    cout<<"Input data Kategori terlebih dahulu "<<endl;
                }
            }
            else if(pil_menu==2)
            {
                system("cls");
                idfound=false;
                while (idfound!=true)
                {
                    cout<<"Insert ID Kategori   : ";
                    cin>>k.id_kategori;
                    if(L2.first!=Nil)
                    {
                        S = findElmKategoriid(L2,k.id_kategori);
                        if(S==Nil)
                        {
                            idfound=true;
                        }
                    }
                    else
                    {
                        idfound=true;
                    }
                }
                cout<<"Insert Nama Kategori : ";
                cin>>k.nama_kategori;
                S= alokasikategori(k);
                insertSortKategori(L2,S);
            }

            break;
        case 2 :
            system("cls");
            cout<<"1. Buku 2. Kategori"<<endl;
            cin>>pil_menu;
            if(pil_menu==1)
            {
                system("cls");
                cout<<"Inputkan ID : ";
                cin>>id_buku;
                Q =findElmBuku(L1,id_buku);
                if(Q!=Nil)
                {
                    cout<<"NISBN           : "<<Q->info.NISBN<<endl;
                    cout<<"Judul Buku      : "<<Q->info.judul<<endl;
                    cout<<"Penulis Buku    : "<<Q->info.penulis<<endl;
                    cout<<"Harga           : "<<Q->info.harga<<endl;
                    cout<<"Stock           : "<<Q->info.stock<<endl;
                }
                else
                {
                    cout<<"Buku Tidak ditemukan!"<<endl;
                }

            }
            else if(pil_menu==2)
            {
                system("cls");
                cout<<"Inputkan ID : ";
                cin>>id_kategori;
                T=findElmKategoriid(L2,id_kategori);
                if(T!=Nil)
                {
                    cout<<"Id kategori  : "<<T->info.id_kategori<<endl;
                    cout<<"Nama Kategori: "<<T->info.nama_kategori<<endl;
                }
                else
                {
                    cout<<"Kategori Tidak ditemukan!"<<endl;
                }

            }

            break;
        case 3 :
            system("cls");
            cout<<"1. Buku 2. Kategori " <<endl;
            cin>>pil_menu;
            if(pil_menu==1)
            {
                system("cls");
                cout<<"Masukkan NISBN buku : ";
                cin>>id_buku;
                deleteBuku(L1,R,id_buku);
            }
            else if(pil_menu==2)
            {
                system("cls");
                cout<<"Masukkan ID Kategori: ";
                cin>>id_kategori;
                if(cekNextKategori(L1,id_kategori)==false )  //fungsi berada di buku.cpp berguna untuk mengecek apakah masih ada
                {
                    deleteKategori(L2,U,id_kategori);        //buku yang terikat sama kategori
                }
                else
                {
                    cout<<"Hapus terlebih dahulu data Buku sebagai Kategori tersebut"<<endl;
                }
            }
            break;
        case 4 :
            system("cls");
            cout<<"Buku     : "<<endl;
            printInfo_buku(L1);
            cout<<"Kategori : "<<endl;
            printInfo_kategori(L2);
            break;
        case 5 :
            system ("cls");
            if((L1.first!=Nil)&&(L2.first!=Nil))
            {
                printInfoByKategori(L1,L2);
                cout <<"1. Jumlah data berdasarkan Kategori "<<endl;
                cout <<"2. Stock paling sedikit di antara semua Buku"<<endl;
                cout<< "3. Harga rata-rata per kategori"<<endl;
                cout<<"Masukkan Pilihan : ";
                cin>>pil_menu;
                if(pil_menu==1)
                {
                    totalData(L1,L2);//buku.cpp menampilkan banyak data setiap kategori
                }
                else if (pil_menu==2)
                {
                    getMinimumStock(L1);//buku.cpp menampilkan data buku yang memiliki stock paling sedikit
                }
                else if (pil_menu==3)
                {
                    getAveragebyKategori(L1,L2);//buku.cpp menampilkan rata-rata harga buku per kategori
                }
            }
            else
            {
                cout<<"List Buku atau Kategori masih kosong!"<<endl;
            }
            break;
        case 6 :
            system("cls");
            cout<<"terimakasih "<<endl;
            break;
        default :
            system("cls");
            cout<<"Masukkan pilihan sesuai menu! "<<endl;
            break;
        }


    }
    return 0;
}

