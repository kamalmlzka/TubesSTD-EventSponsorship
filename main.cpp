#include <iostream>
#include "Event.h"

using namespace std;

int main()
{
    cout<<"||========================================================||"<<endl;
    cout<<"||             TUBES STD - Event Sponsorship              ||"<<endl;
    cout<<"||========================================================||"<<endl;
    cout<<"||    Anggota : 1. Muhammad Zaidan Rafif (1302213072)     ||"<<endl;
    cout<<"||              2. Kamal Maulaazka Sidhqi (1302210032)    ||"<<endl;
    cout<<"||========================================================||"<<endl;

    ListEvent L;
    tambahEvent(L);

    showEvent(L);

    return 0;
}
