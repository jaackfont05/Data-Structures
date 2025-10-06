#include <iostream>

using namespace std;

const int SIZE = 10;

template<class T>
void InsertionSort(T a[], int n){
    int hole;
    T item;

    for(hole = 1; hole < n; ++hole){
        item = a[hole];
        while(hole > 0 && item < a[hole - 1]){
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole] = item;
    }
}
int main()
{
    int a[SIZE];

    for(int i = 0; i < SIZE; ++i){
        a[i] = rand() % SIZE;
    }

     for(auto i: a){
        cout << i << " ";
    }

    cout << endl;

    InsertionSort(a, SIZE);

    for(auto i: a){
        cout << i << " ";
    }

    return 0;
}
