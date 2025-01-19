#ifndef DNA_HPP
#define DNA_HPP

#include "kromozom.hpp"
#include <iostream>
using namespace std;

class DNA {
    private:
        Kromozom* head;    // İlk kromozom
        Kromozom* tail;    // Son kromozom
        int length;        // DNA uzunluğu

    public:
        DNA();             // Yapıcı fonksiyon
        ~DNA();            // Yıkıcı fonksiyon
        void kromozomEkle(Kromozom* kromozom); // Kromozom ekleme fonksiyonu
        void uzunlukTutma(); // DNA uzunluğunu hesaplama
        void ekranaYazdirma(); // Ekrana yazdırma fonksiyonu
        int getLength();    // DNA uzunluğunu döndürme fonksiyonu
        Kromozom* getHead(); // Başlangıç kromozomunu döndürme fonksiyonu
        Kromozom* getTail(); // Son kromozomunu döndürme fonksiyonu
        void dosyaOku(const string& dosyaAdi);  // Dosya okuma fonksiyonu
        void mutasyon(int kromozomSatirNo, int genSutunNo);
        void caprazlama(int kromozomSatirNo1, int kromozomSatirNo2) ;
        void otomatikIslemler(const string& dosyaAdi);
};

#endif


