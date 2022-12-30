#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Event.h"
#include "Sponsor.h"
#include "relasi.h"

void mainMenu(ListEvent LE, ListSponsor LS, ListRelasi LR);
void menuEvent(ListEvent &LE, ListRelasi &LR);
void menuSponsor(ListSponsor &LS, ListRelasi &LR);
void menuRelasi(ListEvent &LE, ListSponsor &LS, ListRelasi &LR);
void execData(ListEvent &LE, ListSponsor &LS, ListRelasi &LR, adr_Event E, adr_Sponsor S, string grade, int persen);

void spasi(int jum, char* kata);

#endif // MENU_H_INCLUDED
