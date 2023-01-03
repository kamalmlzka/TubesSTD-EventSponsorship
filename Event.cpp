#include "Event.h"
#include "menu.h"

void createListEvent(ListEvent &L)
{
    first(L) = nil;
    last(L) = nil;
}

adr_Event newEvent(infotypeE x)
{
    adr_Event P;

    P = new elmListEvent;
    info(P) = x;
    next(P) = nil;
    return P;
}

void delEvent(adr_Event &P)
{
    delete P;
}

bool isEmptyListEvent(ListEvent L)
{
    if ((first(L) == nil) && (last(L) == nil)) {
        return true;
    } else {
        return false;
    }
}

void insertFirstEvent(ListEvent &L, adr_Event P)
{
    if (isEmptyListEvent(L) == true) {
        first(L) = P;
        last(L) = P;
        next(last(L)) = P;
    } else {
        next(P) = first(L);
        next(last(L)) = P;
        first(L) = P;
    }
}

void insertLastEvent(ListEvent &L, adr_Event P)
{
    if (isEmptyListEvent(L) == true) {
        insertFirstEvent(L, P);
    } else {
        next(last(L)) = P;
        next(P) = first(L);
        last(L) = P;
    }
}

void inserAfterEvent(ListEvent &L, adr_Event P, adr_Event Prec)
{
    if (isEmptyListEvent(L) == true) {
        insertFirstEvent(L, P);
    } else {
        if (Prec == last(L)) {
            insertFirstEvent(L, P);
        } else if (next(Prec) == last(L)) {
            insertLastEvent(L, P);
        } else {
            adr_Event Q;

            Q = next(Prec);
            next(Prec) = P;
            next(P) = Q;
        }
    }
}

void deleteFirstEvent(ListEvent &L, adr_Event &P)
{
    if (isEmptyListEvent(L) == true) {
        cout << "Event Kosong" << endl;
    } else if (first(L) == last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = nil;
        next(last(L)) = first(L);
    }
}

void deleteLastEvent(ListEvent &L, adr_Event &P)
{
    if (isEmptyListEvent(L) == true) {
        cout << "Event Kosong" << endl;
    } else if (first(L) == last(L)) {
        deleteFirstEvent(L, P);
    } else if (next(first(L)) == first(L)) {
        deleteFirstEvent(L, P);
    } else {
        adr_Event Q;

        Q = first(L);
        while (next(Q) != last(L)) {
            Q = next(Q);
        }
        P = last(L);
        next(P) = nil;
        next(Q) = first(L);
        last(L) = Q;
    }
}

void deleteAfterEvent(ListEvent &L, adr_Event &P, adr_Event Prec)
{
    if (isEmptyListEvent(L) == true) {
        cout << "Event Kosong" << endl;
    } else if (next(first(L)) == first(L)) {
        deleteFirstEvent(L, P);
    } else {
        if (Prec == last(L)) {
            P = next(Prec);
            deleteFirstEvent(L, P);
        } else if (next(Prec) == last(L)) {
            P = next(Prec);
            deleteLastEvent(L, P);
        } else {
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = nil;
        }
    }
}

adr_Event cariEvent(ListEvent L, string namaEvent)
{
    adr_Event P, Q;
    bool found = false;

    if (isEmptyListEvent(L) == true) {
        cout << "Event Kosong" << endl;
    } else {
        P = first(L);
        do{
            if (info(P).namaEvent == namaEvent) {
                found = true;
                Q = P;
            }
            P = next(P);
        } while (P != first(L));
    }
    if (found == true) {
        return Q;
    } else if (found == false) {
        return nil;
    }
}

void showEvent(ListEvent &L)
{
    adr_Event P = first(L);
    int i = 1;

    if (isEmptyListEvent(L) == true) {
        cout << " " << setiosflags(ios::right) << setw(12) << "nil";
        cout << " " << setiosflags(ios::left) << setw(21) << "Event Kosong";
    } else {
        do {
            cout << " " << setiosflags(ios::right) << setw(7);
            cout << " " << setiosflags(ios::left) << setw(4) << i++;
            cout << " " << setiosflags(ios::left) << setw(20) << info(P).namaEvent;
            cout << " " << setiosflags(ios::left) << setw(19) << info(P).butuhBudget << " juta";
            cout << " " << setiosflags(ios::left) << setw(20) << info(P).budgetKurang << " juta";
            cout << " " << setiosflags(ios::left) << setw(22) << info(P).budgetLebih << " juta" << endl;
            P = next(P);
        } while(P != first(L));
    }
}

void tambahEvent(ListEvent &L)
{
    int menu = 0;
    event eventBaru;

    while (menu != 2) {
        do {
            system("CLS");
            cin.ignore();
            cout << "Nama Event           : "; getline(cin, eventBaru.namaEvent);
            cout << "Dana yang dibutuhkan (juta) : "; cin >> eventBaru.butuhBudget;
            eventBaru.budgetKurang = eventBaru.butuhBudget;
            eventBaru.budgetLebih = 0;
            eventBaru.counter = 0;

            adr_Event P = newEvent(eventBaru);
            insertFirstEvent(L, P);

            cout << endl;
            cout << "1. Tambah Data Event Lagi\n";
            cout << "2. Kembali\n";
            cout << "Pilih Menu: "; cin >> menu;
        } while (menu == 1);
    }
}

void hapusEvent(ListEvent &L, string namaEvent, adr_Event &P)
{
    adr_Event Q;
    bool found = false;

    if (P == nil) {
        cout << "Data tidak ditemukan\n";
    } else {
        if (P == first(L)) {
            deleteFirstEvent(L, P);
            delEvent(P);
        } else if (P == last(L)) {
            deleteLastEvent(L, P);
            delEvent(P);
        } else if (first(L) == last(L)) {
            deleteFirstEvent(L, P);
            delEvent(P);
        } else {
            adr_Event Prec;
            Q = first(L);

            do {
                if (next(Q) == P) {
                    found = true;
                    Prec = Q;
                }
                Q = next(Q);
            } while(next(Q) != first(L));
            deleteAfterEvent(L, P, Prec);
            delEvent(P);
        }
    }
}
