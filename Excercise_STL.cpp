#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Funktor
class Fibonacci
{
private:
    int m_first;
    int m_second;

public:
    Fibonacci() : m_first(0), m_second(1) {}

    int operator() ()
    {
        // store current Fibonacci number
        int last = m_first;

        // calculate next pair
        int tmp = m_first + m_second;
        m_first = m_second;
        m_second = tmp;

        return last;
    }

    void operator() (int elem)
    {
        std::cout << ">: " << elem << std::endl;
    }
};

void stl_exercise_fibonacci()
{
    std::vector<int> numbers(20);
    // numbers.resize(20);

    Fibonacci fibo;

    std::generate (
        numbers.begin(),
        numbers.end(),
        fibo
    );

    std::for_each (
        numbers.begin(),
        numbers.end(),
        fibo
    );
}




void printToConsole(int value) {
    std::cout << ">: " << value << std::endl;
}

void stl_exercise_teufel()
{
    std::vector<int> teufelFolge;

    int start = 23;

    teufelFolge.push_back(start);

    // Greedy - Berechnung
    while (start != 1)
    {
        start = (start % 2 == 0) ? (start / 2) : (start * 3 + 1);
        teufelFolge.push_back(start);
    }

    std::for_each(
        teufelFolge.begin(),
        teufelFolge.end(),
        printToConsole
    );
}

// ===================================================================
// Teufelfolge: More academic solution :)

class CollatzIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int*;
    using reference = int&;

private:
    int m_start;
    int m_current;
    int m_last;     // Könnte die Berechnung des ersten / letzten Wertes vereinfachen ???

public:
    // c'tors
    CollatzIterator(int start) : m_start(start), m_current(start)
    {}

    // operators
    int operator*() const {
        return m_current; 
    }

    CollatzIterator& operator++()
    {
        m_last = m_current;

        m_current = (m_current % 2 == 0)
            ? m_current = m_current / 2
            : m_current = 3 * m_current + 1;

        return *this;
    }

    bool operator!=(const CollatzIterator& iter) const
    {
        return m_last != iter.m_current;
    }
};


class CollatzSequence    //  Klasse TeuflischeFolge
{
private:
    int m_start;

public:
    // c'tor(s)
    CollatzSequence(int start) : m_start(start) {}

    // iterator support
    // Berechnung im Iterator-Objekt: LAZY
    CollatzIterator begin() const { return CollatzIterator (m_start); }
    CollatzIterator end()   const { return CollatzIterator (1); }
};





// using std::for_each
void stl_exercise_teufel_academic_01()
{
    CollatzSequence seq(7);

    // Lazy - Berechnung !!!
    std::for_each(
        seq.begin(),
        seq.end(),
        printToConsole
    );
    std::cout << std::endl;
}


// using std::copy
void stl_exercise_teufel_academic_02()
{
    CollatzSequence seq(7);

    std::vector<int> numbers;   // leer

    // Greedy
    std::copy(
        //std::begin(seq), 
        //std::end(seq), 
        seq.begin(),
        seq.end(),
        std::back_inserter(numbers)    // [] -> push_back
    );

    //std::for_each(
    //    numbers.begin(),
    //    numbers.end(),
    //    printToConsole
    //);

    // ODER "for_each" / Range-Based for-Loop

    for (int value : numbers) {
        std::cout << ">: " << value << std::endl;
    }

    std::cout << std::endl;
}

// using range-based for-loop
void stl_exercise_teufel_academic_03()
{
    CollatzSequence seq(7);

    // Range-Based for-loop auch für User-Defined Container:
    //     Standard-Operatoren-Konzept

    for (int number : seq) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}