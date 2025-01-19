#include "kromozom.hpp"
#include <iostream>
using namespace std;

// Yapıcı fonksiyon
Kromozom::Kromozom() : head(nullptr), lastGen(nullptr), length(0), prewk(nullptr), nextk(nullptr) {}

// Yıkıcı fonksiyon
Kromozom::~Kromozom() {
    Gen* current = head;
    while (current != nullptr) {
        Gen* temp = current;
        current = current->getNextg();
        delete temp;  // Kromozomu sil
    }
}

// Uzunluk tutma fonksiyonu
void Kromozom::uzunlukTutma() {
    length = 0;
    Gen* current = head;
    while (current != nullptr) {
        length++;
        current = current->getNextg();
    }
}


void Kromozom::ekranaYazdirma() {
    if (head == nullptr) {  // Kromozomda hiç gen yoksa
        return;
    }

    Gen* current = lastGen;  // Kromozomun sonundan başlıyoruz
    bool printed = false;  // Yazdırma işlemi yapıldığını takip etmek için

    // Kromozomda gezinmeye başlıyoruz
    while (current != nullptr) {
        // Eğer current gen, head'teki genin değerinden küçükse
        if (current->getValue() < head->getValue()) {
            cout << current->getValue() << " ";  // Bu gen ekrana yazdırılır
            printed = true;
            break;  // Bir gen yazdırıldıktan sonra döngü sonlandırılır
        }
        current = current->getPrewg();  // Önceki gene geç
    }

    // Eğer hiçbir küçük gen bulunmazsa, head'teki gen yazdırılır
    if (!printed && head != nullptr) {  
        cout << head->getValue() << " ";
    }

    
}


void Kromozom::genEkle(const string& value) {
    Gen* newGen = new Gen(value, lastGen, nullptr);  // Yeni gen sonuna ekleniyor
    if (lastGen != nullptr) {
        lastGen->setNextg(newGen);  // Eski son genin nextg'ye yeni gen bağlanıyor
    }
    lastGen = newGen;  // Yeni son gen olarak atanıyor

    if (head == nullptr) {
        head = newGen;  // Eğer başta hiç gen yoksa, ilk gen başa da atanır
    }

    uzunlukTutma();
}

// Son genin erişimi için fonksiyon
Gen* Kromozom::getLastGen() {
    return lastGen;
}

// Son geni ayarlamak için fonksiyon
void Kromozom::setLastGen(Gen* lastGen) {
    this->lastGen = lastGen;
}

// Length getter
int Kromozom::getLength() {
    return length;
}

// Head getter
Gen* Kromozom::getHead() {
    return head;
}

// Önceki kromozomu döndürme fonksiyonu
Kromozom* Kromozom::getPrewk() {
    return prewk;
}

// Sonraki kromozomu döndürme fonksiyonu
Kromozom* Kromozom::getNextk() {
    return nextk;
}

// Kromozomun önceki kromozomunu ayarlama fonksiyonu
void Kromozom::setPrewk(Kromozom* prewk) {
    this->prewk = prewk;
}

// Kromozomun sonraki kromozomunu ayarlama fonksiyonu
void Kromozom::setNextk(Kromozom* nextk) {
    this->nextk = nextk;
}

