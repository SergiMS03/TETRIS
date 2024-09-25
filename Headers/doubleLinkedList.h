#pragma once
#include <iostream>
#include <cstddef>

template<typename T>
class Node{
public:
    bool isNull = true;
    Node *prev;
    T value;
    Node *next;

    Node() :isNull(true), prev(nullptr), next(nullptr) {}
    Node(T value){
        this->value = value;
        this->isNull = false;
    };
};



template<typename T>
class List{
public:
    Node<T> *start;
    Node<T> *end;
    int length = 0;

    List();
    ~List();
    
    void Add(T value, bool debug = false);
    T Get(int position);
    T* GetMem(int position);
    void RemoveLast();
    void RemoveByMem(T value);
    void ToString();
};

template<typename T>
List<T>::List() : start(nullptr), end(nullptr), length(0) {}

template<typename T>
List<T>::~List() {
    while (start != nullptr) {
        RemoveLast();
    }
}

template<typename T>
void List<T>::Add(T value, bool debug){
    if(debug)
        std::cout << "BUG DLL? 1 VALUE: " << &value << "\n";
    Node<T> *currentNode = new Node<T>(value);
    if(start == nullptr || start->isNull){
        if(debug)
        std::cout << "BUG DLL? 2\n";
        currentNode->prev = nullptr;
        currentNode->next = nullptr;
        start = currentNode;
        end = currentNode;
        if(debug)
        std::cout << "BUG DLL? 3\n";
    }else{
        if(debug)
        std::cout << "BUG DLL? 4\n";
        Node<T> *n = start;
        while (n->next != nullptr)//Desde el inicio vamos recorriendo los punteros hasta el final, donde guardaremos nuestro nuevo nodo
        {
            n = n->next;//Con el apuntador cogemos el sigiente nodo, puede ser null
        }
        currentNode->prev = n;//Apuntador previo, hacia atrás
        currentNode->next = nullptr;
        n->next = currentNode;//Solo añadiendo al ultimo objeto de la lista el apuntador del nuevo objeto ya hemos añadido uno mas a la lista
        end = currentNode;
        if(debug)
        std::cout << "BUG DLL? 5\n";
        /*cout << n->prev << "\t" <<  n->piece.isNull << "\t" << n->next << "\n";
        cout << currentNode.prev << "\t" <<  currentNode.piece.isNull << "\t" << currentNode.next << "\n";*/
    }
    length++;
    if(debug)
    std::cout << "BUG DLL? 6 LENGTH: " << length << "\n" ;
}

template<typename T>
T List<T>::Get(int position) {
    Node<T> *currentNode = start;
    bool found = false;
    if(position < length){
        for (int i = 0; i <= position && !false; i++)
        {
            if(i != position){
                currentNode = currentNode->next;
            }else{
                found = true;
            }
        }
    }else{
        throw std::out_of_range("Index out of range");
    }
    return currentNode->value;
}

template<typename T>
T* List<T>::GetMem(int position) {
    Node<T> *currentNode = start;
    bool found = false;
    if(position < length){
        for (int i = 0; i <= position && !false; i++)
        {
            if(i != position){
                currentNode = currentNode->next;
            }else{
                found = true;
            }
        }
    }else{
        throw std::out_of_range("Index out of range");
    }
    return &(currentNode->value);
}

template<typename T>
void List<T>::RemoveLast() {
    if (end == nullptr) {
        return;
    }
    Node<T>* nodeToDelete = end;
    if (start == end) {
        start = nullptr;
        end = nullptr;
    } else {
        end = end->prev;
        end->next = nullptr;
    }
    delete nodeToDelete;
    length--;
}

template<typename T>
void List<T>::RemoveByMem(T value) {
    Node<T>* currentNode = start;
    while (currentNode != nullptr) {
        if (currentNode->value == value) {
            if (currentNode->prev != nullptr) {
                currentNode->prev->next = currentNode->next;
            }
            if (currentNode->next != nullptr) {
                currentNode->next->prev = currentNode->prev;
            }
            if (currentNode == start) {
                start = currentNode->next;
            }
            if (currentNode == end) {
                end = currentNode->prev;
            }
            delete currentNode;
            length--;
            return;
        }
        currentNode = currentNode->next;
    }
}

template<typename T>
void List<T>::ToString(){
    if(start == nullptr){
        std::cout << "List is empty!\n";
    }else{
        Node<T>* currentNode = start;
        for (int i = 0; i < length; i++)
        {
            std::cout << i << ": " << &(currentNode->value) << "\n";
        }
    }
}