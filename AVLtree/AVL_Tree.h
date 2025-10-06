//Author: Jack Fontenot
//Assignment Title: AVL Tree
//Assignment Description: Program 7
//Due Date: 4/6/25
//Date Created: 3/23/25
//Date Last Modified: 4/1/25

#ifndef AVL_TREE_H_
#define AVL_TREE_H_
#include <iostream>

using namespace std;

const int bal = 1;

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        Node(const T& val) : data(val), left(nullptr), right(nullptr),
        height(1) {}
    };

    Node* root;

    //insert and remove
    void insert(Node*& node, const T& value){
        if(node == nullptr){
            node = new Node(value);
        }
        else{
            if(value > node->data){
                insert(node->right, value);
            }
            else if(value < node->data){
                insert(node->left, value);
            }
            else{
                return;
            }
        }

        balance(node);
    }

    void remove(Node*& node, const T& value){
        if(node == nullptr){
            return;
        }
        else{
            if(node->data > value){
                remove(node->left, value);
            }
            else if(node->data < value){
                remove(node->right, value);
            }
            else if(node->right && node->left){
                node->data = findMin(node->right)->data;
                remove(node->right, node->data);
            }
            else{
                if(node->left){
                    node = node->left;
                }
                else{
                    node = node->right;
                }
            }
        }

        balance(node);
    }

    //height and balancing
    void balance(Node*& x){
        if(x == nullptr){
            return;
        }

        if(height(x->left) - height(x->right) > bal){
            if(height(x->left->left) >= height(x->left->right)){
                rotateWithLeftChild(x);
            }
            else{
                doubleWithLeftChild(x);
            }
        }
        else if(height(x->right) - height(x->left) > bal){
            if(height(x->right->right) >= height(x->right->left)){
                rotateWithRightChild(x);
            }
            else{
                doubleWithRightChild(x);
            }
        }

        x->height = max(height(x->left), height(x->right)) + 1;
    }

    int height(Node* node){
        if(node == nullptr){
            return -1;
        }
        else{
            return node->height;
        }
    }

    //int getBalanceFactor(Node* node);

    //rotations
    void rotateWithLeftChild(Node * & k2 ){
        Node* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(Node * & k2){
        Node* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->right), k2->height) + 1;
        k2 = k1;
    }

    void doubleWithLeftChild(Node * & k3){
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(Node * & k3){
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    //traversals
    void inOrder(ostream& out, Node* node){
        if(node == nullptr){
            return;
        }

        inOrder(out, node->left);
        out << node->data << " ";
        inOrder(out, node->right);
    }
    void preOrder(ostream& out, Node* node){
        if(node == nullptr){
            return;
        }

        out << node->data << " ";
        preOrder(out, node->left);
        preOrder(out, node->right);
    }

    void postOrder(ostream& out, Node* node){
        if(node == nullptr){
            return;
        }

        postOrder(out, node->left);
        postOrder(out, node->right);
        out << node->data << " ";
    }

    bool search(Node* node, const T& value){
        if(node == nullptr){
            return false;
        }

        if(node->data > value){
            return search(node->left, value);
        }
        else if(node->data < value){
            return search(node->right, value);
        }
        else{
            return true;
        }
    }

    //delete
    void makeEmpty(Node* t){
        if(t){
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }

        t = nullptr;
    }

    //findmin
    Node* findMin(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        if(node->left == nullptr){
            return node;
        }
        return findMin(node->left);
    }

public:
    AVLTree():root(nullptr){}

    ~AVLTree(){
        makeEmpty(root);
    }

    void insert(const T& value){
        insert(root, value);
    }

    void remove(const T& value){
        remove(root, value);
    }

    void inOrder(ostream& out = cout){
        inOrder(out, root);
        out << endl;
    }

    void preOrder(ostream& out = cout){
        preOrder(out, root);
        out << endl;
    }

    void postOrder(ostream& out = cout){
        postOrder(out, root);
        out << endl;
    }

    bool search(const T& value){
        return (search(root, value));
    }

    int getHeight(){
        return height(root);
    }
};



#endif // AVL_TREE_H_
