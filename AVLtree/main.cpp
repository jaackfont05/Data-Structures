#include <iostream>
#include "AVL_Tree.h"

using namespace std;

int main()
{
    AVLTree<int> tree;

    // Insert elements
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(50);
    tree.insert(5);

    cout << "In-Order Traversal: ";
    tree.inOrder();

    cout << "Tree Height: " << tree.getHeight() << endl;

    tree.remove(20);
    cout << "After Deleting 20: ";
    tree.inOrder();

    cout << "Searching for 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
