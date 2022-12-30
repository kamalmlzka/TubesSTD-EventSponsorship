#include <iostream>
#include "Event.h"
#include "Sponsor.h"
#include "relasi.h"
#include "menu.h"

using namespace std;

int main()
{
    ListEvent LE;
    ListSponsor LS;
    ListRelasi LR;
    createListEvent(LE);
    createListSponsor(LS);
    createListRelasi(LR);

    mainMenu(LE,LS,LR);

    return 0;
}
