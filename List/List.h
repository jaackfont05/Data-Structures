//Author: Jack Fontenot
//Assignment Title: Prog4
//Assignment Description: List
//Due Date: 2/23/25
//Date Created: 2/7/25
//Date Last Modified: 2/23/25

#ifndef LIST_H_
#define LIST_H_


#include "ContainerInterface.h"

template <class T>
class List:public containerInterface<T>
{
private:
   // Node struct definition (doubly linked list node)
    struct Node {
        T data;
        Node* prev;
        Node* next;

        // Node constructor
        Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
            : data(data), prev(prev), next(next) {}
    };

    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node
    size_t listSize; // Size of the list (number of elements)

public:
    List(){
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

	containerInterface <T>& pushFront(const T d){
	    head = new Node(d, nullptr, head);
	    if(head->next){
            head->next->prev = head;
	    }
	    if(!tail){
            tail = head;
	    }

	    listSize++;

	    return *this;
	 }

	 containerInterface <T>& pushBack(const T d){
	     tail = new Node(d, tail, nullptr);
	     if(tail->prev){
            tail->prev->next = tail;
	     }

	     if(!head){
            head = tail;
	     }

	     listSize++;

	     return *this;
	 }

	 containerInterface <T>& popFront( ){
	     if(head == nullptr){
            throw BADINDEX{};
	     }

	     if(head->next != nullptr){
            head = head->next;
            delete head->prev;
	     }
	     else{
            delete head;
	     }

	     listSize--;

	     return *this;
	 }

	 containerInterface <T>& popBack( ){
	     if(tail == nullptr){
            throw BADINDEX{};
	     }

	     if(tail->prev != nullptr){
            tail = tail->prev;
            delete tail->next;
	     }
	     else{
            delete tail;
	     }

	     listSize--;

	     return *this;
	 }

	 int getSize() const {
	     return listSize;
	 }

	 bool empty() const {
	     return head == nullptr;
	 }

	 T front() const{
	     if(listSize == 0){
            throw BADINDEX{};
	     }
	     return head->data;
	 }

	 T back() const{
	     if(listSize == 0){
            throw BADINDEX{};
	     }
	     return tail->data;
	 }

	 T&   operator [](int n){
	     if(n < 0 || n >= static_cast<int>(listSize)){
            throw BADINDEX{};
	     }
	     Node* curNode = head;
	     while(n > 0){
            curNode = curNode->next;
            n--;
	     }
	     return curNode->data;
	 }

	 void erase(){
	     head = nullptr;
	     listSize = 0;
	 }

	 ~List(){
	     Node* curNode = head;
	     Node* nextN = curNode->next;

	     while(nextN){
            if(curNode){
                delete curNode;
            }
            curNode = nextN;
            nextN = nextN->next;
	     }

	     if(curNode){
            delete curNode;
	     }
	 }

   // Iterator class definition
    class Iterator {
    private:
        Node* current; // Pointer to the current node

    public:
        // Iterator constructor
        Iterator(Node* node): current(node) {};

        // Dereference operator
        T& operator*() {
            return current->data;
        }

        // Pre-increment operator (move to the next node)
        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int){
            Iterator tmp = *this;
            current = current->next;
            return tmp;
        }

        // Equality comparison operator
        bool operator==(const Iterator& other) const{
            return current == other.current;

        }

        // Inequality comparison operator
        bool operator!=(const Iterator& other) const{
            return current != other.current;
        }


    };

    // Begin and End functions to get iterators
    Iterator begin(){
    	return Iterator(head);
    }

    Iterator end(){
    	return List<T>::Iterator(nullptr);
    }

};

#endif
