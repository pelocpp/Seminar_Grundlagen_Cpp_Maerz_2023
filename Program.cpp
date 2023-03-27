#include <iostream>

#include "Time.h"

// Einsprungpunkt in das Programm
int main()
{
    printf("Hallo Seminar\n");

    Time now;

    now.hour = 10;
    now.minute = 26;
    now.second = 0;

    now.print();

    Time pause;

    pause.hour = 10;
    pause.minute = 40;
    pause.second = 30;

    pause.print();

    printf("Stunden von now: %d\n", now.hour);

    return 0;
}