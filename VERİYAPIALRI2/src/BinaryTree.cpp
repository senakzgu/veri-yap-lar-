/**
* @BinaryTree.cpp Dosya adı
* @description Ağaç yapısını oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#include "BinaryTree.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

BinaryTree::BinaryTree()
{ // Yapıcı fonksiyon
    root = nullptr;  // Başlangıçta ağaç boş
}


BinaryTree::~BinaryTree() 
{ // Yıkıcı fonksiyon
    delete root; // Ağacı sil
}


void BinaryTree::insert(char value) 
{ // Ağaca düğüm ekleme
    insertNode(root, value);  //  düğüm ekleme işlemi
}


void BinaryTree::insertNode(Node*& node, char value)  // düğüm ekleme fonksiyonu
{
     if(node == nullptr)
    {
        node = new Node(value);  // Burada yeni bir düğüm ekleniyor
    }

    else if(value < node->getValue())
    {
         insertNode(node->getLeft(), value); // sol alta ağaç ekleme
    }
    else
    {
        insertNode(node->getRight(), value);  // Sağ alt ağaçta ekleme
    }
}

 

int BinaryTree::calculateTotal()const // toplam hesaplama fonksiyonu
{
    return calculateTotalRecursive(root,false);
}

int BinaryTree::calculateTotalRecursive(Node* node, bool isLeftChild) const
{
    if (node == nullptr)
    {
        return 0; 
    }
    else
    {
        int leftValue = calculateTotalRecursive(node->getLeft(), true);  // Sol alt ağaç
        int rightValue = calculateTotalRecursive(node->getRight(), false); // Sağ alt ağaç

        // Eğer bu düğüm sol alt ağaçtan geliyorsa, değerini 2 ile çarpıyoruz.
        int currentNodeValue = node->getValue();
        if (isLeftChild)
        {
            currentNodeValue *= 2;
        }

        // Sol ve sağ alt ağaçların hesaplanan değeri ve mevcut düğümün değeri
        return leftValue + rightValue + currentNodeValue;
    }
}




void BinaryTree::mirror() 
{ // Ağacı aynalar
    mirrorRecursive(root);
}


void BinaryTree::mirrorRecursive(Node* node) // aynalama fonksiyonu
{
    if(node != nullptr)
    {
        swap(node->getLeft(),node->getRight()); // Sol ve sağ alt ağaçları değiştir
        mirrorRecursive(node->getLeft());  // Sol alt ağaçta aynalama
        mirrorRecursive(node->getRight());  // Sağ alt ağaçta aynalama
    }
}


 

int BinaryTree::calculateHeight(Node* node) 
{ // yükseklik hesaplama fonksiyonu
    if (!node) return 0;
    return 1 + std::max(calculateHeight(node->getLeft()), calculateHeight(node->getRight())); 
}


void BinaryTree::visualize() 
{
    int height = calculateHeight(root); // Ağacın yüksekliği
    int width = std::pow(2, height) - 1; // Görselleştirme genişliği
    char levels[10][255]; // Maksimum 10 seviye, 255 genişlik

    // Tüm seviyeleri boşluk karakteriyle doldur
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 255; ++j) {
            levels[i][j] = ' ';
        }
    }

    // Ağacı seviyelere yerleştir
    fillLevels(root, levels, 0, 0, width - 1);

    // Ağacı yazdır
    for (int i = 0; i < height; ++i) {
        // Düğüm değerlerini yazdır
        for (int j = 0; j < width; ++j) {
            std::cout << levels[i][j];
        }
        std::cout << std::endl;

        // Dallar için bağlantıları çiz
        if (i < height - 1) {
            for (int j = 0; j < width; ++j) {
                if (levels[i][j] != ' ') {
                    // Sol dal
                    int left_child = j - (1 << (height - i - 2));
                    if (left_child >= 0 && levels[i + 1][left_child] != ' ') {
                        std::cout << '/';
                    } else {
                        std::cout << ' ';
                    }

                    // Sağ dal
                    int right_child = j + (1 << (height - i - 2));
                    if (right_child < width && levels[i + 1][right_child] != ' ') {
                        std::cout << '\\';
                    } else {
                        std::cout << ' ';
                    }
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
}

void BinaryTree::fillLevels(Node* node, char levels[10][255], int depth, int left, int right) { // seviyeleri doldurma fonksiyonu
    if (!node || depth >= 10) return;

    int mid = (left + right) / 2; // Ortadaki konum
    levels[depth][mid] = node->getValue(); // Düğüm değerini ekle

    fillLevels(node->getLeft(), levels, depth + 1, left, mid - 1);  // Sol alt ağaç
    fillLevels(node->getRight(), levels, depth + 1, mid + 1, right); // Sağ alt ağaç
}


