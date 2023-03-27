#include <iostream>

#include "Time.h"

void test_swap();
void test_pointer_vs_reference();


int main()
{
    Time leer;

    //test_swap();
    test_pointer_vs_reference();
}

// Einsprungpunkt in das Programm
int main_mutable()
{
    printf("Hallo Seminar\n");

    Time now (13, 0, 0);

    Time abstand(4, 0, 0);

    // Variante 1
    now.add(abstand);

    // Variante 2
    //Time end;
    //end = now.add(abstand);

    return 0;
}


int main_01()
{
    printf("Hallo Seminar\n");

    Time now;

    //now.m_hour = 11;
    
    now.setHour(11);
    //now.m_minute = 0;
    //now.m_second = 0;

    now.print();

    Time pause;
    //pause.m_hour = 10;
    //pause.m_minute = 40;
    //pause.m_second = 30;

    pause.print();

    printf("Stunden von now: %d\n", now.getHour());

    Time mittags_pause (12, 0, 0);

    return 0;
}