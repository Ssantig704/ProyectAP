// Pig.h
#pragma once
#include "Animal.h"

class Pig : public Animal {
public:
    Pig();
    ~Pig();
    void wallowInMud();
    void comer() override;
};