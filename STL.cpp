#include <iostream>
#include <vector>

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