//AUTHOR: Jack Fontenot
//ASSIGNMENT TITLE: program 1
//ASSIGNMENT DESCRIPTION: HTML check
//DUE DATE: 02/02/25
//DATE CREATED: 01/27/25
//DATE LAST MODIFIED: 01/29/25


#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stack>

using namespace std;

int main()
{
    ifstream file;
    string fName, curTag;
    char c;
    bool activeTag = false;
    stack<string> tags;

    cin >> fName;

    file.open(fName);
    assert(file);

    while(file.get(c)){
        if(c == '<'){
            activeTag = true;
            curTag = "";
        }
        if(c == '>' && c != ' '){
            curTag += c;
            activeTag = false;
            tags.push(curTag);
        }
        if(c == ' '){
            curTag += '>';
            tags.push(curTag);
            activeTag = false;
        }
        if(activeTag){
            if(c == '/'){
                while(c != '>'){
                    file.get(c);
                    curTag += c;
                }
                if(curTag == tags.top()){
                    tags.pop();
                }
            }
            else{
                curTag += c;
            }
        }
    }

    file.close();

    cout << tags.top();

    if(tags.empty()){
        cout << "File " << fName << " --> Is Balanced" << endl;
    }
    else{
        cout << "File " << fName << " --> Is Not Balanced" << endl;
    }

    return 0;
}
