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
    int getHour();
    void setHour(int hour);

public:
    // methods
    void print();

    // Time tomorrow();
};