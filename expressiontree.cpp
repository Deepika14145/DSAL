#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;

        Node(char value){
            data = value;
            left = right = NULL;
        };
};

class ExpressionTree{
public:
    Node* constructFromPostfix(const string& postfix){
        stack<Node*> st;
        for(char ch : postfix){
            if(isalnum(ch)) {
                st.push(new Node(ch));
            } else{
                Node* node = new Node(ch);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
        return st.top();
    }    

    Node* constructFromPrefix(const string& prefix){
        stack<Node*> st;

        for(int i = prefix.length()-1; i>= 0; i--){
            char ch = prefix[i];

            if(isalnum(ch)){
                st.push(new Node(ch));
            } else {
                Node* node = new Node(ch);
                node->left = st.top(); st.pop();
                node-> right = st.top(); st.pop();

                st.push(node);
            }    
            }
            return st.top();
        }

    void inorder(Node* root){
        if(root){
            inorder(root -> left);
            cout<<root -> data << " ";
            inorder(root-> right);
        }
    }
    void preorder(Node* root){
        if(root){
            cout<<root->data << " ";
            preorder(root ->left);
            preorder(root -> right);
        }
    }
    void postorder(Node* root){
        if(root){
            postorder(root -> left);
            postorder(root -> right);
            cout<<root -> data << " ";
        }
    }
};

int main(){ 
    ExpressionTree tree;

    string postfix;
    cout<<"Enter the postfix expression: "<<postfix<<endl;
    cin>>postfix;
    Node* rootfrompostfix = tree.constructFromPostfix(postfix);
    cout<<"Tree constructed!"<<endl;

    cout<<"Tracversal"<<endl;
    cout<<"Inorder Traversal:";
    tree.inorder(rootfrompostfix);
    cout<<endl;

    cout<<"Preorder Traversal:";
    tree.preorder(rootfrompostfix);
    cout<<endl;

    cout<<"Postorder Traversal:";
    tree.postorder(rootfrompostfix);
    cout<<endl;


    string prefix;
    cout<<"Enter the expression  prefix: "<<prefix<<endl;
    cin>>prefix;
    Node* rootfromprefix = tree.constructFromPrefix(prefix);
    cout<<"Tree constructed!"<<endl;


    cout<<"Traversal"<<endl;
    cout<<"Inorder Traversal:";
    tree.inorder(rootfromprefix);
    cout<<endl;

    cout<<"Preorder Traversal:";
    tree.preorder(rootfromprefix);
    cout<<endl;

    cout<<"Postorder Traversal:";
    tree.postorder(rootfromprefix);
    cout<<endl;
    
    return 0;

}
