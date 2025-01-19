
/**
* @TreeNode.hpp Dosya adı
* @description Ağacın düğümlerini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "BinaryTree.hpp"



class TreeNode 
{
    private:
    
        BinaryTree* tree;   // Bağlı listedeki ağaç
        TreeNode* next; // Sonraki düğümü işaret eden pointer

    public:

        TreeNode(BinaryTree *tree);
        ~TreeNode();


        BinaryTree* getTree() const;
        void setTree(BinaryTree *tree);
        TreeNode* getNext() const;
        void setNext(TreeNode* next);


};








#endif