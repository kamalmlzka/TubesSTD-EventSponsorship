#include "Sponsor.h"

void createListSponsor(ListSponsor &L)
{
    first(L) = nil;
}

adr_Sponsor newSponsor(infotypeS x)
{
    adr_Sponsor P;

    P = new elmListSponsor;
    info(P) = x;
    next(P) = nil;
    return P;
}

void delSponsor(adr_Sponsor &P)
{
    delete P;
}

void insertFirstSponsor(ListSponsor &L, adr_Sponsor P)
{
    if (first(L) == nil) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastSponsor(ListSponsor &L, adr_Sponsor P)
{
    if (first(L) == nil) {
        insertFirstSponsor(L, P);
    } else {
        adr_Sponsor Q = first(L);
        while (next(Q) != nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void inserAfterSponsor(ListSponsor &L, adr_Sponsor P, adr_Sponsor Prec)
{
    if (first(L) == nil) {
        insertFirstSponsor(L, P);
    } else {
        if (first(L) == Prec) {
            insertFirstSponsor(L, P);
        } else if (next(Prec) == nil) {
            insertLastSponsor(L, P);
        } else {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void deleteFirstSponsor(ListSponsor &L, adr_Sponsor P)
{
    if (first(L) == nil) {
        cout << "List Kosong";
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = nil;
    }
}

void deleteLastSponsor(ListSponsor &L, adr_Sponsor P)
{
    if (first(L) == nil) {
        cout << "List Kosong";
    } else if (first(L) == nil) {
        deleteFirstSponsor(L, P);
    } else {
        adr_Sponsor Q = first(L);
        while (next(next(Q)) != nil) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = nil;
    }
}

void deleteAfterSponsor(ListSponsor &L, adr_Sponsor P, adr_Sponsor Prec)
{
    if (first(L) == nil) {
        cout << "List Kosong";
    } else {
        if (first(L) == P) {
            deleteFirstSponsor(L, P);
        } else if (next(P) == nil) {
            deleteLastSponsor(L, P);
        } else {
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = nil;
        }
    }
}

adr_Sponsor cariSponsor(ListSponsor L, string namaSponsor)
{
    adr_Sponsor P;

    if (first(L) == nil) {
        return nil;
    } else {
        adr_Sponsor Q = first(L);
        bool found = false;

        while ((Q != nil) && (found == false)) {
            if (info(Q).namaSponsor == namaSponsor) {
                found = true;
                P = Q;
            }
            Q = next(Q);
        }

        if (found == true) {
            return P;
        } else {
            return nil;
        }
    }
}

void showSponsor(ListSponsor &L)
{
    adr_Sponsor P;
    int i = 1;
    P = first(L);

    if (P == nil) {
        cout << " " << setiosflags(ios::right) << setw(12) << "nil";
        cout << " " << setiosflags(ios::left) << setw(25) << "Sponsor Kosong";
    }
    while (P != nil) {
        cout << " " << setiosflags(ios::right) << setw(7);
        cout << " " << setiosflags(ios::left) << setw(4) << i++;
        cout << " " << setiosflags(ios::left) << setw(22) << info(P).namaSponsor;
        cout << " " << setiosflags(ios::left) << setw(31) << info(P).budget;
        cout << " " << setiosflags(ios::left) << setw(32) << info(P).sisaBudget << endl;
        P = next(P);
    }
}

void tambahSponsor(ListSponsor &L)
{
    int menu = 0;
    sponsor sponsorBaru;

    while (menu != 2) {
        do {
            system("CLS");
            cin.ignore();
            cout << "Nama Sponsor : "; getline(cin, sponsorBaru.namaSponsor);
            cout << "Budget : "; cin >> sponsorBaru.budget;
            sponsorBaru.sisaBudget = sponsorBaru.budget;
            sponsorBaru.counter = 0;

            insertFirstSponsor(L, newSponsor(sponsorBaru));
            cout << "1.Tambah Data Sponsor Lagi\n";
            cout << "2.Kembali\n";
            cout << "Pilih Menu : "; cin >> menu;
        } while (menu == 1);
    }
}

void hapusSponsor(ListSponsor &L, string namaSponsor, adr_Sponsor &P)
{
    if (P == nil) {
        cout << "List Kosong";
    } else {
        if (first(L) == P) {
            deleteFirstSponsor(L, P);
        } else if (next(P) == NULL) {
            deleteLastSponsor(L, P);
        } else {
            adr_Sponsor Prec = first(L);
            while (next(Prec) != P) {
                Prec = next(Prec);
            }
            deleteAfterSponsor(L, P, Prec);
        }
    }
}
