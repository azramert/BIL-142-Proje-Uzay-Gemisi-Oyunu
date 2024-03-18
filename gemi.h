//
// Created by azram on 15.03.2024.
//

#ifndef PROJE3DENEME_GEMI_H
#define PROJE3DENEME_GEMI_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
class Gemi {
public:
    int yakit{0};
    int saglik{0};
    int para{0};
    std::string const tip;

    Gemi(std::string gemiTipi) : tip(gemiTipi), yakit(100), saglik(100), para(0) {}


    virtual void kacmaOlasiligi(int& yakit) = 0;
    virtual void hasarAl(int hasar,int& saglik) = 0;
    virtual void paraAyarla(int ucret, int& para)= 0;
};

#endif //PROJE3DENEME_GEMI_H
