#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "Event.h"
#include "Sponsor.h"

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define Event(P) P->Event
#define Sponsor(P) P->Sponsor
#define first(L) L.first
#define nil NULL

using namespace std;

struct relasi {
    string dukungan;
    int budgetDukungan;
};

typedef struct elmRelasi *adr_Relasi;

typedef relasi infotype;

struct elmRelasi {
    infotype info;
    adr_Relasi next;
    adr_Relasi prev;
    adr_Sponsor Sponsor;
    adr_Event Event;
};

struct ListRelasi {
    adr_Relasi first;
};

void createListRelasi(ListRelasi &L,);
adr_Relasi newRelasi(adr_Event E, adr_Sponsor S, infotype x);
void insertLastRelasi(ListRelasi &L, adr_Relasi P);
void deleteFirstRelasi(ListRelasi &L, adr_Relasi &P);
adr_Relasi cariRelasi(ListRelasi L, adr_Event E, adr_Sponsor S);
void showRelasi(ListRelasi L);
void hapusRelasi(ListRelasi &L, adr_Relasi &P);

#endif // RELASI_H_INCLUDED
