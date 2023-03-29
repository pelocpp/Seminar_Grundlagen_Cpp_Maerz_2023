#include <iostream>
#include <exception>

#include "Time.h"
#include "BigData.h"

// ============================================================

// Realisierung der Klasse BigData

BigData::BigData() 
{
    m_count = 0;
    m_data = nullptr; 
    // m_data = 0;
}

BigData::BigData(int count) 
{
    m_count = count; 

    m_data = new int[count];

    // Feld vorbelegen
    for (int i = 0; i < m_count; ++i) {
        m_data[i] = 0;
    }
}

BigData::BigData(const BigData& other)
{
    m_count = other.m_count;

    // NEIN
    // m_data = other.m_data;

    // allocate new memory
    m_data = new int[other.m_count];

    // copy buffer from other object into this object
    for (int i = 0; i < m_count; ++i) {
        m_data[i] = other.m_data[i];
    }
}

BigData::~BigData()    // d'tor
{
    // mit new allokierte Daten freigeben
    delete[] m_data;
}

BigData& BigData::operator= (const BigData& other)
{
    // delete 'old' contents
    delete[] m_data;

    // build new contents - according to 'other'
    m_count = other.m_count;

    m_data = new int[other.m_count];

    // copy buffer from 'other' object into this object
    for (int i = 0; i < other.m_count; ++i) {
        m_data[i] = other.m_data[i];
    }

    return *this;   // this: ist vom Typ BigData* - deshalb *this
}


// ============================================================

void beobachtung()
{
    int n = 1;

    int m (n);  // Kopie erstellen - geht automatisch - Kopierkonstruktor :)

    n = m;      // Wertzuweisung


    Time t(9, 26, 30);
    std::cout << t << std::endl;

    Time t2(t);       // Kopie erstellen - geht automatisch - Kopierkonstruktor
    std::cout << t2 << std::endl;

    Time t3;
    t3 = t;           // Wertzuweisung - geht automatisch
    std::cout << t3 << std::endl;

    // Stolperfalle
    Time t4 = t;      // Kopier-Konstruktor
    std::cout << t4 << std::endl;
}

// ============================================================


void testBigData()
{
    BigData data1(10);

    BigData data2(data1);  // Kopie erstellen - geht automatisch - Kopierkonstruktor

    // <---: Es wird an data eine Methode zum Freigeben der Daten aufgerufen
    // <---: Destruktor 
}


void testBigData02()
{
    BigData data1(10);

    BigData data2(20);

    data1 = data2;       // Wertzuweisung 
}

int main_big_data()
{
    testBigData02();

    return 0;
}
