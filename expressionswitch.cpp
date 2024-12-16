#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = NULL;
    };
};

class ExpressionTree {
public:
    Node* constructFromPostfix(const string& postfix) {
        stack<Node*> st;
        for (char ch : postfix) {
            if (isalnum(ch)) {
                st.push(new Node(ch));
            } else {
                Node* node = new Node(ch);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
        return st.top();
    }

    Node* constructFromPrefix(const string& prefix) {
        stack<Node*> st;

        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix[i];

            if (isalnum(ch)) {
                st.push(new Node(ch));
            } else {
                Node* node = new Node(ch);
                node->left = st.top(); st.pop();
                node->right = st.top(); st.pop();

                st.push(node);
            }
        }
        return st.top();
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    //iterative approach
    void iterativeinorder(Node* root){
        
    }
};

int main() {
    ExpressionTree tree;
    Node* root = nullptr;

    int choice;
    cout << "Choose an operation:\n";
    cout << "1. Construct from postfix\n";
    cout << "2. Construct from prefix\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            string postfix;
            cout << "Enter the postfix expression: ";
            cin >> postfix;
            root = tree.constructFromPostfix(postfix);
            cout << "Tree constructed!" << endl;
            break;
        }
        case 2: {
            string prefix;
            cout << "Enter the prefix expression: ";
            cin >> prefix;
            root = tree.constructFromPrefix(prefix);
            cout << "Tree constructed!" << endl;
            break;
        }
        default: {
            cout << "Invalid choice!" << endl;
            return 0;
        }
    }

    cout << "Enter type of traversal which you have to perform:" << endl;
    cout << "1. Inorder Traversal" << endl;
    cout << "2. Preorder Traversal" << endl;
    cout << "3. Postorder Traversal" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Inorder Traversal: ";
            tree.inorder(root);
            cout << endl;
            break;
        }
        case 2: {
            cout << "Preorder Traversal: ";
            tree.preorder(root);
            cout << endl;
            break;
        }
        case 3: {
            cout << "Postorder Traversal: ";
            tree.postorder(root);
            cout << endl;
            break;
        }
        default: {
            cout << "Invalid traversal choice!" << endl;
            return 0;
        }
    }

    return 0;
}
