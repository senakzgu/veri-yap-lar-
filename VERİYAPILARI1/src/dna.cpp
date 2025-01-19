#include "dna.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Yapıcı fonksiyon
DNA::DNA() : head(nullptr), tail(nullptr), length(0) {}

// Yıkıcı fonksiyon
DNA::~DNA() {
    Kromozom* current = head;
    while (current != nullptr) {
        Kromozom* temp = current;
        current = current->getNextk(); // Kromozomlar arası geçiş
        delete temp;  // Kromozomu sil
    }
}

// Kromozom ekleme fonksiyonu
void DNA::kromozomEkle(Kromozom* kromozom) {
    if (head == nullptr) {
        head = kromozom;  // İlk kromozom
        tail = kromozom;  // İlk kromozom aynı zamanda son kromozom
    } else {
        tail->setNextk(kromozom);  // Sonraki kromozom
        kromozom->setPrewk(tail);  // Önceki kromozom
        tail = kromozom;  // Yeni son kromozom
    }
    uzunlukTutma();  // DNA uzunluğunu güncelle
}

// Uzunluk tutma fonksiyonu
void DNA::uzunlukTutma() {
    length = 0;
    Kromozom* current = head;
    while (current != nullptr) {
        length++;
        current = current->getNextk();
    }
}

// Ekrana yazdırma fonksiyonu
void DNA::ekranaYazdirma() {
    Kromozom* current = head;
    while (current != nullptr) {
        current->ekranaYazdirma(); // Her kromozomun yazdırılması
        current = current->getNextk();
    }
    cout << " ";
}

// DNA uzunluğunu döndüren fonksiyon
int DNA::getLength() {
    return length;
}

// Başlangıç kromozomunu döndüren fonksiyon
Kromozom* DNA::getHead() {
    return head;
}

// Son kromozomunu döndüren fonksiyon
Kromozom* DNA::getTail() {
    return tail;
}

void DNA::dosyaOku(const string& dosyaAdi)
{
     ifstream dosya(dosyaAdi); // Dosya açma
    if (!dosya.is_open()) { // Dosya açılamazsa hata ver
        cout << "Dosya acilamadi!" << endl;
        return;
    }
    string satir;
    while (getline(dosya, satir)) { // Dosyanın her satırını oku
        Kromozom* yeniKromozom = new Kromozom(); // Yeni bir kromozom oluştur

        stringstream ss(satir);  // Satırı bir stringstream ile işle
        string harf;

        while (ss >> harf) {  // Satırdaki her boşlukla ayrılmış kelimeyi (harfi) oku
            yeniKromozom->genEkle(harf);  // Harfi gen olarak ekle
        }

        kromozomEkle(yeniKromozom); // Yeni kromozomu DNA'ya ekle
    }
    dosya.close(); // Dosyayı kapat

}
void DNA::mutasyon(int kromozomSatirNo, int genSutunNo) {
    if (kromozomSatirNo < 0 || kromozomSatirNo > length) {
        cout << "Geçersiz satır numarası!" << endl;
        return;
    }

    Kromozom* currentKromozom = head;

    // Kromozom satır numarasına git
    for (int i = 0; i < kromozomSatirNo; i++) {
        currentKromozom = currentKromozom->getNextk();
    }

    Gen* currentGen = currentKromozom->getHead();

    // Gen sütun numarasına git
    for (int j = 0; j < genSutunNo; j++) {
        if (currentGen == nullptr) {
            cout << "Geçersiz sütun numarası!" << endl;
            return;
        }
        currentGen = currentGen->getNextg();
    }

    // Mutasyonu gerçekleştir
    if (currentGen != nullptr) {
        currentGen->setValue("X");  // Burada X ile mutasyonu yapıyoruz
        cout << "Mutasyon başarıyla gerçekleşti!" << endl;

        // Dosyayı baştan yazalım
        std::ofstream dosyaYazma("dna.txt", std::ofstream::trunc);  // Dosyayı sıfırlayarak açıyoruz
        if (!dosyaYazma.is_open()) {
            cout << "Dosyaya yazılamadı!" << endl;
            return;
        }

        // Kromozomlar üzerinde gezinip, her birini dosyaya yazıyoruz
        Kromozom* currentKromozom = head;
        while (currentKromozom != nullptr) {
            Gen* currentGen = currentKromozom->getHead();
            while (currentGen != nullptr) {
                dosyaYazma << currentGen->getValue() << " ";  // Gen değerini yazıyoruz
                currentGen = currentGen->getNextg();  // Sonraki gene geçiyoruz
            }
            dosyaYazma << std::endl;  // Her kromozomun sonuna yeni satır ekliyoruz
            currentKromozom = currentKromozom->getNextk();  // Sonraki kromozoma geçiyoruz
        }

        dosyaYazma.close();  // Dosyayı kapatıyoruz
    } else {
        cout << "Geçersiz gen sütun numarası!" << endl;
    }
}

