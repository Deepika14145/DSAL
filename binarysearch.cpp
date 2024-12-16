#include<iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(   int value){
        data = value;
        left = right = NULL;
    }

    Node* insert(Node* root, int value){
        if(root == NULL){
            root = new Node(value);
            return;
        }
        if(value < root-> data){
            root-> left = insert(root->left, value);
        }
        else if(value > root-> data){
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node* minNode(Node* root, int value){
        while(root-> left != NULL){
            root = root-> left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int value){
        if(root == NULL)
            return root;

        if(value < root-> data){
            root-> left = deleteNode(root-> left, value);
        }    
        else if(value > root->data){
            root->right = deleteNode(root->right, value);
        } else {
            //handle condition if it has only one or no child
            if(root-> left == nullptr){
                Node* temp = root -> right;
                delete root;
                return temp;
            }
            else if(root-> right == nullptr){
                Node* temp = root -> left;
                delete root;
                return temp;
            }
        }
        return root;
    }

    bool search(Node* root, int value){
        if(root == nullptr){
            return false;
        }
        if(root-> data == value){
            return true;
        }
        else if(value < root-> data){
            return search(root-> left, value);
        }
        else{
            return search(root->right, value);
        }
    }

    void preOrder(Node* root){
        if(root == NULL)
            return;
        preOrder(root->left);
        cout<<root->data<<" ";
        preOrder(root->right);    
    }

    void inorder(Node* root){
        if(root == NULL){
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);    
        }
    }

    void postOrder(Node* root){
        if(root == NULL){
            return;
        preOrder(root->left);
        preOrder(root->right);   
        cout<<root->data<<" ";
        }
    }

    int depth(Node* root){
        if(root == NULL)
            return 0;  
        return 1 + max(depth(root->left), depth(root->right));
    }

    
};