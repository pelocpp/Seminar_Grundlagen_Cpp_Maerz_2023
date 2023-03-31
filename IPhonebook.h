#pragma once

#include <iostream>
#include <string>

class IPhonebook
{
    virtual bool insert(const std::string& first, const std::string& last, long number) = 0;

    //virtual bool search(const std::string& first, const std::string& last, long& number) = 0;

    //virtual bool remove(const std::string& first, const std::string& last) = 0;

    virtual void print () = 0;
};
