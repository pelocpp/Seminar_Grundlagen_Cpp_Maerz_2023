#include <iostream>

#include "Time.h"

// Einsprungpunkt in das Programm
int main()
{
    printf("Hallo Seminar\n");

    Time now;

    //now.m_hour = 11;
    
    now.setHour(1000);
    
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