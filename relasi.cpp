#include "relasi.h"

void createListRelasi(ListRelasi &L)
{
    first(L) = nil;
}

adr_Relasi newRelasi(adr_Event E, adr_Sponsor S, infotypeR x)
{
    adr_Relasi Q;

    Q = new elmRelasi;
    Sponsor(Q) = S;
    Event(Q) = E;
    info(Q) = x;
    next(Q) = nil;
    prev(Q) = nil;
    return Q;
}

void delRelasi(adr_Relasi &P)
{
    delete P;
}

void insertFirstRelasi(ListRelasi &L, adr_Relasi P)
{
    if (first(L) == nil) {
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastRelasi(ListRelasi &L, adr_Relasi P)
{
    if (first(L) == nil) {
        insertFirstRelasi(L, P);
    } else {
        adr_Relasi Q = first(L);
        while (next(Q) != nil) {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}

void inserAfterRelasi(ListRelasi &L, adr_Relasi Prec, adr_Relasi P)
{
    if (first(L) == nil) {
        insertFirstRelasi(L, P);
    } else {
        if (first(L) == Prec) {
            insertFirstRelasi(L, P);
        } else if (next(Prec) == nil) {
            insertLastRelasi(L, P);
        } else {
            next(P) = next(Prec);
            prev(next(Prec)) = P;
            prev(P) = Prec;
            next(Prec) = P;
        }
    }
}

void deleteFirstRelasi(ListRelasi &L, adr_Relasi &P)
{
    if (first(L) == nil) {
        cout << "List Kosong";
    } else if (next(P) == nil) {
        first(L) = nil;
        Sponsor(P) = nil;
        Event(P) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(next(P)) = nil;
        next(P) = nil;
        Sponsor(P) = nil;
        Event(P) = nil;
    }
}

void deleteLastRelasi(ListRelasi &L, adr_Relasi &P)
{
    if (first(L) == nil) {
        cout << "List Kosong";
    } else if (first(L) == P) {
        deleteFirstRelasi(L,P);
    } else {
        adr_Relasi Q = first(L);
        while(next(next(Q)) != nil){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = nil;
        prev(P) = nil;
        Sponsor(P) = nil;
        Event(P) = nil;

    }
}

void deleteAfterRelasi(ListRelasi &L, adr_Relasi Prec, adr_Relasi &P)
{
   if (first(L) == nil) {
        cout << "List Kosong";
   } else {
        if (first(L) == P) {
            deleteFirstRelasi(L ,P);
        } else if (next(P) == nil) {
            deleteLastRelasi(L ,P);
        } else {
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = nil;
            prev(P) = nil;
            Sponsor(P) = nil;
            Event(P) = nil;
        }
   }
}

adr_Relasi cariRelasi(ListRelasi L, adr_Event E, adr_Sponsor S)
{
    adr_Relasi Q = first(L);

    while(Q != nil){
        if(Event(Q) == E && Sponsor(Q) == S){
            return Q;
        }
        Q = next(Q);
    }
    return nil;
}

void showRelasi(ListRelasi L)
{
    adr_Relasi Q = first(L);
    long budget = info(Event(Q)).butuhBudget - info(Q).budgetDukungan;
    while (Q != nil) {
        cout << info(Event(Q)).namaEvent << "\n";
        cout << info(Sponsor(Q)).namaSponsor << "\n";
        cout << info(Q).dukungan << "\n";
        cout << budget << "\n";
    }
}

void hapusRelasi(ListRelasi &L, adr_Relasi &P)
{
    if (P == nil) {
        cout << "List Kosong";
    } else {
        if (first(L) == P) {
            deleteFirstRelasi(L, P);
        } else if (next(P) == nil) {
            deleteLastRelasi(L, P);
        } else {
            adr_Relasi Prec = first(L);
            while(next(Prec) != P){
                Prec = next(Prec);
            }
            deleteAfterRelasi(L, P, Prec);
        }
    }
}
