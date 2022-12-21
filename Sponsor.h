#ifndef SPONSORLIB_H_INCLUDED
#define SPONSORLIB_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
#define nil NULL

using namespace std;

struct sponsor {
    string namaSponsor;
    int budget, sisaBudget;
    int counter;
};

typedef sponsor infotype;

typedef struct elmListSponsor *adr_Sponsor;

struct elmListSponsor {
    infotype info;
    adr_Sponsor next;
};

struct ListSponsor {
    adr_Sponsor first;
};

void createListSponsor(ListSponsor &L);
adr_Sponsor newSponsor(infotype x);
void insertLastSponsor(ListSponsor &L, adr_Sponsor P);
void deleteFirstSponsor(ListSponsor &L, adr_Sponsor P);
adr_Sponsor cariSponsor(ListSponsor L, string namaSponsor);
void showSponsor(ListSponsor &L);
void tambahSponsor(ListSponsor &L);
void hapusSponsor(ListSponsor &L, string namaSponsor, adr_Sponsor &P);

#endif // SPONSORLIB_H_INCLUDED
