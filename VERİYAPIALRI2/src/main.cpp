/**
* @main.cpp Dosya adı
* @description Ağaçları görselleştiren program
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

void displayMenu() {
    cout << "\n------------------- Menu -------------------" << endl;
    cout << "Move Left (a key)" << endl;
    cout << "Move Right (d key)" << endl;
    cout << "Delete Tree (s key)" << endl;
    cout << "Mirror Tree (w key)" << endl;
    cout << "Exit (x)" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Make your choice: ";
}

int main() {
    LinkedList list;
    list.loadTreesFromFile("agaclar.txt");  // Dosyadaki ağaçları yüklüyoruz

    int page = 1;  // Başlangıçta ilk sayfayı gösteriyoruz

    char choice;

    while (true) {
        list.displayTrees(page);  // Geçerli sayfayı göster

        cout << "\nSelected Tree Structure:" << endl << endl;
        BinaryTree* currentTree = list.getCurrentTree();  // Seçili ağacı al
        
        if (currentTree) {
            currentTree->visualize();  // Ağacı görselleştir
        } else {
            cout << "No trees selected!" << endl;
        }
       

        displayMenu();  // Menü gösteriliyor
        cin >> choice;

        switch (choice) {

            case 'a':  // Sola git
                list.moveLeft();
                // Seçili düğümün olduğu sayfayı güncelle
                page = (list.getCurrentIndex() / 10) + 1;
                break;

            case 'd':  // Sağa git
                list.moveRight();
                // Seçili düğümün olduğu sayfayı güncelle
                page = (list.getCurrentIndex() / 10) + 1;
                break;

            case 's':  // Ağaç sil
                list.deleteCurrentTree();
                // Sayfayı güncelle
                page = (list.getCurrentIndex() / 10) + 1;
                break;

            case 'w':  // Ağaç aynala
                list.mirrorCurrentTree();
                break;

            case 'x':  // Çıkış
                cout << "Exit is being made..." << endl;
                return 0;

            default:
                cout << "Invalid selection, try again!" << endl;
                break;
        }
    }

    return 0;
}
