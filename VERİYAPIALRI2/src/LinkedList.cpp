/**
* @LinkedList.cpp Dosya adı
* @description Ağaçların bağlı listesini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>


LinkedList::LinkedList()    // Yapıcı fonksiyon      
{
    head = nullptr;
    current = nullptr;
}


LinkedList::~LinkedList() // Yıkıcı fonksiyon
{
    TreeNode *temp;
    while(head != nullptr)
    {
        temp = head;
        head = head->getNext();
        delete temp;

    }
}


void LinkedList::append(BinaryTree *tree) //listeye ağaç ekler
{
    TreeNode *newNode = new TreeNode(tree);
    if(head == nullptr)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        TreeNode *temp = head;
        while(temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    
}


int LinkedList::getCurrentIndex() const 
{ // Geçerli düğümün indeksini almak için
    int index = 0;
    TreeNode* temp = head;

    while (temp != nullptr) {
        if (temp == current) {
            return index;  // Seçili düğümün indeksini döndür
        }
        temp = temp->getNext();
        ++index;
    }

    return -1;  // Eğer current bulunamazsa -1 döndür
}





BinaryTree* LinkedList::getCurrentTree() //mevcut düğümü döndürür
{
    if(current == nullptr) return nullptr;

    return current->getTree();

}



   


void LinkedList::moveLeft() 
{ // Seçili düğümü sola hareket ettirir
    if (current == nullptr || current == head) {
        cout << "This first element cannot move in any way." << endl;
        return;
    }
    
    // Bağlı listedeki önceki düğüme gitmek için
    TreeNode* temp = head;
    while (temp->getNext() != current) {
        temp = temp->getNext();
    }

    current = temp;  // current'ı sola kaydır
    cout << "Switched to the node on the left." << endl;
}


void LinkedList::moveRight() 
{ // Seçili düğümü sağa hareket ettirir
    if (current == nullptr || current->getNext() == nullptr) {
        cout << "This last element cannot be moved to the right." << endl;
        return;
    }

    current = current->getNext();  // current'ı sağa kaydır
    cout << "Switched to the node on the right." << endl;
}


void LinkedList::deleteCurrentTree() 
{ // Seçili ağacı siler
    if (current == nullptr) {
        cout << "You have no trees to delete." << endl;
        return;
    }

    // Eğer current başta ise, head'i güncelle
    if (current == head) {
        TreeNode* temp = head;
        head = head->getNext();  // Yeni başı göster
        current = head;  // current'ı yeni başa ayarla
        delete temp;
    } else {
        // current düğümünün bir önceki düğümünü bul
        TreeNode* prev = head;
        while (prev != nullptr && prev->getNext() != current) {
            prev = prev->getNext();
        }

        // Eğer önceki düğüm mevcutsa, bağlantıyı kes
        if (prev != nullptr) {
            prev->setNext(current->getNext());  // Önceki düğüm, current'un bir sonrasına işaret eder
            delete current;
            current = prev->getNext();  // current'ı bir sonraki düğüme ayarla
        }
    }

    // Eğer current nullptr olduysa, listede daha fazla düğüm yoktur
    if (current == nullptr) {
        cout << "All nodes deleted." << endl;
    } else {
        cout << "Selected tree deleted." << endl;
    }
}



void LinkedList::mirrorCurrentTree() 
{ // Seçili ağacı aynalar
    if (current == nullptr) {
        cout << "The tree was not found." << endl;
        return;
    }

    current->getTree()->mirror();  // Seçili ağacı aynalar
    cout << "Selected tree mirrored." << endl;
}


void LinkedList::loadTreesFromFile(const string& filename) 
{ // Dosyadan ağacın yüklenmesi
    ifstream file(filename);
    string line;
    
    if (!file.is_open()) {
        cout << "An error occurred while opening the file." << endl;
        return;
    }
    
    while (getline(file, line)) {
        BinaryTree* tree = new BinaryTree();
        for (int i = 0; i < line.length(); i++) 
        {
            char c = line[i];
            tree->insert(c);  // Satırdaki her karakteri ağaçta ekliyoruz
        }

        append(tree);  // Ağaçları listeye ekliyoruz
    }
    
    file.close();  // Dosyayı kapatıyoruz
}


void LinkedList::displayTrees(int page) 
{ // İlk 10 elemanı yazdırır
    if (head == nullptr) {
        cout << "The linked list is empty." << endl;
        return;
    }

    int start = (page - 1) * 10; // Sayfa başlangıcı
    int end = start + 10;       // Sayfa sonu

    // Seçili düğümün indeksini bul
    int currentIndex = 0;
    TreeNode* temp = head;
    while (temp != nullptr && temp != current) {
        temp = temp->getNext();
        ++currentIndex;
    }

    // Eğer seçili düğüm mevcut sayfanın dışında ise, sayfayı ayarla
    if (currentIndex < start || currentIndex >= end) {
        page = (currentIndex / 10) + 1;
        start = (page - 1) * 10;
        end = start + 10;
    }

    // Sayfa başlangıcından itibaren yazdırılacak düğümleri ayarla
    temp = head;
    for (int i = 0; i < start && temp != nullptr; ++i) {
        temp = temp->getNext();
    }

    // Tabloyu yazdırmak için gerekli dizileri hazırla
    string nodeAddresses[10];
    string treecalculate[10];
    string nextAddresses[10];
    bool isSelected[10] = {false};

    int index = 0;
    while (temp != nullptr && index < 10) {
        nodeAddresses[index] = to_string((uintptr_t)temp);          // Düğüm adresi
        treecalculate[index] = to_string(temp->getTree()->calculateTotal()); 
        nextAddresses[index] = temp->getNext() 
                               ? to_string((uintptr_t)temp->getNext()) 
                               : "NULL"; // Sonraki adres
        if ((start + index) == currentIndex) {
            isSelected[index] = true; // Seçili düğüm işareti
        }
        temp = temp->getNext();
        ++index;
    }

    // Tabloyu yazdır
    cout << "Page: " << page << endl;

    // Düğüm adreslerini yazdır
    for (int i = 0; i < index; ++i) {
        cout << setw(19) << nodeAddresses[i] <<"|";
    }
    cout << endl;

    // Kendi adreslerini yazdır
    for (int i = 0; i < index; ++i) {
        cout << setw(19) << treecalculate[i] <<"|";
    }
    cout << endl;

    // Sonraki adresleri yazdır
    for (int i = 0; i < index; ++i) {
        cout << setw(19) << nextAddresses[i] <<"|" ;
    }
    cout << endl;

    // Seçili ifadelerini yazdır
    
    for (int i = 0; i < index; ++i) {
        if (isSelected[i]) {
            cout << setw(20) << "   ^^^^^^^^^^^";
        } else {
            cout << setw(20) << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < index; ++i) {
        if (isSelected[i]) {
            cout << setw(20) << "    |||||||||||" << endl;
        } else {
            cout << setw(20) << " ";
        }
    }
    cout << endl;
}
