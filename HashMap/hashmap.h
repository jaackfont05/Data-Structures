//Author: Jack Fontenot
//Assignment Title: Program 8
//Assignment Description: hashmap
//Due Date: 4/27/25
//Date Created: 4/14/25
//Date Last Modified: 4/14/25

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <functional>
#include <list>

using namespace std;


template <typename K, typename V>
class hashMap {
private:
    static constexpr size_t DEFAULT_CAPACITY = 10;
    static constexpr double LOAD_FACTOR_THRESHOLD = 0.75;
    double currentSize;
    size_t currentCapacity;

    size_t hashFunction(const K& key) const {
        return hash<K>{}(key) % currentCapacity;
    }

    void resize() {
        currentCapacity *= 2;
        list<V>* temp = new list<V>[currentCapacity];
        for(int i = 0; i < currentCapacity/2; ++i){
            for(int j = 0; j < hMap[i].size(); ++j){
                temp[i].push_front(hMap[i].front());
                hMap[i].pop_front();
            }
        }

        delete [] hMap;
        hMap = temp;
    }

    // TODO: Add data structure for the hash table
    list<V>* hMap;

public:
    hashMap(size_t capacity = DEFAULT_CAPACITY)
           :currentCapacity(capacity), currentSize(0) {

        hMap = new list<V>[capacity];


    }

    ~hashMap() {
        clear();
    }

    void insert(const K& key, const V& value) {
        if(currentSize / currentCapacity >= 0.75){
            resize();
        }
        K nKey = hashFunction(key);
        hMap[nKey].push_back(value);
        currentSize++;
    }

    bool remove(const K& key) {
        bool flag = false;

        if(hMap[key].front() != nullptr){
            hMap[key].pop_front();
            flag = true;
            currentSize--;
        }

        return flag;
    }

    void clear() {
        delete [] hMap;
        hMap = nullptr;
    }

    size_t size() const {
        return currentSize;
    }

    size_t capacity() const {
        return currentCapacity;
    }

    V& operator[](const K& key) {
        return hMap[key].front();
    }
};

#endif // HASHMAP_H_
