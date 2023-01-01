#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "Event.h"
#include "Sponsor.h"
#include <iostream>

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define Sponsor(P) P->Sponsor
#define Event(P) P->Event
#define nil NULL

using namespace std;

struct relasi {
    string level;
    int danaSponsorship;
};

typedef relasi infotypeR;
typedef struct elmRelasi *adr_Relasi;

struct elmRelasi {
    infotypeR info;
    adr_Relasi next;
    adr_Relasi prev;
    adr_Sponsor Sponsor;
    adr_Event Event;
};

struct ListRelasi {
    adr_Relasi first;
};

void createListRelasi(ListRelasi &L);
adr_Relasi newRelasi(adr_Event E, adr_Sponsor S, infotypeR x);
void delRelasi(adr_Relasi &P);
void insertFirstRelasi(ListRelasi &L, adr_Relasi P);
void insertLastRelasi(ListRelasi &L, adr_Relasi P);
void inserAfterRelasi(ListRelasi &L, adr_Relasi Prec, adr_Relasi P);
void deleteFirstRelasi(ListRelasi &L, adr_Relasi &P);
void deleteLastRelasi(ListRelasi &L, adr_Relasi &P);
void deleteAfterRelasi(ListRelasi &L, adr_Relasi Prec, adr_Relasi &P);
adr_Relasi cariRelasi(ListRelasi L, adr_Event E, adr_Sponsor S);
void showRelasi(ListRelasi L);
void tambahRelasi(ListEvent &LE, ListSponsor &LS, ListRelasi &LR, adr_Event E, adr_Sponsor S, string level, int persen);
void hapusRelasi(ListRelasi &L, adr_Relasi &P);

#endif // RELASI_H_INCLUDED
