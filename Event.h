#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define nil NULL

using namespace std;

struct event {
    string namaEvent;
    int butuhBudget;
    int budgetKurang;
    int budgetLebih;
    int counter;
};

typedef event infotypeE;
typedef struct elmListEvent *adr_Event;

struct elmListEvent {
    infotypeE info;
    adr_Event next;
};

struct ListEvent {
    adr_Event first;
    adr_Event last;
};

void createListEvent(ListEvent &L);
adr_Event newEvent(infotypeE x);
void delEvent(adr_Event &P);
bool isEmptyListEvent(ListEvent L);
void insertFirstEvent(ListEvent &L, adr_Event P);
void insertLastEvent(ListEvent &L, adr_Event P);
void inserAfterEvent(ListEvent &L, adr_Event P, adr_Event Prec);
void deleteFirstEvent(ListEvent &L, adr_Event &P);
void deleteLastEvent(ListEvent &L, adr_Event &P);
void deleteAfterEvent(ListEvent &L, adr_Event &P, adr_Event Prec);
adr_Event cariEvent(ListEvent L, string namaEvent);
void showEvent(ListEvent &L);
void tambahEvent(ListEvent &L);
void hapusEvent(ListEvent &L, string namaEvent, adr_Event &P);

#endif // EVENT_H_INCLUDED
