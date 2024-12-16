#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;

struct Node{
    char data;
    Node* next;  
};

class stack{
private:
    Node* top;

public:
    stack(){
        top = NULL;
    }    

    void push(char value){
        Node* newNode = new Node;
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
    }

    char pop(){
        if(top == NULL)
            return 0;
        Node* temp = top;    
        char popelement = top -> data;
        top = top -> next;
        delete temp;
        return popelement;    
    }

    char peek(){
        if(top == NULL)
            return 0;
        return top -> data;
    }

    bool isEmpty(){  // Corrected function name
        return top == NULL;
    }  
};

int precedence(char op){  // Function to determine operator precedence
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/') 
        return 2;
    if(op == '^' || op == '$')
        return 3;
    return 0;    
}

string infixToPostfix(string infix){
    stack s;  // Corrected class name from 'Stack' to 'stack'
    string postfix = "";
    for(char ch : infix){
        if(isalnum(ch)){
            postfix += ch; // add operand to postfix
        }
        else if(ch == '('){
            s.push(ch);
        }
        else if(ch == ')'){ 
            while(!s.isEmpty() && s.peek() != '('){
                postfix += s.pop();
            }
            s.pop(); // pop '('
        }
        else{ // operator
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(ch)){
                postfix += s.pop();
            }
            s.push(ch); // push current operator
        }
    }
    while(!s.isEmpty()){
        postfix += s.pop();
    }
    return postfix;
}

string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());

    for(int i = 0; i< infix.length(); i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int evaluatePostfix(string postfix){  // Corrected argument type to 'string'
    stack s;
    for(char ch : postfix){
        if(isdigit(ch)){  // Corrected to check if the character is a digit
            s.push(ch - '0');
        }
        else{
            int a = s.pop();
            int b = s.pop();
            switch(ch){
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;   
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                case '^':
                    s.push(pow(a, b));
                    break;                 
            }
        }
    }
    return s.pop();
}

int evaluatePrefix(string prefix){  // Corrected argument type to 'string'
    stack s;
    reverse(prefix.begin(), prefix.end());

    for(char ch : prefix){
        if(isdigit(ch)){  // Corrected to check if the character is a digit
            s.push(ch - '0');
        } else {
            int a = s.pop();
            int b = s.pop();
            switch(ch){
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                case '^':
                    s.push(pow(a, b));
                    break;                
            }
        }
    }
    return s.pop();
}

int main(){
    string infix, prefix, postfix;
    char repeat;

    do{
    cout << "Enter an infix expression: ";
    cin >> infix;

    int choice;
    cout << "Choose an operation:\n";
    cout << "1. Convert to postfix\n";
    cout << "2. Convert to prefix\n";
    cout << "3. Evaluate postfix expression\n";
    cout << "4. Evaluate prefix expression\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice){
        case 1:
            postfix = infixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;
            break;
        case 2:
            prefix = infixToPrefix(infix);
            cout << "Prefix expression: " << prefix << endl;
            break;
        case 3:
            cout << "Postfix evaluation result: " << evaluatePostfix(infix) << endl;
            break;
        case 4:
            cout << "Prefix evaluation result: " << evaluatePrefix(infix) << endl;
            break;
        case 5 :
            cout << "Exiting the program.";
            exit(0); 
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    cout<<"Do you want to perform another operation?? (y/n): ";
    cin>>repeat;
    }
    while(repeat =='y' || repeat == 'Y');

    cout<<"Exiting the program." <<endl;
    return 0;
}
