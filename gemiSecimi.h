//
// Created by azram on 15.03.2024.
//

#ifndef PROJE3DENEME_GEMISECIMI_H
#define PROJE3DENEME_GEMISECIMI_H

#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "gemi.h"
#include <memory>
#include "hizliGemi.h"
#include "gucluGemi.h"
#include "normalGemi.h"

std::shared_ptr<Gemi> gemiSecimi() {

    int secim;
    std::cout << "Hos geldiniz! Maceraya baslamak icin lutfen bir gemi seciniz\n"
              << " 1) Hizli Gemi\n"
              << " 2) Guclu Gemi\n"
              << " 3) Normal Gemi\n";
    std::cin >> secim;

    std::shared_ptr<Gemi> gemi;
    switch (secim) {
        case 1:
            gemi = std::make_shared<hizliGemi>();
            break;
        case 2:
            gemi = std::make_shared<gucluGemi>();
            break;
        case 3:
            gemi = std::make_shared<normalGemi>();
            break;
        default:
            std::cout << "Gecersiz secim yaptiniz!\n";
            gemiSecimi();
            break;
    }
    std::cout<<"Kemerlerini bagla kaptan!\n"<<"Secilen gemi: "<<gemi->tip<<"\nSaglik: "<<gemi->saglik<<"\nYakit: "<<gemi->yakit<<"\nPara: "<<gemi->para<<"\n\n";
    return gemi;

}
#endif //PROJE3DENEME_GEMISECIMI_H
