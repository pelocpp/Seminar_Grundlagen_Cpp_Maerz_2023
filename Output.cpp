#include <iostream>

// DON'T USE "using namespace std;"
// using namespace std;

#include "Time.h"

int main_ausgabe_erste_schritte()
{
    // Time now(10, 8, 0);

    std::cout.write("Hallo\n", 6);

    // Man interpretiere '<<' als Pfeilspitze nach links :  <<=====
    std::cout << "Hallo zum Zweiten: Bitte Wert eingeben: ";

    int n;

    std::cin >> n;

    std::cout << "Wert lautet: " << n << "." << '\n' << std::endl;

    
    return 0;
}

int main_ausgabe()
{
    Time now(11, 3, 0);

   // std::cout << now;

    (std::cout << now) << '.';

    return 0;
}
