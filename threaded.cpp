#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool leftThread, rightThread;

    Node(int val) : data(val), left(nullptr), right(nullptr), leftThread(true), rightThread(true) {}
};

class ThreadedBinaryTree {
public:

    Node* root;

    ThreadedBinaryTree() : root(nullptr) {}

    Node* findLeftMost(Node* node) {
        while(node && !node->leftThread) {
            node = node->left;
        }
        return node;
    }

    Node* findInorderSuccessor(Node* node) {
        if(node->rightThread) {
            return node->right;
        }

        node = node->right;
        return findLeftMost(node);
    }

    Node* findPreorderSuccessor(Node* node) {
        if(!node->leftThread) {
            return node->left;
        }

        if(!node->rightThread) {
            return node->right;
        }

        while(node->rightThread && node->right) {
            node = node->right;
        }

        return node->right;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if(!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while(current) {
            parent = current;
            if(current->data < val) {
                if(current->rightThread) {
                    break;
                }
                current = current->right;
            } else {
                if(current->leftThread) {
                    break;
                }
                current = current->left;
            }
        }

        if (val < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

    void inorderTraversal() {
        
        Node* current = findLeftMost(root);
        while(current) {
            cout << current->data << " ";
            current = findInorderSuccessor(current);
        }
        cout << "\n";
    }

    void preorderTraversal() {
        
        Node* current = root;
        while(current) {
            cout << current->data << " ";
            current = findPreorderSuccessor(current);
        }
        cout << "\n";
    }

};


int main() {
    ThreadedBinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "In-order Traversal:   ";
    tree.inorderTraversal();

    std::cout << "Pre-order Traversal:  ";
    tree.preorderTraversal();

    return 0;
}