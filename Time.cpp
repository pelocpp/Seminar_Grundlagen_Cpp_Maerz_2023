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
    // �berpr�fung der Parameter
    if (hour >= 0 && hour < 24) {
        m_hour = hour;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert f�r Stunden: %d\n", hour);
    }
}

int Time::getMinute()
{
    return m_minute;
}

void Time::setMinute(int minute)
{
    // �berpr�fung der Parameter
    if (minute >= 0 && minute < 60) {
        m_minute = minute;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert f�r Minuten: %d\n", minute);
    }
}

int Time::getSecond()
{
    return m_second;
}

void Time::setSecond(int second)
{
    // �berpr�fung der Parameter
    if (second >= 0 && second < 60) {
        m_second = second;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert f�r Sekunden: %d\n", second);
    }
}

// Methods
void Time::print()
{
    printf("%d:%d:%d\n", m_hour, m_minute, m_second);
}


// 1. Variante
//void Time::add(Time time)
//{
//    // Ist noch nicht behandelt: �BERLAUF
//
//    m_hour = m_hour + time.m_hour;
//    m_minute = m_minute + time.m_minute;
//    m_second = m_second + time.m_second;
//}


// 2. Variante
Time Time::add(Time time)
{
    Time result;

    result.m_hour = m_hour + time.m_hour;
    result.m_minute = m_minute + time.m_minute;
    result.m_second = m_second + time.m_second;

    return result;
}