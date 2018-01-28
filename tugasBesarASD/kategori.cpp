#include "induk.h"
void createListKategori (List_kategori &L)
{
    L.first = Nil;
}
adr_kategori alokasikategori(kategori k)
{
    adr_kategori P = new ElmList_kategori;
    P->info = k;
    P->next = Nil;
    return P;
}
void dealokasiKategori(adr_kategori &P)
{
    delete (P);
}
void insertFirstKategori(List_kategori &L, adr_kategori P)
{
    if(L.first ==Nil)
    {
        L.first = P;
    }
    else
    {
        P->next = L.first;
        L.first = P;
    }
}
void insertAfterKategori(List_kategori &L, adr_kategori P, adr_kategori Prec)
{
    if(L.first==Nil)
    {
        L.first =P;
    }
    else
    {
        P->next = Prec->next;
        Prec->next= P;
    }
}
void insertLastKategori(List_kategori &L, adr_kategori P)
{
    if(L.first==Nil)
    {
        L.first = P;
    }
    else
    {
        adr_kategori Q=L.first;
        while(Q->next!=Nil)
        {
            Q=Q->next;
        }
        Q->next = P;
    }
}
void insertSortKategori(List_kategori &L, adr_kategori P)
{
    if(L.first==Nil)
    {
        L.first=P;
    }
    else
    {
        if(P->info.id_kategori<L.first->info.id_kategori)
        {
            insertFirstKategori(L,P);
        }
        else
        {
            adr_kategori R;
            adr_kategori Q = L.first;
            while((P->info.id_kategori>Q->info.id_kategori) && (Q->next!=Nil))
            {
                R=Q;
                Q=Q->next;
            }
            if(P->info.id_kategori>Q->info.id_kategori)
            {
                insertLastKategori(L,P);
            }
            else
            {
                insertAfterKategori(L,P,R);
            }
        }
    }
}
adr_kategori findElmKategori(List_kategori L, string k)
{
    adr_kategori P;
    P=L.first;

    while((P!= Nil)&&(P->info.nama_kategori!=k))
    {
        P=P->next;
    }

    return P;
}
adr_kategori findElmKategoriid(List_kategori L, int k)
{
    adr_kategori P;
    P=L.first;

    while((P!= Nil)&&(P->info.id_kategori!=k))
    {
        P=P->next;
    }

    return P;
}
void deleteFirstKategori(List_kategori &L, adr_kategori &P)
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
    }

    dealokasiKategori(P);
}
void deleteAfterKategori(List_kategori &L, adr_kategori &P,adr_kategori Prec)
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
    }

    dealokasiKategori(P);
}
void deleteLastKategori(List_kategori &L, adr_kategori &P)
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
        adr_kategori Q = L.first;
        while (P->next!=Nil)
        {
            Q=P;
            P=P->next;
        }
        Q->next = Nil;
    }
    dealokasiKategori(P);
}
void deleteKategori (List_kategori &L, adr_kategori &P, int x)
{
    adr_kategori Q=L.first;
    adr_kategori R;
    while((Q!= Nil)&&(Q->info.id_kategori!=x))
    {
        R=Q;
        Q=Q->next;
    }
    if(Q==Nil)
    {
        cout<<"Kategori tidak ditemukan!"<<endl;
    }
    else
    {
        if(Q==L.first)
        {
            deleteFirstKategori(L,P);
        }
        else if(Q->next==Nil)
        {
            deleteLastKategori(L,P);
        }
        else
        {
            deleteAfterKategori(L,P,R);
        }
        cout<<"Data Berhasil dihapus!"<<endl;
    }
}
void printInfo_kategori(List_kategori L)
{
    adr_kategori P;
    P=L.first;
    if(L.first==Nil)
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        while(P != Nil)
        {
            cout<<"Id Kategori     : "<<P->info.id_kategori<<endl;
            cout<<"Nama Kategori   : "<<P->info.nama_kategori<<endl;
            P=P->next;
            cout<<endl;
        }
    }

}