void DNA::caprazlama(int kromozomSatirNo1, int kromozomSatirNo2) {
    if (kromozomSatirNo1 < 0 || kromozomSatirNo2 < 0 || kromozomSatirNo1 >= length || kromozomSatirNo2 >= length) {
        cout << "Geçersiz kromozom satır numarası!" << endl;
        return;
    }

    Kromozom* kromozom1 = head;
    Kromozom* kromozom2 = head;

    // İlk kromozomu belirtilen satır numarasına göre bul
    for (int i = 0; i < kromozomSatirNo1; i++) {
        kromozom1 = kromozom1->getNextk();
    }

    // İkinci kromozomu belirtilen satır numarasına göre bul
    for (int i = 0; i < kromozomSatirNo2; i++) {
        kromozom2 = kromozom2->getNextk();
    }

    kromozom1->uzunlukTutma();  // Kromozom1'deki gen sayısını al
    kromozom2->uzunlukTutma();  // Kromozom2'deki gen sayısını al

    int uzunluk1 = kromozom1->getLength();
    int uzunluk2 = kromozom2->getLength();

    // Ortadaki noktayı hesapla (gen sayısı tekse, ortadaki gen hariç olacak)
    int ortaNokta1 = (uzunluk1 % 2 == 0) ? uzunluk1 / 2 : uzunluk1 / 2 + 1;
    int ortaNokta2 = (uzunluk2 % 2 == 0) ? uzunluk2 / 2 : uzunluk2 / 2 + 1;

    // Kromozomların genleri üzerinde çaprazlama yap
    Gen* gen1 = kromozom1->getHead();
    Gen* gen2 = kromozom2->getHead();

    // İlk kromozomun ilk yarısı ile ikinci kromozomun ikinci yarısını birleştir
    Kromozom* yeniKromozom1 = new Kromozom();
    for (int i = 0; i < ortaNokta1; i++) {
        yeniKromozom1->genEkle(gen1->getValue());  // İlk kromozomdan
        gen1 = gen1->getNextg();
    }
    for (int i = ortaNokta2; i < uzunluk2; i++) {
        yeniKromozom1->genEkle(gen2->getValue());  // İkinci kromozomdan
        gen2 = gen2->getNextg();
    }

    // İkinci kromozomun ilk yarısı ile birinci kromozomun ikinci yarısını birleştir
    Kromozom* yeniKromozom2 = new Kromozom();
    gen1 = kromozom1->getHead();
    gen2 = kromozom2->getHead();
    for (int i = 0; i < ortaNokta2; i++) {
        yeniKromozom2->genEkle(gen2->getValue());  // İkinci kromozomdan
        gen2 = gen2->getNextg();
    }
    for (int i = ortaNokta1; i < uzunluk1; i++) {
        yeniKromozom2->genEkle(gen1->getValue());  // Birinci kromozomdan
        gen1 = gen1->getNextg();
    }

    // Yeni kromozomları popülasyona ekle
    this->kromozomEkle(yeniKromozom1);
    this->kromozomEkle(yeniKromozom2);

    // Yeni kromozomları dosyaya ekle
    ofstream dosya("dna.txt", ios::app);  // Dosyaya ekleme modu
    if (dosya.is_open()) {
         
        // Yeni kromozomları dosyaya yazdıralım
        Gen* gen = yeniKromozom1->getHead();
        while (gen != nullptr) {
            dosya << gen->getValue() << " ";  // Gen değerini yaz
            gen = gen->getNextg();
        }
        dosya << endl;  // Yeni bir satıra geçelim

        gen = yeniKromozom2->getHead();
        while (gen != nullptr) {
            dosya << gen->getValue() << " ";  // Gen değerini yaz
            gen = gen->getNextg();
        }
        dosya.close();
    } else {
        cout << "Dosya açılamadı!" << endl;
    }

    cout << "Çaprazlama başarıyla tamamlandı!" << endl;
}

void DNA::otomatikIslemler(const std::string& dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        std::cout << "islemler.txt dosyası açılamadı!" << std::endl;
        return;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        std::istringstream iss(satir);
        char komut;
        int param1, param2;

        iss >> komut >> param1 >> param2;

        if (komut == 'C') {
            // Çaprazlama işlemi
            std::cout << param1 << ". ve " << param2 << ". kromozomlar çaprazlanıyor..." << std::endl;
            this->caprazlama(param1, param2);
        } else if (komut == 'M') {
            // Mutasyon işlemi
            std::cout << param1 << ". kromozomun " << param2 << ". genine mutasyon uygulanıyor..." << std::endl;
            this->mutasyon(param1, param2);
        } else {
            std::cout << "Geçersiz komut: " << komut << std::endl;
        }
    }

    dosya.close();
    std::cout << "Otomatik işlemler tamamlandı." << std::endl;
}