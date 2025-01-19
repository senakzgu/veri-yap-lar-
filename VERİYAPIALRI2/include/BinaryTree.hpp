/**
* @BinaryTree.hpp Dosya adı
* @description Ağaç yapısını oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "Node.hpp"

class BinaryTree
{


    private:
    Node* root; //ağacın kök düğümü

    void insertNode(Node*& node, char value);  // düğüm ekleme fonksiyonu
    int calculateTotalRecursive(Node* node, bool isLeftChild)const ;  // toplam hesaplama fonksiyonu
    void mirrorRecursive(Node* node);  // aynalama fonksiyonu
    int calculateHeight(Node* node); // yükseklik hesaplama fonksiyonu
    void fillLevels(Node* node, char levels[10][255], int depth, int left, int right); // seviyeleri doldurma fonksiyonu
    
    
    
    public:
    BinaryTree();  // Yapıcı fonksiyon
    ~BinaryTree();  // Yıkıcı fonksiyon

    
    void insert(char value);  // Ağaca düğüm ekler
    int calculateTotal() const;  // Ağacın toplam değerini hesaplar
    void mirror();  // Ağacı aynalar
    void visualize();  // Ağacı görselleştirir

    
};



#endif