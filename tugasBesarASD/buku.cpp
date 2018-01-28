#include "induk.h"
void createListBuku (List_buku &L)
{
    L.first = Nil;
    L.last  = Nil;
}
adr_buku alokasibuku(buku b)
{
    adr_buku P = new ElmList_buku;
    P->info = b;
    P->next = Nil;
    P->prev = Nil;
    return P;
}
void dealokasiBuku (adr_buku &P)
{
    delete(P);
}
void insertFirstBuku(List_buku &L, adr_buku P)
{
    if( L.first == Nil)
    {
        L.first = P;
        L.last  = P;
    }
    else
    {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertAfterBuku(List_buku &L, adr_buku P, adr_buku Prec)
{
    if(L.first==Nil)
    {
        L.first =P;
        L.last  =P;
    }
    else
    {
        P->prev = Prec;
        P->next = Prec->next;
        Prec->next = P;
        P->next->prev = P;
    }
}

void insertLastBuku (List_buku &L, adr_buku P)
{
    if(L.first==Nil)
    {
        L.first = P;
        L.last  = P;
    }
    else
    {
        L.last->next=P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertSortBuku (List_buku &L, adr_buku P)
{
    if(L.first==Nil)
    {
        L.first=P;
        L.last =P;
    }
    else
    {
        if(P->info.NISBN<L.first->info.NISBN)
        {
            insertFirstBuku(L,P);
        }
        else
        {
            adr_buku Q = L.first;
            while((P->info.NISBN>Q->info.NISBN) && (Q->next!=Nil))
            {
                Q=Q->next;
            }
            if(P->info.NISBN>Q->info.NISBN)
            {
                insertLastBuku(L,P);
            }
            else
            {
                Q=Q->prev;
                insertAfterBuku(L,P,Q);
            }
        }
    }
}
adr_buku findElmBuku(List_buku L, int b)
{
    adr_buku P;
    P=L.first;
    while((P!= Nil)&&(P->info.NISBN!=b))
    {
        P=P->next;
    }
    return P;

}

void deleteFirstBuku(List_buku &L, adr_buku &P)
{
    if(L.first==Nil)
    {
        cout<<"List Kosong";
    }
    else if(L.first->next==Nil)
    {
        P=L.first;
        L.first=Nil;
    }
    else
    {
        P=L.first;
        L.first= P->next;
        P->next = Nil;
        L.first ->prev = Nil;

    }
    dealokasiBuku(P);
}
void deleteAfterBuku(List_buku &L, adr_buku &P, adr_buku Prec)
{
    if(L.first==Nil)
    {
        cout<<"List Kosong";
    }
    else if(L.first->next==Nil)
    {
        P=L.first;
        L.first=Nil;
    }
    else
    {
        P=Prec->next;
        Prec->next=P->next;
        P->next = Nil;
        P->prev = Nil;
        Prec->next->prev = Nil;
    }
    dealokasiBuku(P);
}
void deleteLastBuku(List_buku &L, adr_buku &P)
{
    if(L.first==Nil)
    {
        cout<<"List Kosong";
    }
    else if(L.first->next==Nil)
    {
        P=L.first;
        L.first=Nil;
    }
    else
    {
        P= L.last;
        L.last=L.last->prev;
        P->prev = Nil;
        L.last->next = Nil;
    }
    dealokasiBuku(P);
}
void deleteBuku (List_buku &L, adr_buku &P, int x)
{
    adr_buku Q = findElmBuku(L,x);
    if(Q==Nil)
    {
        cout<<"Buku tidak ditemukan";
    }
    else
    {
        if(Q==L.first)
        {
            deleteFirstBuku(L,P);
        }
        else if(Q->next==Nil)
        {
            deleteLastBuku(L,P);
        }
        else
        {
            Q=Q->prev;
            deleteAfterBuku(L,P,Q);
        }
        cout<<"Data Berhasil dihapus!"<<endl;
    }
}
void printInfo_buku(List_buku L)
{
    adr_buku P;
    P=L.first;
    if(L.first==Nil)
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        while(P != Nil)
        {
            cout<<"NISBN           : "<<P->info.NISBN<<endl;
            cout<<"Judul Buku      : "<<P->info.judul<<endl;
            cout<<"Penulis Buku    : "<<P->info.penulis<<endl;
            cout<<"Harga           : "<<P->info.harga<<endl;
            cout<<"Stock           : "<<P->info.stock<<endl;
            P=P->next;
            cout<<endl;
            ;
        }
    }
}
void set_kategori (List_buku &L1,List_kategori L2, int x, string y, bool &z)
{
    adr_buku P;
    adr_kategori Q;
    P = findElmBuku(L1, x);
    Q = findElmKategori(L2, y);//namakategori
    if (P != Nil && Q!= Nil)
    {
        P->next_kategori = Q;
        z=true;
    }
    else
    {
        cout<<"Kategori tidak ditemukan!"<<endl;
    }
}

void menu()
{
    cout<<"---------TOKO BUKU WIRAGUNS-------------"<<endl;
    cout<<"1.  Insert data                         "<<endl;
    cout<<"2.  Search and View                     "<<endl;
    cout<<"3.  Search and Delete                   "<<endl;
    cout<<"4.  View All                            "<<endl;
    cout<<"5.  Reporting                           "<<endl;
    cout<<"6.  exit                                "<<endl;

}

void totalData(List_buku L1, List_kategori L2)
{
    adr_kategori Q= L2.first;
    adr_buku     P;
    int hitung;
    while (Q!=Nil)
    {
        hitung=0;
        P=L1.first;
        cout<<endl<<"Total Data Berdasarkan Kategori " <<Q->info.nama_kategori<<": ";
        while(P!=Nil)
        {
            if(P->next_kategori->info.id_kategori==Q->info.id_kategori)
            {
                hitung++;
            }
            P=P->next;
        }
        cout<<hitung;
        Q=Q->next;
    }
    cout<<endl;
}
void getMinimumStock(List_buku L)
{
    adr_buku P=L.first;
    int minimum=P->info.stock;
    while((P!=Nil)&&(P->info.stock<minimum))
    {
        P=P->next;
    }
    cout<<"Stock Paling sedikit di antara semua buku adalah "<<endl;
    cout<<"NISBN           : "<<P->info.NISBN<<endl;
    cout<<"Judul Buku      : "<<P->info.judul<<endl;
    cout<<"Penulis Buku    : "<<P->info.penulis<<endl;
    cout<<"Harga           : "<<P->info.harga<<endl;
    cout<<"Stock           : "<<P->info.stock<<endl;

}
void printInfoByKategori(List_buku L1, List_kategori L2)
{
    adr_kategori Q= L2.first;
    adr_buku     P;
    while (Q!=Nil)
    {
        P=L1.first;
        cout<<endl<<"Data Berdasarkan Kategori " <<Q->info.nama_kategori<<": "<<endl;
        while(P!=Nil)
        {
            if(P->next_kategori->info.id_kategori==Q->info.id_kategori)
            {
                cout<<"NISBN           : "<<P->info.NISBN<<endl;
                cout<<"Judul Buku      : "<<P->info.judul<<endl;
                cout<<"Penulis Buku    : "<<P->info.penulis<<endl;
                cout<<"Harga           : "<<P->info.harga<<endl;
                cout<<"Stock           : "<<P->info.stock<<endl;
            }
            P=P->next;
            cout<<endl;
        }
        Q=Q->next;
    }
}
void getAveragebyKategori(List_buku L1, List_kategori L2)
{
    adr_kategori Q= L2.first;
    adr_buku     P;
    int sum,n;
    double avg;
    while (Q!=Nil)
    {
        P=L1.first;
        sum= 0;
        n  = 0;
        cout<<endl<<"Rata-rata harga Berdasarkan Kategori " <<Q->info.nama_kategori<<": "<<endl;
        while(P!=Nil)
        {
            if(P->next_kategori->info.id_kategori==Q->info.id_kategori)
            {
                sum=sum+P->info.harga;
                n++;
            }
            P=P->next;
        }
        if(sum!=0){
            avg=sum/n;
            cout<<avg<<endl;
            }
        else {
            cout<<sum<<endl;
        }
        Q=Q->next;
    }

}

bool cekNextKategori(List_buku L, int id_kategori){
    bool cek=false;
    adr_buku P=L.first;
    while (P!=Nil){
        if(P->next_kategori->info.id_kategori==id_kategori){
            cek =true;
            break;
        }
        P=P->next;
    }
    return cek;
}
