//Author: Jack Fontenot
//Assignment Title: program 10
//Assignment Description: Galactic Bonding
//Due Date: 5/4/2025
//Date Created: 5/3/2025
//Date Last Modified: 5/5/2025

#include <iostream>
#include <vector>
#include <utility>

using namespace std;



//Disjoint Set

class disjointSet{

private:
    vector<int> pset;
    int MAX_STARS = 1000;
public:

    disjointSet(){
        pset.assign(MAX_STARS,0);
    }

    void initSet(int N ){

        for(size_t i = 0; i < N; i++)
            pset[i] = i;
    }

    int findSet(int i){
       if (pset[i] == i)
        return i;
       else
        return (pset[i]=findSet(pset[i]));
    }

    bool isSameSet(int i, int j){
      return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        pset[findSet(i)] = findSet(j);
    }

    int countSets(int N){
       int count = 0;

       for(size_t i = 0; i < N; i++){
          if(pset[i] == i) count++;
       }

       return count;
    }

};


int main()
{
    disjointSet p();
    int T;
    double D;
    int N;
    double x, y;
    vector<pair<double, double>> pairs;
    pair<double, double> temp;

    cin >> T;

    do{
        cin >> N;
        cin >> D;

        while(N > 0){
            cin >> x;
            cin >> y;
            temp = {x, y};
            pairs.push_back(temp);
            N--;
        }

        T--;

    }while(T > 0);




    return 0;
}
