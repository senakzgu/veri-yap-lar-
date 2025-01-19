#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "gen.hpp"
using namespace std;

class Kromozom {
    private:
        Gen* head;     // İlk gen
        Gen* lastGen;  // Son gen (eklentilerde hızlı erişim için)
        int length;    // Kromozom uzunluğu
        Kromozom* prewk;  // Önceki kromozom
        Kromozom* nextk;  // Sonraki kromozom

    public:
        Kromozom();     // Yapıcı fonksiyon
        ~Kromozom();    // Yıkıcı fonksiyon

        void uzunlukTutma();  // Uzunluk tutma fonksiyonu
        void ekranaYazdirma(); // Ekrana yazdırma fonksiyonu
        void genEkle(const string& value); // Gen ekleme fonksiyonu
        int getLength();      // Kromozom uzunluğunu döndürme fonksiyonu
        Gen* getHead();       // İlk geni döndürme fonksiyonu
        Gen* getLastGen();    // Son geni döndürme fonksiyonu
        void setLastGen(Gen* lastGen); // Son geni ayarlama fonksiyonu
        Kromozom* getPrewk();  // Önceki kromozomu döndürme fonksiyonu
        Kromozom* getNextk();  // Sonraki kromozomu döndürme fonksiyonu
        void setPrewk(Kromozom* prewk);
        void setNextk(Kromozom* nextk);
        


};

#endif
