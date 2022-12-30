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

}

void inserAfterEvent(adr_Relasi Prec, adr_Relasi P)
{

}

void deleteFirstRelasi(ListRelasi &L, adr_Relasi &P)
{

}

void deleteLastRelasi(ListRelasi &L, adr_Relasi &P)
{

}

void deleteAfterRelasi(ListRelasi &L, adr_Relasi Prec, adr_Relasi &P)
{

}

adr_Relasi cariRelasi(ListRelasi L, adr_Event E, adr_Sponsor S)
{

}

void showRelasi(ListRelasi L)
{

}

void hapusRelasi(ListRelasi &L, adr_Relasi &P)
{

}
