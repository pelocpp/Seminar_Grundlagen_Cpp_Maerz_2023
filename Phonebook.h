#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

#include "IPhonebook.h"

class Phonebook : public IPhonebook
{
private:
    std::unordered_map<std::string, long> m_map;

public:
    bool insert (const std::string& first, const std::string& last, long number) override;
    void print() override;
};