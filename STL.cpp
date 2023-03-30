#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void stl_01()
{
    std::vector<int> v;   // new / delete / Rule-of-3

    v.reserve(90);   // vermeidet überflüssige new / delete

    for (int i = 0; i < 100; ++i) {

        v.push_back(2 * i);

        std::cout
            << "Index " << i << " - Size: " << v.size()
            << " - Capacity: " << v.capacity() << std::endl;
    }

    v.shrink_to_fit();

    std::cout << 
        "Size: " << v.size() << " - Capacity: " << v.capacity() << std::endl;
}


void stl_02()
{
    std::vector<int> v;

    // int n = 3;
    // int v2[n];  // ein Feld hat eine KONSTANTE Länge !

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); ++i) {

        // int elem = v.at(i); // at: langsamer / Bereichsüberprüfung / throw
        // oder
        int elem = v[i];    // operator[]: schneller / keine Bereichsüberprüfung

        std::cout << elem << std::endl;
    }
}

void stl_03()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator pos;

    pos = v.begin();

    // oder
    // auto pos1 = v.begin();

    if (pos == v.end())
        return;

    // Gib Wert aus
    int value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == v.end())
        return;

    // Gib Wert aus
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == v.end())
        return;

    // Gib Wert aus
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == v.end())
        return;

    // Gib Wert aus
    value = *pos;
    std::cout << value << std::endl;
}

void stl_04()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // Vorbereitung für den ersten Algorithmus

    std::vector<int>::iterator pos;
    std::vector<int>::iterator end;

    pos = v.begin();
    end = v.end();

    pos = std::next(pos);
    end = std::prev(end);

    while (pos != end) {

        int value = *pos;
        std::cout << value << std::endl;
        ++pos;
    }
}


void tueWasMitElement(int value) {
    std::cout << "tueWasMitElement: " << value << std::endl;
}

void stl_05()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // Unser erster Algorithmus: std::for_each

    std::for_each(
        v.begin(),
        v.end(),
        tueWasMitElement
    );
}

int fueller() {

    static int wert = 2;

    std::cout << "bin im Fueller: " << std::endl;
    
    wert = 2 * wert;
    
    return wert;
}

void stl_06()
{
    std::vector<int> v;

    v.resize(10);  // nicht zu verwechseln:  reserve ==>  Capacity

    // fill
    std::fill(
        v.begin(),
        v.end(),
        1
    );

    // versus

    for (int i = 0; i < v.size(); ++i) {
        v[i] = 1;
    }

    // Was ist, wenn der Wert nicht konstant ist

    std::generate(
        v.begin(),
        v.end(),
        fueller
    );
}

// Suchen .....
void stl_07()
{
    std::vector<int> v;

    v.resize(10);

    std::generate(
        v.begin(),
        v.end(),
        fueller
    );

    // ein Element im Vektor suchen
    std::vector<int>::iterator result = std::find(
        v.begin(),
        v.end(),
        512
    );

    if (result == v.end()) {
        std::cout << "Element NOT found: " << std::endl;
    }
    else {
        std::cout << "Element found: " << *result << std::endl;
    }
}

// int globalerWert = 512;

bool sucheWert(int aktuell) {

    std::cout << "Vergleiche Element : " << aktuell << std::endl;

    if (aktuell == 512)
        return true;
    else
        return false;
}

void stl_08()
{
    std::vector<int> v;

    v.resize(10);

    std::generate(
        v.begin(),
        v.end(),
        fueller
    );

    // ein Element im Vektor suchen, das nicht konstant ist ....
    std::vector<int>::iterator result = std::find_if(
        v.begin(),
        v.end(),
        sucheWert
    );

    if (result == v.end()) {
        std::cout << "Element NOT found!" << std::endl;
    }
    else {
        std::cout << "Element found: " << *result << std::endl;
    }
}

// ======================================================

// Ein neuer Ansatz für die Funktion 'sucheWert'

// Funktor Klasse 

