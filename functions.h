//
// Created by azram on 15.03.2024.
//

#ifndef PROJE3DENEME_FUNCTIONS_H
#define PROJE3DENEME_FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "gemi.h"
#include <memory>
#include "hizliGemi.h"
#include "normalGemi.h"
#include "gucluGemi.h"
#include "gemiSecimi.h"
#include <chrono>
#include <thread>
#define EVENTCOUNTER 5


inline void bekle(int saniye) {
    std::this_thread::sleep_for(std::chrono::seconds(saniye));
}

inline void bitir(std::shared_ptr<Gemi> gemi){
    if(gemi->yakit<=0 || gemi->saglik<=0){
        std::cout<<"Geminiz mahvoldu!! Oyunu kaybettiniz.\n";
        float puan{0};
        puan = (gemi->yakit)*5 + (gemi->saglik)*10 + (gemi->para)*10;
        std::cout<<"Puaniniz: "<<puan<<"\n";
        exit(0);
    }
}


inline void savas(std::shared_ptr<Gemi> gemi){
    int sans = rand() % 2;
    if (sans == 0) {
        int hasar{30};
        gemi->hasarAl(hasar, gemi->saglik);
        std::cout<<"Savasi kaybettiniz. Hasar aldiniz.\n";
    }
    else{
        std::cout<<"Tebrikler! Savasi kazandiniz.\n";
    }
}


inline void pazarlik(std::shared_ptr<Gemi> gemi){
    int random = rand() % 3;
    if(random==0){
        gemi->paraAyarla(-10,gemi->para);
    }
    else if(random==1){
        gemi->paraAyarla(-20,gemi->para);
    }
    else{
        gemi->paraAyarla(-30,gemi->para);
    }
}

inline void asteroidKusagi( std::shared_ptr<Gemi> gemi) {
    std::cout<<"Asteroid kusagina girdiniz!! Kusaktan 3 kere gececeksiniz ve hasar alabilirsiniz!\n";
    bekle(3);
    for(int i{1}; i<=3; ++i){
        int random = rand() % 2;
        int hasar{10};
        int toplamHasar{0};
        if(random==0){
            std::cout<<i<<". gecis\n";
            bekle(2);
            std::cout<<"Sansiniz yaver gitmedi :( Hasar aldiniz.\n";
            toplamHasar+=hasar;
            gemi->hasarAl(toplamHasar,gemi->saglik);
        }
        else{
            std::cout<<i<<". gecis\n";
            bekle(2);
            std::cout<<"Ucuz kurtuldunuz! Hasar alinmadi.\n";
        }
    }
    std::cout<<"\nSaglik: "<<gemi->saglik<<"\nYakit: "<<gemi->yakit<<"\nPara: "<<gemi->para<<"\n";
}

inline void uzayKorsanlari(std::shared_ptr<Gemi> gemi) {
    std::cout << "Uzay korsanlariyla karsilastiniz! Hemen bir karar verin.\n";
    std::cout << "Secenekleriniz: \n1-Kac\n2-Savas\n3-Pazarlik Et\n";
    int secim{0};
    int gerekliYakit{33};
    int gerekliPara{30};
    std::cin >> secim;
    if(secim==1 && gemi->yakit < gerekliYakit){
        bekle(2);
        std::cout<<"Kacmak icin yeterli yakitiniz yok!! Tekrar secim yapmalisiniz. \n2-Savas \n3-Pazarlik Et\n";
        std::cin>> secim;
    }
    if(secim==3 && gemi->para < gerekliPara){
        bekle(2);
        std::cout<<"Pazarlik etmek icin yeterli paraniz yok!! Tekrar secim yapmalisiniz. \n1-Kac \n2-Savas\n";
        std::cin>> secim;
    }
    switch (secim) {
        case 1:
            bekle(2);
            gemi->kacmaOlasiligi(gemi->yakit);
            asteroidKusagi(gemi);
            break;
        case 2:
            bekle(2);
            savas(gemi);
            break;
        case 3:
            bekle(2);
            pazarlik(gemi);
            break;
        default:
            std::cout << "Gecersiz secenek.\n";
            break;
    }
    std::cout<<"\nSaglik: "<<gemi->saglik<<"\nYakit: "<<gemi->yakit<<"\nPara: "<<gemi->para<<"\n";
}

inline bool terkedilmisGezegen(std::shared_ptr<Gemi> gemi) {
    std::cout<<"Terk edilmis gezegene girdiniz! Dikkat edin, burada altin kazanabilir ya da Uzay Korsanlari'yla karsilasabilirsiniz.\n";
    bekle(3);
    int random = rand() % 2;
    if (random == 0) {
        gemi->paraAyarla(10,gemi->para);
        std::cout << "Sanslisiniz! Altin kazandiniz!\n";
        std::cout<<"\nSaglik: "<<gemi->saglik<<"\nYakit: "<<gemi->yakit<<"\nPara: "<<gemi->para<<"\n";
        return true;
    } else {
        std::cout << "Uzay korsanlari cikti!\n";
        uzayKorsanlari(gemi);
        return false;
    }
}


inline void eventSecici(std::shared_ptr<Gemi> gemi) {
    for (int i{0}; i < EVENTCOUNTER; ++i) {
        int random = rand() % 3;
        switch (random) {
            case 0:
                bekle(2);
                asteroidKusagi(gemi);
                bitir(gemi);
                break;
            case 1:
                bekle(2);
                if (!terkedilmisGezegen(gemi)) {
                    uzayKorsanlari(gemi);
                    bitir(gemi);
                }
                break;
            case 2:
                bekle(2);
                uzayKorsanlari(gemi);
                bitir(gemi);
                break;
        }
        std::cout<<"\nOlayi atlattiniz!\n\n";
        bekle(3);
    }
    std::cout<<"Karsina cikan 5 olaydan da sag salim kurtuldun kaptan! Oyun sona erdi.\n";
    float puan{0};
    puan = (gemi->yakit)*5 + (gemi->saglik)*10 + (gemi->para)*10;
    std::cout<<"Puan: "<<puan<<"\n";
    exit(0);

}

#endif //PROJE3DENEME_FUNCTIONS_H
