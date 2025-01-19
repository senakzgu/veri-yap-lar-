/**
* @G231210385 Dosya adı
* @description Ağacın düğümlerini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/
#include "TreeNode.hpp" 

TreeNode::TreeNode(BinaryTree* tree)
{
    this->tree = tree;
    this->next = nullptr;
}


TreeNode::~TreeNode()
{
    delete this->tree;
}
 

BinaryTree* TreeNode::getTree() const
{
    return this->tree;
}


void TreeNode::setTree(BinaryTree* tree)
{
    this->tree = tree;
}


TreeNode* TreeNode::getNext() const
{
    return this->next;
}


void TreeNode::setNext(TreeNode* next)
{
    this->next = next;
}