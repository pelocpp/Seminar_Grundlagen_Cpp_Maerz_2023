// Realisierung / Implementierung der Methoden der Klasse Time


#include <vector> 

#include "Time.h" 

//Time::Time()
//{
//    m_hour = 0;
//    m_minute = 0;
//    m_second = 0;
//}

// Constructor Chaining
Time::Time() : Time (0, 0, 0) {}


Time::Time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

//int Time::getHour() const
//{
//    return m_hour;
//}

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

int Time::getMinute() const
{
    return m_minute;
}

void Time::setMinute(int minute)
{
    // Überprüfung der Parameter
    if (minute >= 0 && minute < 60) {
        m_minute = minute;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert für Minuten: %d\n", minute);
    }
}

int Time::getSecond() const
{
    return m_second;
}

void Time::setSecond(int second)
{
    // Überprüfung der Parameter
    if (second >= 0 && second < 60) {
        m_second = second;
    }
    else
    {
        // Silent Error Recovery: Falscher wert wird ignoriert.

        // Logging:
        printf("Falscher Wert für Sekunden: %d\n", second);
    }
}

// Methods
void Time::print()
{
    printf("%d:%d:%d\n", m_hour, m_minute, m_second);
}


// 1. Variante
void Time::add(const Time& time)  // mutable
{
    // Ist noch nicht behandelt: ÜBERLAUF

    m_hour = m_hour + time.m_hour;
    m_minute = m_minute + time.m_minute;
    m_second = m_second + time.m_second;
}


// 2. Variante
//Time Time::add(Time time)
//{
//    Time result;
//
//    result.m_hour = m_hour + time.m_hour;
//    result.m_minute = m_minute + time.m_minute;
//    result.m_second = m_second + time.m_second;
//
//    return result;
//}


//Time Time::add2(const Time& time) const
//{
//    Time result;
//
//    result.m_hour =   m_hour   + time.getHour();
//    result.m_minute = m_minute + time.m_minute;
//    result.m_second = m_second + time.m_second;
//
//    return result;
//}

//Time Time::add2(const Time& time) const
//{
//    int hour = m_hour + time.getHour();
//    int minute = m_minute + time.m_minute;
//    int second = m_second + time.m_second;
//
//    Time result(hour, minute, second);  // geeigneten Konstruktor
//    return result;
//}

Time Time::add2(const Time& time) const
{
    int hour = m_hour + time.getHour();
    int minute = m_minute + time.m_minute;
    int second = m_second + time.m_second;

    return Time (hour, minute, second);   // geeigneten Konstruktor
}