#ifndef FORWARD_LIST_NOREPO_LIST_H
#define FORWARD_LIST_NOREPO_LIST_H
#include <iostream>
#include <ostream>
#include "node.h"
#include <ctime>

template <typename T>
    class Iterator{
    private:
        typedef node<T> Node;
        Node* iterator;
    public:
        Iterator(){iterator = nullptr;}
        Iterator(Node * itr){ this->iterator = itr;}

        void operator ++(){
            this->iterator = this->iterator->next;
        }
        T& operator *(){
            return iterator->value;
        }
        bool operator ==(const Iterator& itr){
                return iterator == itr.iterator;
        }
        bool operator !=(const Iterator& itr){
            return iterator != itr.iterator;
        }
        Node *get_itr(){
            return iterator;
        }


    };


template <class T>
class List {
protected:
    typedef Node<T> node;
    node* head  ;
    node* tail  ;

public:
    typedef Iterator<T> iterator;
    
    List(const List& lista){
        this->head = lista.head;
        this->tail = lista.tail;
    }

    List(T* arr,int tam){
        head = nullptr;
        tail = head;
        for(int i = 0 ; i < tam ; i++){
            push_back(arr[i]);
        }
        tail->next = nullptr;
    }
    
    List(node* m){
        head = m;
        tail = m;
    }

    List(int tam){
        head = nullptr;
        tail = head;
        srand(time(nullptr));
        for(int i = 0 ; i < tam ; i++){
            push_back(rand()%10);
        }
    }

    List(){
        head = nullptr;
        tail = head;
    }

    ~List(){
        while(empty()){
            pop_back();
        }
    }

    // Retorna una referencia al primer elemento
    T front(){
        return head->value;
    };

    // Retorna una referencia al ultimo elemento
    T back(){
        return tail->value;
    };

    // Inserta un elemento al final
    void push_back(const T& element) {
        if(head == nullptr){
            node* new_node = new node(element , nullptr);
            head = new_node;
            tail = new_node;
        }else{
            node* new_node = new node (element, nullptr);
            tail->next = new_node;
            tail = new_node;
        }
    };

    // Inserta un elemento al inicio
    void push_front(const T& element) {
        node *new_node = new node(element, head);
        head = new_node;
    };

    // Quita el ultimo elemento y retorna una referencia
    List& pop_back() {
        for(node* pointer = head ; ; pointer= pointer->next){
            if(pointer->next == tail){
                tail = pointer;
                tail->next = nullptr;
                break;
            }
        }
        if(tail == head){
            head = nullptr;
        }
    };

    // Quita el primer elemento y retorna una referencia
    List& pop_front(void){
        node* pointer = head;
        head = head->next;
        delete pointer;
    };

    // Acceso aleatorio
    T& operator[] (const int& pos){
        node* pointer = head;
        for(int i = 0 ; i < size() ; i++){
            if(i == pos){
                return pointer->value;
            }
            pointer = pointer->next;
        }
    };
    //ITERADORES
    iterator begin(){
        return iterator(head);
    }
    iterator end(){
        return iterator(tail);
    }

    // la lista esta vacia?
    bool empty() {
        return head == nullptr;
    };

    // retorna el tamaño de la lista
    unsigned int size(){
        node* temp = head;
        for(int i = 0 ; ; i ++){
            if(temp == tail)
                return i;
            else
                temp = temp->next;
        }
    };

    // Elimina toda la lista
    void clear(){
        node* pointer = head;
        int size_per = size();
        for(int i = 0 ; i < size_per ; i++){
            head = head->next;
            delete pointer;
            pointer = head;
        }
        head = nullptr;
        delete pointer;

    };

     // Elimina un elemento en base a un puntero
    void erase(node* borrar) {
        node* pointer = head;
        node* next_borrar = head->next;
        for(int i = 0 ; ; i++){
            if(pointer->next == borrar){
                next_borrar = next_borrar->next;
                pointer->next = next_borrar;
                delete borrar;
                break;
            }
            pointer = pointer->next;
            next_borrar = next_borrar->next;
        }
    };

    // Inserta un elemento  en base a un puntero
    void insert(node* insertar){
        node* pointer = head;
        for(int i = 0 ; i< size() ; i++){
            if(pointer->next == insertar->next){
                pointer->next = insertar;
                break;
            }
            pointer = pointer->next;
        }

    };
    

    // Elimina todos los elementos por similitud
    void remove(const T& x) {
        node* pointer = head;
        while(pointer!= nullptr){
            if(head->value == x){
                node* temp = pointer;
                head = head->next;
                pointer = head;
                delete temp;
                continue;
            }
            if(pointer == tail and tail->value == x){
                node* temp = head;
                for(int i = 0 ; ;i++){
                    if(temp->next == tail){
                        tail = temp;
                        pointer = nullptr;
                        tail->next = pointer;
                        break;
                    }
                    temp = temp->next;
                }
                continue;
            }
            if(pointer->value == x){
                node* temp = head;
                for(int i = 0 ; ;i++){
                    if(temp->next == pointer){
                        node* temp2 = pointer;
                        pointer = pointer->next;
                        temp->next = pointer;
                        delete temp2;
                        break;
                    }
                    temp = temp->next;
                }
            }

            else{
                pointer = pointer->next;
            }

        }
        delete pointer;
    };

    // ordena la lista
    List& sort() {
        for(node* nuevo = head->next; nuevo!= nullptr ; nuevo= nuevo->next){
            for(node* old = head ; old != nuevo ; old = old->next){
                if(nuevo->value < old->value){
                    T valor = old->value;
                    old->value = nuevo->value;
                    nuevo->value = valor;
                }
            }
        }
    };

    // invierte la lista
    List& reverse() {
        node *lista2 = tail;
        node *head2 = lista2;
        int counter = size();
        for(counter ; counter> 0 ; counter--){
            node *temp = head;
            for(int j = 0 ; j < size() ; j++){
                if(temp->next == lista2){
                    node* rev = new node(temp->value, nullptr);
                    tail->next = rev;
                    tail = rev;
                    lista2 = temp;
                    break;
                }
                temp = temp->next;
            }
        }
        head = head2;
    }

    // Imprime la lista con cout
    friend std::ostream& operator << (std::ostream &os, const List & cll){
        node * pointer = cll.head;
        do{
            os << pointer->value << " ";
            pointer = pointer->next;
        }while(pointer != nullptr);

        return os;
    }
};



#endif //FORWARD_LIST_NOREPO_LIST_H
