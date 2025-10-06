#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector<int> v;
    v.pushFront(17);
    v.pushFront(10);
    v.pushFront(-17);
    v.pushFront(27);
    v.pushFront(36);
    cout << v[0] << endl;

    for(auto& i : v){
        cout << i << " ";
        i *= 2;
    }

    //for(Vector<int>::Iterator i = v.begin(); i != v.end(); ++i)
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
