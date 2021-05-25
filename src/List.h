#pragma once
#include<iostream>

template <class T> 
class node {
public:
    T value;
    node* next;
};


template <class T> 
class List {
private:
    int len;
    node<T> *head, *tail;
public:

    //construct-destruct
    List();
    List(List<T>&);
    ~List();

    // add functions
    void append(T);
    void push(T);
    // void insert(int, T);
    
    // delete functions
    void remove(int);
    void pop();
    void clear();

    // get set functions
    T get(int);
    void set(int, T);
    T top();
    T operator[](const int);
    // const T& operator[](const int&);

    // length functions
    int getLen();
    bool isEmpty();

    // print functions
    void printList();
    void printListCustom(std::string, std::string, std::string listStart, std::string listEnd);
    void printListReverse(int);

    // sort
    void sortList();

    // friend functions
    // template problem with friend functions
    // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class/4661372#4661372
    template <class U> 
    friend std::ostream& operator<< (std::ostream&, List<U>&);
};





//construct-destruct
template<class T>
List<T>::List() {
    len = 0;
    head = NULL;
    tail = NULL;
}

template<class T>
List<T>::List(List<T> &oldList) {

    len = 0;
    head = NULL;
    tail = NULL;

    if(oldList.head != NULL){
        node<T> *cursor = oldList.head;
        while(cursor != NULL) {

            append(cursor->value);
            cursor = cursor->next;
        }
    }
}

template<class T>
List<T>::~List() {
    clear();
}



// add functions
template <class T>
void List<T>::append(T newValue) {
    node<T> *newNode = new node<T>;
    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        len = 1;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        len++;
    }
}

template <class T>
void List<T>::push(T newValue) {
    node<T> *newNode = new node<T>;
    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        len = 1;
    }
    else {
        newNode->next = head;
        head = newNode;
        len++;
    }
}



// delete functions
template <class T>
void List<T>::remove(int index){

   if(index >= len || index < 0){
        throw std::string("List index out of range");
    }
    else{
        if(getLen() == 0) {
            throw std::string("List is empty");
            }
        
        // only one element
        else if(getLen() == 1){
            pop();
        }

        // starting of List
        else if(index == 0){
            node<T> *cursor = head;
            head = head->next;
            delete cursor;
            cursor = NULL;
            len--;
            }
        
        // end of List
        else if(index == 0){
            pop();
            }
        
        // middle of the List
        else{
            node<T> *cursor = head;
            node<T> *deleter = cursor->next;
            for (int i = 0; i < index - 1; i++){
                cursor = cursor->next;
                deleter = cursor->next;
            }
            cursor->next = deleter->next;
            delete deleter;
            cursor = NULL;
            deleter = NULL;
            len--;
            }
        }
}

template <class T>
void List<T>::pop(){
    if(getLen() == 0) {
        throw std::string("List is empty");
    }

    // only one element
    else if(getLen() == 1){
        delete head;
        head = NULL;
        tail = NULL;
        len = 0;
    }

    // more than one elements
    else{
        node<T> *cursor = head;
        while (cursor->next != tail) {
            cursor = cursor->next;
        }
        delete tail;
        tail = cursor;
        tail->next = NULL;
        cursor = NULL;
        len--;
    }

}

template <class T>
void List<T>::clear(){
    if (head != NULL) {
        node<T> *cursor = head;
        node<T> *deleter = head;
        head = NULL;
        tail = NULL;

        while (cursor != NULL) {
            cursor = cursor->next;
            delete deleter;
            deleter = cursor;
        }
        len = 0;
        cursor = NULL;
    }
}



// get set functions
template <class T>
T List<T>::get(int index){
    if(index >= len || index < 0){
        throw std::string("List index out of range");
    }

    else{
        if(head == NULL) {
            throw std::string("List is empty");
            }
        else if(index == 0){
            return head->value;
            }
        else {
            node<T> *cursor = head;
            for (int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            return cursor->value;
            }
        }
}

template <class T>
void List<T>::set(int index, T value) {

    if(index >= len || index < 0){
        throw std::string("List index out of range");
    }
    else{
        if(head == NULL) {
            throw std::string("List is empty");
            }
        else if(index == 0){
            
            head->value = value;
            }
        else{
            node<T> *cursor = head;
            for (int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            cursor->value = value;
            }
        }

}

template <class T>
T List<T>::top(){
    if(getLen() == 0) {
        throw std::string("List is empty");
    }

    return tail->value;
}

template <class T>
T List<T>::operator[](int index){
    return get(index);
}



// length functions
template <class T>
int List<T>::getLen() {
    return len;
}

template <class T>
bool List<T>::isEmpty() {
    if(len){
        return false;
    }
    else{
        return true;
    }
}



// print functions
template <class T>
void List<T>::printList() {
    printListCustom(",", "\n", "[", "]");
}

template <class T>
void List<T>::printListCustom(std::string sep, std::string end, std::string listStart, std::string listEnd) {
    node<T> *cursor = head;
    if (cursor == NULL) {
        std::cout << listStart << listEnd << end;
    }
    else {
        std::cout << listStart;
        while (cursor->next != NULL) {
            std::cout << cursor->value << sep;
            cursor = cursor->next;
        }
        std::cout << cursor->value;
        std::cout << listEnd << end;
    }
    cursor = NULL;
}

template <class T>
void List<T>::printListReverse(int index) {

    // if -1 is given print all List
    if(index == -1 ){
        index = getLen() - 1;
    }

    if(index == getLen() - 1){
        std::cout << "[";
    }


    if(index >= len || index < 0){
        throw std::string("List index out of range");
    }

    else if (head == NULL) {
        std::cout << "[]" << std::endl;
    }

    else {
        if(index == 0){
            std::cout << head->value << "]" << std::endl;
        }
        else{
            node<T> *cursor = head;
            for(int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            std::cout << cursor->value << ",";

            printListReverse(index - 1);
        }
    }

}



// sorting functions
template <class T>
void List<T>::sortList(){
    // bubble sort

    int swapped = 1; 
    node<T> *cursor = head; 
    node<T> *cursor2 = NULL; 

    // empty list
    if (head == NULL){
        return; 
    }

    // if no swaps happen in a full pass break
    while (swapped){
        swapped = 0; 
        cursor = head; 
        while (cursor->next != cursor2){ 
            if (cursor->value > cursor->next->value){  

                // swap values (because it is easier like that)
                T temp = cursor->value; 
                cursor->value = cursor->next->value; 
                cursor->next->value = temp;    

                swapped = 1; 
            } 
            cursor = cursor->next; 
        } 
        cursor2 = cursor; 
    }
}



// friend functions
template <class T>
std::ostream& operator<< (std::ostream &out,  List<T> &l){
    l.printListCustom(",", "", "[", "]");
    return out;
}

