//Author: Jack Fontenot
//Assignment Title: Prog3
//Assignment Description: Vector
//Due Date: 2/16/25
//Date Created: 2/5/25
//Date Last Modified: 2/10/25

#ifndef VECTOR_H_
#define VECTOR_H_

#include "ContainerInterface.h"
#include <cstring>
#include <stdexcept>

using namespace std;

template <class T>
class Vector:public containerInterface<T>
{
  private:

    int size;
    int capacity;
    T * data;

  public:

    Vector(int size=0, int capacity=1):size(size), capacity(capacity){
        data = new T[capacity];
    }

    containerInterface <T>& pushFront(const T d){
        if(size >= capacity){
            grow();
        }
        shiftRight();
        data[0] = d;
        size++;

        return *this;
	}

    containerInterface <T>& pushBack(const T d){
        if(size >= capacity){
            grow();
        }
        data[size] = d;
        size++;

        return *this;
    }

    containerInterface <T>& popFront( ){
        if(size > 0){
            for(int i = 0; i < size - 1; ++i){
                data[i] = data[i+1];
            }

            size--;
        }

        return *this;
    }

    containerInterface <T>& popBack( ){
        if(size > 0){
            data[size - 1] = 0;
            size--;
        }
        return *this;
    }

    int  getSize() const {

        return size;
    }

    bool empty() const {

        return size < 1;
    }

    T  front() const{

        return data[0];
    }

    T    back() const{
        return data[size-1];
    }

    T&   operator [](int n){
        if(n < 0 || n >= size){
            throw BADINDEX{};
        }
        return data[n];
    }

    void erase(){
        size = 0;
    }

    ~Vector(){
        delete [] data;
    }

    void grow(){
        capacity *= 2;
        T* newData = new T[capacity];
        memcpy(newData, data, size*sizeof(T));
        delete [] data;
        data = newData;
    }


    void shiftRight(){
        for(size_t i = size; i > 0; i--){
            data[i] = data[i-1];
        }
    }


   // Iterator class
    class Iterator {
    private:
        T* ptr; // Pointer to the element in the array
    public:
        explicit Iterator(T* ptr):ptr(ptr){}

        // Dereference operator
        T& operator*() const{
            return *ptr;
        }

        // Pre-increment
        Iterator& operator++(){
            ptr++;

            return *this;
        }

        // Post-increment
        Iterator operator++(int){
            Iterator temp = *this;

            ptr++;

            return Iterator(temp);
        }

        // Equality comparison
        bool operator==(const Iterator& other) const{
            return ptr == other.ptr;
        }

        // Inequality comparison
        bool operator!=(const Iterator& other) const{
            return ptr != other.ptr;
        }
    };

    // Begin and End functions for the iterator
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }


};

#endif // VECTOR_H_
