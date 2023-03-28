// Realisierung / Implementierung der Methoden der Klasse Time


#include <iostream> 
#include <iomanip> 

#include "Time.h" 

//Time::Time()
//{
//    m_hour = 0;
//    m_minute = 0;
//    m_second = 0;
//}

// Constructor Chaining  // C++ 17 oder aufwärts
Time::Time() : Time (0, 0, 0)
{
    std::cout << "c'tor()" << std::endl;
}


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

//void Time::setHour(int hour)
//{
//    // Überprüfung der Parameter
//    if (hour >= 0 && hour < 24) {
//        m_hour = hour;
//    }
//    else
//    {
//        // Silent Error Recovery: Falscher wert wird ignoriert.
//
//        // Logging:
//        printf("Falscher Wert für Stunden: %d\n", hour);
//    }
//}

void Time::setHour(int hour)
{
    // Überprüfung der Parameter
    if (hour >= 0 && hour < 24) {
        m_hour = hour;
    }
    else
    {
        throw std::exception("Falscher Wert für Stunde");    
    }

    //  std::cout << "Ende von setHour ???" << std::endl;
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


//Time Time::operator+ (const Time& time) const
//{
//    int hour = m_hour + time.m_hour;
//    int minute = m_minute + time.m_minute;
//    int second = m_second + time.m_second;
//
//    return Time (hour, minute, second);   // geeigneten Konstruktor
//}

// =======================================================
// Definition eines Operators als "globale Funktion"

//Time operator+ (const Time& left, const Time& right)
//{
//    Time result;
//
//    int hour = left.getHour() + right.getHour();
//    int minute = left.getMinute() + right.getMinute();
//    int second = left.getSecond() + right.getSecond();
//
//    result.setHour(hour);
//    result.setMinute(minute);
//    result.setSecond(second);
//
//    return result;
//}

// =======================================================
// Definition eines Operators als "globale Funktion"

Time operator+ (const Time& left, const Time& right)
{
    Time result;

    result.m_hour =   left.m_hour +   right.m_hour;
    result.m_minute = left.m_minute + right.m_minute;
    result.m_second = left.m_second + right.m_second;

    return result;
}

//void operator<< (std::ostream& os, const Time& time)
//{
//    // 10:30:40
//    os << time.getHour() << ':' << time.getMinute() << ':' << time.getSecond();
//}

std::ostream& operator<< (std::ostream& os, const Time& time)
{
    // 10:30:40
    os 
        << std::setw(2) << std::setfill('0') << time.getHour() << ':'
        << std::setw(2) << std::setfill('0') << time.getMinute() << ':'
        << std::setw(2) << std::setfill('0') << time.getSecond();

    return os;
}