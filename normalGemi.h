//
// Created by azram on 15.03.2024.
//

#ifndef PROJE3DENEME_NORMALGEMI_H
#define PROJE3DENEME_NORMALGEMI_H

#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "gemi.h"

class normalGemi : public Gemi {
public:
    normalGemi() : Gemi("Normal Gemi") {}

    void kacmaOlasiligi(int& yakit) override {
        int sans = rand() % 100 + 1;
        if (sans <= 50) {
            std:: cout << "Tebrikler!! Kacmayi basardiniz :)\n\n";
            yakit -= 33;
            if(yakit < 0){
                yakit = 0;
            }
        } else {
            std::cout << "Kacmayi basaramadiniz! :(\n\n";
        }
    }

    void hasarAl(int hasar,int& saglik) override {
        saglik -= hasar;
        if(saglik < 0){
            saglik = 0;
        }
    }

    void paraAyarla(int ucret, int& para) override {
        para += ucret;
    }
};


#endif //PROJE3DENEME_NORMALGEMI_H
