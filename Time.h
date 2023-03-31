// Beschreibung / Schnittstelle / Interface einer Klasse

class Time
{
    friend Time operator+ (const Time& left, const Time& right);

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

    // Überladen: Eine Methode kann mehrere Male vorhanden sein  / NICHT: Überschreiben (override)

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

    void increment ();

    // 1. Variante
    void add(const Time& time);                 // mutable

    // 2. Variante
    // Time add(Time time);

    Time add2(const Time& time) const;   // immutable


    // Operators
    // Time operator+ (const Time& time) const;   // immutable

private:

};

// =======================================================
// Definition eines Operators als "globale Funktion"


// friend-Deklaration in der Klasse macht die nächste Zeile überflüssig:
Time operator+ (const Time& left, const Time& right);

// Ausgabe kann NUR ALS "globale Funktion" realisiert werden:
std::ostream& operator<< ( std::ostream& os, const Time& time);

