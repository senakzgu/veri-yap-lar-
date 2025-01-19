/**
* @Node.hpp Dosya adı
* @description Ağaçları tutan bağıl listin düğümlerini oluşturan sınıf
* @course 2A
* @assignment 2. ödev
* @date 20.10.2024

*/
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;


class Node
{
    private:

        char value;
        Node *left;
        Node *right;

    public:

        Node(char value); 
        ~Node(); 


        void setValue(char value);  
        char getValue();     
        Node*& getLeft();      
        Node*& getRight();    
        void setLeft(Node* left);   
        void setRight(Node* right); 


};


#endif