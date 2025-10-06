
#include <string>
#include <functional>

using namespace std;

int hash1(const string& key, int tableSize){
    int hashVal = 0;

    for(char c: key){
        hashVal += c;
    }

    return (key[0] + 27 * key[1] + 729 * key[2] % tableSize);
}




int hash3(const string& key, int tableSize){
    int hashVal = 0;

    for(char c: key){
        hashVal = 37 * hashVal + c;
    }
    return hashVal % tableSize;
}


