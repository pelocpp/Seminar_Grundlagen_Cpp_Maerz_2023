#include <iostream>
#include <string>
#include <algorithm>

#include <unordered_map>
#include <utility>

#include "Phonebook.h"

bool Phonebook::insert(const std::string& first, const std::string& last, long number)
{
    // gibt es den Eintrag schon ... später ...
    // To be Done

    std::string key(first + "_" + last);

    std::pair<std::string, long> entry (key, number);

    m_map.insert(entry);

    return true;
}

void printEntry(const std::pair<std::string, long>& entry)
{
    std::string key = entry.first;   // "Anton_Huber"

    size_t pos_underscore = key.find("_");

    std::string firstName = key.substr(0, pos_underscore);

    std::string lastName = key.substr(pos_underscore + 1);

    // std::cout << entry.first << " == " << entry.second << std::endl;

    std::cout 
        << "Vorname: " << firstName 
        << ", Nachname: " << lastName << ": " 
        << entry.second << std::endl;
}

void Phonebook::print()
{
    std::for_each(
        m_map.begin(),
        m_map.end(),
        printEntry
    );
}
