#ifndef SPONSOR_H_INCLUDED
#define SPONSOR_H_INCLUDED

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
#define nil NULL

using namespace std;

struct sponsor {
    string namaSponsor;
    long budget, sisaBudget;
    int counter;
};

typedef sponsor infotypeS;
typedef struct elmListSponsor *adr_Sponsor;

struct elmListSponsor {
    infotypeS info;
    adr_Sponsor next;
};

struct ListSponsor {
    adr_Sponsor first;
};

void createListSponsor(ListSponsor &L);
adr_Sponsor newSponsor(infotypeS x);
void delSponsor(adr_Sponsor &P);
void insertFirstSponsor(ListSponsor &L, adr_Sponsor P);
void insertLastSponsor(ListSponsor &L, adr_Sponsor P);
void inserAfterSponsor(ListSponsor &L, adr_Sponsor P, adr_Sponsor Prec);
void deleteFirstSponsor(ListSponsor &L, adr_Sponsor P);
void deleteLastSponsor(ListSponsor &L, adr_Sponsor P);
void deleteAfterSponsor(ListSponsor &L, adr_Sponsor P, adr_Sponsor Prec);
adr_Sponsor cariSponsor(ListSponsor L, string namaSponsor);
void showSponsor(ListSponsor &L);
void tambahSponsor(ListSponsor &L);
void hapusSponsor(ListSponsor &L, string namaSponsor, adr_Sponsor &P);

#endif // SPONSOR_H_INCLUDED
