#include "menu.h"

void mainMenu(ListEvent LE, ListSponsor LS, ListRelasi LR)
{
    int menu;
    do {
        system("cls");
        cout << "||========================================================||" << endl;
        cout << "||             TUBES STD - Event Sponsorship              ||" << endl;
        cout << "||========================================================||" << endl;
        cout << "||    Anggota : 1. Muhammad Zaidan Rafif (1302213072)     ||" << endl;
        cout << "||              2. Kamal Maulaazka Sidhqi (1302210032)    ||" << endl;
        cout << "||========================================================||" << endl;
        cout << endl;
        cout << "  MENU" << endl << endl;
        cout << "  1. Event (Parent)" << endl;
        cout << "  2. Sponsor (Child)" << endl;
        cout << "  3. Level Sponsorship (relasi)" << endl;
        cout << "  4. Exit" << endl << endl;
        cout << "  Masukan menu : "; cin >> menu;

        switch(menu) {
            case 1 : menuEvent(LE, LR); break;
            case 2 : menuSponsor(LS, LR); break;
            case 3 : menuRelasi(LE, LS, LR); break;
            case 4 : exit(0); break;
        }
    } while (menu != 1 || menu != 2);
}

void menuEvent(ListEvent &LE, ListRelasi &LR)
{
    int menu;
    while (menu != 3) {
        do {
            system("cls");
            spasi(120, "=====================================\n");
            spasi(122, "DAFTAR EVENT\n");
            spasi(120, "=====================================\n");
            cout << endl;
            spasi(25, "No. ");
            spasi(30, "Nama Event ");
            spasi(35, "Dana dibutuhkan ");
            spasi(40, "Dana Kurang ");
            spasi(45, "Dana Lebih ");
            cout << endl;
            showEvent(LE);
            cout << endl;
            cout << endl;
            spasi(40, "1. Tambah Event \n");
            spasi(38, "2. Hapus Event \n");
            spasi(34, "3. Kembali \n");
            cout << endl;
            spasi(34, "Pilih Menu : ");
                cin >> menu;
                if (menu == 1) {
                    system("CLS");
                    tambahEvent(LE);
                } else if (menu == 2) {
                    system("CLS");
                    string namaEvent;
                    char pil;
                    cout << "Cari Nama Event : "; cin >> namaEvent;
                    adr_Event P = cariEvent(LE, namaEvent);
                    if (P == nil) {
                        cout << "Tidak ada event bernama " << namaEvent << " " << endl;
                        system("pause");
                        system("CLS");
                        menu = 3;
                        menuEvent(LE, LR);
                    } else {
                        cout << endl;
                        cout << "Nama Event : " << info(P).namaEvent << endl;
                        cout << "Budget Yang dibutuhkan : " << info(P).butuhBudget << endl;
                        cout << "Budget Kurang : " << info(P).budgetKurang << endl;
                        cout << "\nApakah anda yakin menghapus data ini ? [y/n] "; cin >> pil;
                        if (pil == 'y') {
                            adr_Relasi R = first(LR);
                            while (R != nil) {
                                if (info(P).namaEvent == info(Event(R)).namaEvent) {
                                    hapusRelasi(LR, R);
                                }
                                R = next(R);
                            }
                            hapusEvent(LE, namaEvent, P);
                            system("CLS");
                            menu = 3;
                            menuEvent(LE, LR);
                        } else if (pil == 'n') {
                            system("CLS");
                            menu = 3;
                            menuEvent(LE, LR);
                        }
                    }
                }
        } while (menu == 1 || menu == 2);
    }
}

void menuSponsor(ListSponsor &LS, ListRelasi &LR)
{
    int menu = 0;
    while (menu != 3) {
        do {
            system("cls");
            spasi(120, "=====================================\n");
            spasi(122, "MENU SPONSOR\n");
            spasi(120, "=====================================\n");
            cout << endl;
            spasi(25, "No. ");
            spasi(35, "Nama Sponsor ");
            spasi(45, "Budget Sponsor ");
            spasi(55, "Sisa Budget ");
            cout << endl;
            showSponsor(LS);
            cout << endl;
            cout << endl;
            spasi(40, "1. Tambah Sponsor \n");
            spasi(38, "2. Hapus Sponsor \n");
            spasi(33, "3. Kembali \n");
            cout << endl;
            spasi(34, "Pilih Menu : "); cin >> menu;

            if (menu == 1) {
                system("CLS");
                tambahSponsor(LS);
            } else if (menu == 2) {
                system("CLS");
                string namaSponsor;
                char pil;
                cout << "Cari Nama Sponsor : "; cin >> namaSponsor;
                adr_Sponsor P = cariSponsor(LS, namaSponsor);
                if (P == nil) {
                    cout << "Tidak Ditemukan\n";
                    system("pause");
                    system("CLS");
                    menu = 3;
                    menuSponsor(LS, LR);
                } else {
                    cout << "Nama Sponsor : " << info(P).namaSponsor << endl;
                    cout << "Budget Awal : " << info(P).budget << endl;
                    cout << "Sisa Budget : " << info(P).sisaBudget << endl;
                    cout << "\nApakah anda yakin menghapus data ini ? [y/n] "; cin >> pil;
                    if (pil == 'y') {
                        adr_Relasi R = first(LR);
                        while (R != nil) {
                            if (info(P).namaSponsor == info(Sponsor(R)).namaSponsor) {
                                hapusRelasi(LR, R);
                            }
                            R = next(R);
                        }

                        hapusSponsor(LS, namaSponsor, P);
                        system("CLS");
                        menu = 3;
                        menuSponsor(LS, LR);
                    } else if (pil == 'n') {
                        system("CLS");
                        menu = 3;
                        menuSponsor(LS, LR);
                    }
                }
            }
        } while (menu == 1 || menu == 2);
    }
}

void menuRelasi(ListEvent &LE, ListSponsor &LS, ListRelasi &LR)
{

}

void spasi(int jum, char* kata){
    int l = strlen(kata);
    int pos = (int)((jum - l) / 2);
    for (int i = 0; i < pos; i++) { cout << " "; }
    cout << kata;
}
