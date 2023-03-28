#include <iostream>
#include <exception>

#include "Time.h"

Time* datenWerdenAngelegt ()
{
    Time* t = new Time();   // Standard-Konstruktor

    t->setHour(14);
    t->setMinute(30);
    t->setSecond(59);

    std::cout << *t << std::endl;

   // delete t;  // Objekt freigeben

    return t;
}

void datenWerdenVerwendet(Time* tp)
{
    tp->setHour(14);
    tp->setMinute(30);
    tp->setSecond(59);
}


int main()
{
    Time* tp = datenWerdenAngelegt();

    datenWerdenVerwendet(tp);

    delete tp;

    std::cout << "Fertig." << std::endl;

    return 0;
}


