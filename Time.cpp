// Realisierung / Implementierung der Methoden der Klasse Time


#include <vector> 

#include "Time.h" 

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}

Time::Time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

int Time::getHour()
{
    return m_hour;
}

void Time::setHour(int hour)
{
    // Überprüfung der Parameter
    if (hour >= 0 && hour < 24) {
        m_hour = hour;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert für Stunden: %d\n", hour);
    }
}


void Time::print()
{
    printf("%d:%d:%d\n", m_hour, m_minute, m_second);
}
