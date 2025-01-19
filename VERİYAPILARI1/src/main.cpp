#include <iostream>
#include "dna.hpp"

using namespace std;

int main() {
    DNA dna;

    // DNA verisini dosyadan okuma işlemi
    dna.dosyaOku("dna.txt");  // Burada "dna.txt" dosyasını okuyoruz.

    int secim;
    do {
        cout << "\nMenu:\n";
        cout << "1- Çaprazlama\n";
        cout << "2- Mutasyon\n";
        cout << "3- Otomatik İşlemler\n";
        cout << "4- Ekrana Yaz\n";
        cout << "5- Çıkış\n";
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
            case 1:{
                 // Çaprazlama işlemi
                int kromozomSatirNo1, kromozomSatirNo2;
                cout << "İlk kromozom satır numarasını girin: ";
                cin >> kromozomSatirNo1;
                cout << "İkinci kromozom satır numarasını girin: ";
                cin >> kromozomSatirNo2;

                // Çaprazlama işlemi yap
                dna.caprazlama(kromozomSatirNo1, kromozomSatirNo2);
                break;
            }
            case 2: {
                // Mutasyon işlemi
                int kromozomIndex, genIndex;
                cout << "Kromozom satır numarasını girin: ";
                cin >> kromozomIndex;
                cout << "Gen sütun numarasını girin: ";
                cin >> genIndex;

                // Mutasyonu uygula
                dna.mutasyon(kromozomIndex, genIndex);
                break;
            }

            case 3:
              cout << "Otomatik işlemler seçildi." << endl;
                dna.otomatikIslemler("islemler.txt");  // islemler.txt dosyasını okuyup işlemleri uygula
                break;

                break;

            case 4:
                // Ekrana yazdırma işlemi
                cout << "Ekrana yazdırma işlemi seçildi." << endl;
                dna.ekranaYazdirma();  // Ekrana yazdırma fonksiyonu
                break;

            case 5:
                cout << "Çıkış yapılıyor..." << endl;
                break;

            default:
                cout << "Geçersiz seçenek. Lütfen tekrar deneyin." << endl;
        }
    } while (secim != 5);

    return 0;
}
