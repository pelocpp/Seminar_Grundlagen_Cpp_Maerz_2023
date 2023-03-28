#include <iostream>
#include <exception>

#include "Time.h"

int langeBerechnung()
{
    return 123;
}

void unterprogramm()
{
    Time unknown;    // Default-Constructor

    //try
    //{

        int stunden = langeBerechnung();

        unknown.setHour(stunden);
    //}
    //catch (std::exception ex)
    //{
    //    std::cout << "Ein Fehler ist aufgetreten: " << ex.what() << std::endl;

    //    unknown.setHour(1);
    //}

    std::cout << unknown << std::endl;
}

void zweitesUnterprogramm()
{
    try
    {
        unterprogramm();
    }
    catch (std::exception ex)
    {
        std::cout << "Ein Fehler ist aufgetreten: " << ex.what() << std::endl;
        // Logging !!! falscher wert berechnet !!!
    }
}


// C++ 20: Mit Attribut
[[ nodiscard ]] bool langeBerechnung(int& result)
{
    // berechnung ....

    if (true) {

        result = 12;  // 12 soll für einen korrekten Wert stehen
        return true;
    }
    else {
        result = 0;   // Wert zurücksetzen
        // Logging !!! falscher wert berechnet !!!
        return false;
    }
}

void aufrufVonlangeBerechnung()
{
    int n = 1;

    bool succeeded = langeBerechnung(n);

    if (succeeded == true) {
        // alles passt
    }
    else {
        // habe einen Fehler entdeckt: Wie geht es weiter ?????
        // Logging !!! falscher wert berechnet !!!  Besser
    }
}

void aufrufVonlangeBerechnungZumZweiten()
{
    int n = 1;

    // langeBerechnung(n);
}

int main_ausnahmen()
{
    zweitesUnterprogramm();

    return 1;
}


