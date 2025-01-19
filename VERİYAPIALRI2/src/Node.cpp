/**
* @G231210385 Dosya adı
* @description Ağaçları tutan bağıl listin düğümlerini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024
*/

#include "Node.hpp"

Node::Node(char value)
{
    this->value = value;
    this->right = nullptr;
    this->left = nullptr;

}

Node::~Node()
{
    delete this->left;
    delete this->right;
}

char Node::getValue() {
    return this->value;  
}

void Node::setValue(char value) {
    this->value = value;  
}

Node*& Node::getLeft() {
    return this->left;  // Sol alt düğümü döndürme
}

void Node::setLeft(Node* left) {
    this->left = left;  // Sol alt düğümü ayarlama
}
Node*& Node::getRight() {
    return this->right;  // Sağ alt düğümü döndürme
}

void Node::setRight(Node* right) {
    this->right = right;  // Sağ alt düğümü ayarlama
}