class SucheWert
{
private:
    int m_zuSuchenderWert;

public:
    SucheWert () : m_zuSuchenderWert (1) {}
    SucheWert(int wert) : m_zuSuchenderWert(wert) {}

    // getter / setter
    int getWert() { return m_zuSuchenderWert; }
    void setWert( int wert ) { m_zuSuchenderWert = wert; }

    // operator ()
    bool operator() (int aktuell) {

        std::cout << "Vergleiche Element : " << aktuell << std::endl;

        if (aktuell == m_zuSuchenderWert)
            return true;
        else
            return false;
    }
};

void stl_09()
{
    SucheWert sw(512);

    bool result = sw.operator() (123);
    std::cout << "Result : " << std::boolalpha << result << std::endl;

    result = sw (512);
    std::cout << "Result : " << std::boolalpha << result << std::endl;
}

void stl_10()
{
    std::vector<int> v;

    v.resize(10);

    std::generate(
        v.begin(),
        v.end(),
        fueller
    );

    SucheWert sw(999);

    // ein Element im Vektor suchen, das nicht konstant ist ....
    std::vector<int>::iterator result = std::find_if(
        v.begin(),
        v.end(),
        sw
    );
    if (result == v.end()) {
        std::cout << "Element NOT found!" << std::endl;
    }
    else {
        std::cout << "Element found: " << *result << std::endl;
    }

    // neues Element suchen :-))))))
    sw.setWert(512);

    result = std::find_if(
        v.begin(),
        v.end(),
        sw
    );
    if (result == v.end()) {
        std::cout << "Element NOT found!" << std::endl;
    }
    else {
        std::cout << "Element found: " << *result << std::endl;
    }
}


int aufsteigend() {

    static int wert = 0;

    std::cout << "bin in aufsteigend: " << std::endl;

    ++wert;

    return wert;
}


bool binIchGerade(int aktuell) {

    std::cout << "binIchGerade: " << aktuell << std::endl;

    if (aktuell % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void stl_11()
{
    std::vector<int> numbers;
    numbers.resize(10);

    std::generate(
        numbers.begin(),
        numbers.end(),
        aufsteigend
    );

    std::vector<int> evenNumbers;
    evenNumbers.resize(10);

    // Kopieren: alle geraden Wert aus v
    // VORSICHT: copy_if wendet [] auf das Zielobjekt an !!!
    std::copy_if(
        numbers.begin(),
        numbers.end(),
        evenNumbers.begin(),
        binIchGerade
    );
}

void ausgabe(int value) {
    std::cout << ">: " << value << std::endl;
}

void stl_12()
{
    std::vector<int> numbers;
    numbers.resize(10);

    std::generate(
        numbers.begin(),
        numbers.end(),
        aufsteigend
    );

    std::vector<int> evenNumbers;

    // Kopieren: alle geraden Wert aus v
    // VORSICHT: copy_if wendet [] auf das Zielobjekt an !!!
    //    Dies kann man umgehen durch ein Proxy-Objekt:  std::back_inserter
    //    Dieses wendet einen Aufruf von push_back auf das Zielobjekt an !!!
    std::copy_if(
        numbers.begin(),
        numbers.end(),
        std::back_inserter (evenNumbers),
        binIchGerade
    );

    std::for_each(
        evenNumbers.begin(),
        evenNumbers.end(),
        ausgabe
    );
}


int summiereAuf(int letzterWert, int naechstesElementAusContainer)
{
    int summe;

    summe = letzterWert + naechstesElementAusContainer;

    return summe;
}

void stl_13()
{
    std::vector<int> numbers;

    numbers.resize(10);

    std::generate(
        numbers.begin(),
        numbers.end(),
        aufsteigend
    );

    // berechne die Summe aller Werte in einem Vektor

    int start = 0;

    int result = std::accumulate(
        numbers.begin(),
        numbers.end(),
        start,
        summiereAuf
    );

    std::cout << "Summe aller Werte: " << result << std::endl;
}

