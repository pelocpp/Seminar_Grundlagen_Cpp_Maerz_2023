#include <iostream>
#include <string>

#include "Phonebook.h"

void main_phonebook()
{
    Phonebook book;

    book.insert("Hubert", "Mueller", 123456);
    book.insert("Anton", "Huber", 354534);
    book.insert("Sepp", "Meier", 8723223);

    book.print();
}
