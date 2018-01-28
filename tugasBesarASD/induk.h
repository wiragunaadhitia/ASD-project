#ifndef INDUK_H_INCLUDED
#define INDUK_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#define Nil NULL
using namespace std;
////////////STRUCT ANAK//////////////////////////
struct kategori
{
    string nama_kategori;
    int id_kategori;
};
typedef kategori infotype_kategori;
typedef struct ElmList_kategori *adr_kategori;
struct ElmList_kategori
{
    infotype_kategori info;
    adr_kategori next;
};
struct List_kategori
{
    adr_kategori first;
};
/////////////////STRUCT INDUK///////////////////////////////////
struct buku
{
    int NISBN;
    string judul;
    string penulis;
    int    stock;
    int    harga;
};
typedef buku infotype_buku;
typedef struct ElmList_buku *adr_buku;
struct ElmList_buku
{
    infotype_buku info;
    adr_buku next;
    adr_buku prev;
    adr_kategori next_kategori;
};
struct List_buku
{
    adr_buku first;
    adr_buku last;
};
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void createListBuku (List_buku &L);
adr_buku alokasibuku(buku b);
void dealokasiBuku (adr_buku &P);

void insertFirstBuku(List_buku &L, adr_buku P);
void insertAfterBuku(List_buku &L, adr_buku P, adr_buku Prec);
void insertLastBuku (List_buku &L, adr_buku P);

adr_buku findElmBuku(List_buku L, int b);

void deleteFirstBuku(List_buku &L, adr_buku &P);
void deleteAfterBuku(List_buku &L, adr_buku &P, adr_buku Prec);
void deleteLastBuku(List_buku &L, adr_buku &P);
void deleteBuku (List_buku &L, adr_buku &P, int x);

void printInfo_buku(List_buku L);
void set_kategori (List_buku &L1,List_kategori L2,int x, string y, bool &z);
void insertSortBuku (List_buku &L, adr_buku P);

/////////////////////////////////////////////////////////////////
void createListKategori (List_kategori &L);
adr_kategori alokasikategori(kategori k);
void dealokasiKategori(adr_kategori &P);

void insertFirstKategori(List_kategori &L, adr_kategori P);
void insertAfterKategori(List_kategori &L, adr_kategori P, adr_kategori Prec);
void insertLastKategori(List_kategori &L, adr_kategori P);
void insertSortKategori(List_kategori &L, adr_kategori P);
adr_kategori findElmKategori(List_kategori L, string k);
adr_kategori findElmKategoriid(List_kategori L, int k);

void deleteFirstKategori(List_kategori &L, adr_kategori &P);
void deleteAfterKategori(List_kategori &L, adr_kategori &P,adr_kategori Prec);
void deleteLastKategori(List_kategori &L, adr_kategori &P);
void deleteKategori (List_kategori &L, adr_kategori &P, int x);

void printInfo_kategori(List_kategori L);
////////////////////////////////////////////////////////////////////
void menu();

///////////////////////////PROSEDUR REPORT//////////////////////////
void totalData(List_buku L1, List_kategori L2);
void getMinimumStock(List_buku L);
void printInfoByKategori(List_buku L1, List_kategori L2);
void getAveragebyKategori(List_buku L1, List_kategori L2);
bool cekNextKategori(List_buku L, int id_kategori);
#endif // INDUK_H_INCLUDED
