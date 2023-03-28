#include <iostream>
#include <exception>

#include "Time.h"

void mehrereDatenWerdenAngelegt()
{
    int wieviele = 5;

    Time festeAnzahlUhrzeiten [5];

    Time* ts = new Time[wieviele];   // 5 Time-Objekte werden angelegt 

    // Zugriff -- mit dem Operator []

    int stundeErstesElement = ts[0].getHour();

    for (int i = 0; i < 5; ++i) 
    {
        ts[i].setHour(15);
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << ts[i] << std::endl;
    }

    delete[] ts;
}

void mehrereDatenWerdenAngelegtAlternate()
{
    Time* ts = new Time[5];   // 5 Time-Objekte werden angelegt 

    // Zugriff -- mit dem Operator []

    for (int i = 0; i < 5; ++i)
    {
        (ts + i)->setHour(15+i);
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << ts[i] << std::endl;
    }
}



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


int main_dynamic_01()
{
    Time* tp = datenWerdenAngelegt();

    datenWerdenVerwendet(tp);

    delete tp;

    std::cout << "Fertig." << std::endl;

    return 0;
}

int main()
{
    mehrereDatenWerdenAngelegt();

    return 0;
}

