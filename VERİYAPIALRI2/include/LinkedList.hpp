/**
* @LinkedList.hpp Dosya adı
* @description Ağaçların bağlı listesini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#ifndef LİNKEDLİST_HPP
#define LİNKEDLİST_HPP
#include "TreeNode.hpp"

class LinkedList
{
    private:

    TreeNode *head;
    TreeNode *current;
    int currentIndex;

    public:

    LinkedList();
    ~LinkedList();

    void append(BinaryTree *tree); //listeye ağaç ekler
    BinaryTree* getCurrentTree(); //mevcut düğümü döndürür
    void displayTrees(int page); // İlk 10 elemanı yazdırır
    void moveLeft();  // Seçili düğümü sola hareket ettirir
    void moveRight(); // Seçili düğümü sağa hareket ettirir
    void deleteCurrentTree(); // Seçili ağacı siler
    void mirrorCurrentTree(); // Seçili ağacı aynalar
    void loadTreesFromFile(const string& filename);  // Dosyadan ağacın yüklenmesi
    void setCurrentIndex(int index);  // Seçili düğümü ayarlamak için
    int getCurrentIndex() const;  // Geçerli düğümün indeksini almak için


    


};


#endif