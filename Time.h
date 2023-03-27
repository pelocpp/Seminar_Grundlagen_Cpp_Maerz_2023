// Beschreibung / Schnittstelle / Interface einer Klasse

class Time
{
private:
    // data
    int m_hour;
    int m_minute;
    int m_second;

public:
    // Konstruktoren / constructors / c'tors
    Time();   // Spez. Konstruktor: Keine Parameter // Standard-Konstruktor

    Time(int h, int m, int s);   // Weiterer  Konstruktor: Mit Parameter 
              // Benutzer-definierte Konstruktor (user-defined)

public:
    // getter/setter
    // int getHour() const;
    int getHour() const { return m_hour; }
    int getMinute() const;
    int getSecond() const;

    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

public:
    // methods
    void print();

    // 1. Variante
    void add(const Time& time);                 // mutable

    // 2. Variante
    // Time add(Time time);

    Time add2(const Time& time) const;   // immutable

    // Time tomorrow();

private:

};