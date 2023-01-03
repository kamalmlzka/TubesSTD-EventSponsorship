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
                    char pil; cin.ignore();
                    cout << "Cari Nama Event : "; getline(cin, namaEvent);
                    adr_Event P = cariEvent(LE, namaEvent);
                    if (P == nil) {
                        cout << "Tidak ada event bernama " << namaEvent << " " << endl;
                        system("pause");
                        system("CLS");
                        menu = 3;
                        menuEvent(LE, LR);
                    } else {
                        system("cls");
                        cout << "Nama Event : " << info(P).namaEvent << endl;
                        cout << "Budget Yang dibutuhkan : " << info(P).butuhBudget << " juta" << endl;
                        cout << "Budget Kurang : " << info(P).budgetKurang << " juta" << endl;
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
            spasi(122, "DAFTAR SPONSOR\n");
            spasi(120, "=====================================\n");
            cout << endl;
            spasi(25, "No. ");
            spasi(31, "Nama Sponsor ");
            spasi(49, "Budget Sponsor ");
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
                char pil; cin.ignore();
                cout << "Cari Nama Sponsor : "; getline(cin, namaSponsor);
                adr_Sponsor P = cariSponsor(LS, namaSponsor);
                if (P == nil) {
                    cout << "Tidak Ditemukan\n";
                    system("pause");
                    system("CLS");
                    menu = 3;
                    menuSponsor(LS, LR);
                } else {
                    system("cls");
                    cout << "Nama Sponsor : " << info(P).namaSponsor << endl;
                    cout << "Budget Awal : " << info(P).budget  << " juta"<< endl;
                    cout << "Sisa Budget : " << info(P).sisaBudget  << " juta"<< endl;
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
    int menu = 0;
    string namaEvent, namaSponsor;
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
            spasi(120, "=====================================\n");
            spasi(122, "DAFTAR SPONSOR\n");
            spasi(120, "=====================================\n");
            cout << endl;
            spasi(25, "No. ");
            spasi(31, "Nama Sponsor ");
            spasi(49, "Budget Sponsor ");
            spasi(55, "Sisa Budget ");
            cout << endl;
            showSponsor(LS);
            cout << endl;
            cout << endl;
            cout << endl;
            spasi(40, "1. Tambah Relasi \n");
            spasi(43, "2. List Sponsorship \n");
            spasi(35, "3. Kembali \n");
            cout << endl;
            spasi(34, "Pilih Menu : "); cin >> menu;
            if (menu == 1) {
                int pilihLevel;
                system("cls");
                adr_Sponsor C;
                relasi relasiBaru;
                sponsor sponsorBaru;
                event eventBaru;
                adr_Event E = first(LE);
                cin.ignore();

                if (E != nil) {
                    cout << "Nama Event\n";
                    do {
                        cout << info(E).namaEvent << endl;
                        E = next(E);
                    } while (E != first(LE));
                    cout << endl;
                    cout << "Masukan Nama Event Yang Akan Didukung : "; getline(cin, namaEvent);
                    adr_Event P = cariEvent(LE,namaEvent);
                    if (P == nil) {
                        cout << "Event tidak ditemukan" << endl;
                        system("pause");
                    }
                    if (P != nil) {
                        system("cls");
                        cout << "Nama Event : " << info(P).namaEvent << endl;
                        cout << "Dana Yang Dibutuhkan : " << info(P).butuhBudget << " juta" << endl;
                        cout << "Dana Lebih : " << info(P).budgetLebih << " juta" << endl;
                        cout << "Level Sponsorship : \n";
                        cout << "1.Grand-Master = 100%\n";
                        cout << "2.Master = 65%\n";
                        cout << "3.Diamond = 50%\n";
                        cout << "4.Platinum = 25%\n";
                        cout << "5.Gold = 15%\n";
                        cout << "6.Silver = 10%\n";
                        cout << "7.Bronze = 5%\n";
                        cout << "Pilih Level Sponsorship : "; cin >> pilihLevel;
                        cout << "Masukan nama sponsor anda : "; cin.ignore(); getline(cin, namaSponsor);
                        C = cariSponsor(LS, namaSponsor);
                        if (C == nil) {
                            cout << "Sponsor tidak ditemukan !!\n";
                            system("pause");
                        } else {
                            if (pilihLevel == 1&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Grand-Master", 100);
                            } else if (pilihLevel == 2&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Master", 65);
                            } else if (pilihLevel == 3&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Diamond", 50);
                            } else if (pilihLevel == 4&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Platinum", 25);
                            } else if (pilihLevel == 5&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Gold", 15);
                            } else if (pilihLevel == 6&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Silver", 10);
                            } else if (pilihLevel == 7&&C!=nil) {
                                tambahRelasi(LE, LS, LR, P, C, "Bronze", 5);
                            }
                        }
                    }
                } else {
                    cout << "Silahkan tambah event & sponsor terlebih dahulu\n";
                    system("pause");
                }
            } else if (menu == 2) {
                system("cls");
                int i = 1;
                cin.ignore();
                cout << "Masukan Nama Event : "; getline(cin, namaEvent);
                adr_Event P = cariEvent(LE, namaEvent);
                adr_Relasi R = first(LR);

                if (R != nil && P != nil) {
                    system("cls");
                    spasi(120, "=====================================\n");
                    spasi(115, "DAFTAR SPONSORSHIP "); cout << namaEvent << endl;
                    spasi(120, "=====================================\n");
                    cout << endl;
                    spasi(60, "No. ");
                    spasi(15, "Nama Sponsor ");
                    spasi(25, "Level Sponsorship");
                    spasi(35, "Dana Sponsorship ");
                    cout << endl;
                    while (R != nil) {
                        if (info(Event(R)).namaEvent == namaEvent) {
                            cout << " " << setiosflags(ios::right) << setw(0);
                            cout << " " << setiosflags(ios::left) << setw(28) << i++;
                            cout << " " << setiosflags(ios::left) << setw(14) << info(Sponsor(R)).namaSponsor;
                            cout << " " << setiosflags(ios::left) << setw(21) << info(R).level;
                            cout << " " << setiosflags(ios::left) << setw(19) << info(R).danaSponsorship << " juta" << endl;
                        }
                        R = next(R);
                    }
                    cout << endl;
                    spasi(40, "1. Batal Donasi\n");
                    spasi(36, "2. Kembali\n");
                    cout << endl;
                    spasi(34, "Pilih Menu : "); cin >> menu;
                    if (menu == 1) {
                        cout << "Masukan Nama Sponsor : "; cin.ignore(); getline(cin, namaSponsor);
                        adr_Sponsor C = cariSponsor(LS, namaSponsor);
                        adr_Relasi Q = cariRelasi(LR, P, C);
                        if (Q != nil) {
                            info(C).sisaBudget = info(C).sisaBudget + info(Q).danaSponsorship;
                            info(P).budgetKurang = info(P).budgetKurang + info(Q).danaSponsorship;
                            if (info(P).budgetLebih > 0) {
                                info(P).budgetLebih = info(P).budgetLebih - info(Q).danaSponsorship;
                            }
                            cout << "\n";
                            hapusRelasi(LR, Q);
                            cout << "Sponsor " << info(C).namaSponsor << " batal mendukung Event " << namaEvent << endl;
                            system("pause");
                        } else {
                            cout << "Tidak Ditemukan\n";
                        }
                    }
                } else {
                    cout << "Tidak ada relasi\n";
                    system("pause");
                }
            }
        } while (menu == 1 || menu == 2);
    }
}

void spasi(int jum, char* kata){
    int l = strlen(kata);
    int pos = (int)((jum - l) / 2);
    for (int i = 0; i < pos; i++) { cout << " "; }
    cout << kata;
}
