#include <iostream>
#include <string>
#include <algorithm>

#include "Phonebook.h"


void ausgabe(const std::string& name) {
    std::cout << "Name: " << name << std::endl;
}

void main_phonebook()
{
    Phonebook book;

    book.insert("Hubert", "Mueller", 123456);
    book.insert("Anton", "Huber", 354534);
    book.insert("Sepp", "Meier", 8723223);
    book.insert("Wolfang", "Wagner", 8723223);

    // Range-Based for Loop
    for (std::pair<std::string, long> elem : book) {

        std::string key = elem.first;

        std::string first;
        std::string last;

        Phonebook::keyToNames(key, first, last);

        std::cout << first << "  " << last << ": " << elem.second << std::endl;
    }
}


void main_phonebook_zum_zweiten()
{
    Phonebook book;

    book.insert("Hubert", "Mueller", 123456);
    book.insert("Anton", "Huber", 354534);
    book.insert("Sepp", "Meier", 8723223);

    std::cout << book << std::endl;
}


void main_phonebook_zum_ersten()
{
    Phonebook book;

    book.insert("Hubert", "Mueller", 123456);
    book.insert("Anton", "Huber", 354534);
    book.insert("Sepp", "Meier", 8723223);

    book.print();

    long phoneNumber = 0;

    bool found = book.search("Anton", "Huber", phoneNumber);

    if (found) {

        std::cout << "Anton Huber hat die Tel.Nr. " << phoneNumber << std::endl;
    }

    book.remove("Sepp", "Meier");

    book.print();

    // ====================================
    // Erstelle Liste mit allen Namen aus dem Tel.Buch:

    std::forward_list<std::string> names = book.getNames();

    std::for_each(
        names.begin(),
        names.end(),
        ausgabe
    );
}
