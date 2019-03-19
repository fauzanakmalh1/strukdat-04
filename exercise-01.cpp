/*
Nama Program    : Struktur Data Pegawai - Single Linked List
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 19 Maret 2019
Deskripsi       : Exercise Single Linked List
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct pegawai{
    char nama[40];
    char bidang[50];
    int gaji;
    pegawai* next;
};

typedef pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void insertLast(List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast(List& First, pointer& pHapus);
void traversal(List First);

int main()
{
    pointer p;
    List First;
    int pilih;

    createList(First);

    while(1)
    {
        system("cls");
        cout<<"===============================================" <<endl;
        cout<<"Program untuk Menampilkan Struktur Data Pegawai" <<endl;
        cout<<"===============================================" <<endl <<endl;

        cout<<"= No.    Pilihan Menu                         =" <<endl;
        cout<<"= 1.     Insert First                         =" <<endl;
        cout<<"= 2.     Insert Last                          =" <<endl;
        cout<<"= 3.     Delete First                         =" <<endl;
        cout<<"= 4.     Delete Last                          =" <<endl;
        cout<<"= 5.     Traversal                            =" <<endl;
        cout<<"= 6.     Keluar                               =" <<endl <<endl;
        cout<<"Silahkan Masukan Pilihan : "; cin>>pilih; cout<<endl;

        switch(pilih)
        {
            case 1:
                createElmt(p);
                insertFirst(First, p);
                break;
            case 2:
                createElmt(p);
                insertLast(First, p);
                break;
            case 3:
                deleteFirst(First, p);
                break;
            case 4:
                deleteLast(First, p);
                break;
            case 5:
                traversal(First);
                break;
            case 6:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
    }
}

void createList(List& First)
{
    First=NULL;
}

void createElmt(pointer& pBaru)
{
    pBaru=new pegawai;

    cout<<"Nama\t\t\t: "; cin.ignore(); cin.getline(pBaru->nama, 40);
    cout<<"Bidang/divisi\t\t: "; cin.getline(pBaru->bidang, 50);
    cout<<"Gaji\t\t\t: "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru)
{
    if(First==NULL)
    {
        First=pBaru;
    }
    else
    {
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast(List& First, pointer pBaru)
{
    pointer Last;

    if(First==NULL)
    {
        First=pBaru;
    }
    else
    {
        Last=First;
        while(Last->next!=NULL)
        {
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void deleteFirst(List& First, pointer& pHapus)
{
    if(First==NULL)
    {
        pHapus=NULL;

        cout<<"List kosong, tidak ada yang dihapus" <<endl;
    }
    else if(First->next==NULL)
    {
        pHapus=First;
        First=NULL;
    }
    else
    {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast(List& First, pointer& pHapus)
{
    pointer Last, precLast;

    if(First==NULL)
    {
        pHapus=NULL;

        cout<<"List kosong, tidak ada yang dihapus" <<endl;
    }
    else if(First->next==NULL)
    {
        pHapus=First;
        First=NULL;
    }
    else
    {
        Last=First;
        precLast=NULL;
        while(Last->next!=NULL)
        {
            precLast=NULL;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}

void traversal(List First)
{
    pointer pBantu;
    pBantu=First;

    if(First==NULL)
    {
        cout<<"List kosong" <<endl;
    }
    else
    {
        pBantu=First;
        cout<<"Nama\t\t\t Bidang\t\t Gaji" <<endl;
        cout<<"=======================================================" <<endl;
        do
        {
            cout<<pBantu->nama <<"\t\t" <<pBantu->bidang <<"\t\t" <<pBantu->gaji <<endl;
            pBantu=pBantu->next;
        }
        while(pBantu!=NULL);
    }
}
