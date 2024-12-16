#include<iostream>
using namespace std;

class CircularQueue{
private:
    int front, rear;
    int size;
    int *queue;

public:
    CircularQueue(int s)
{
    front = rear =-1;
    size =s;
    queue = new int[size];
}

~CircularQueue(){
    delete[] queue;
}

void enqueue(int item){
    //check for overflow
    if(front == (rear +1) % size){
        cout<<"Queue overflow"<<endl;
    }
    else {
        item = queue[front];
        if(front == -1){
            front = rear = 0;
        }
        else{
            rear = (rear +1) % size;
            item = queue[rear];
        }
    }
}

int dequeue(int item){
    //check for underflow
    if(front == -1){
        cout<<"Queue is underflow, cannot delete element"<<endl;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }
    return item;
    }

void display(){
    if(front = rear  == -1){
        cout<<"queue is empty"<<endl;
    } else{
        // cout<<"Queue elements are: ";
        // for(int i = front; i!= rear; i = (i + 1) % size){
        //     cout<<queue[i]<<" ";
        // }
        // cout<<queue[rear]<<endl;

        // cout<<"elements are:"<<endl;
        // for(int i = 0; i< size; i++){
        //     cout<<queue[i]<<" ";
        //     if(i == rear){
        //         break;
        //     }

        cout<<"Elements are: "<<endl;
        for(int i = 0; i<size; i++){
            cout<<queue[(front + i) % size]<<" ";
        }
        cout<<endl;
        }

        }
};

int main(){
    int choice, value, size;
    
    cout<<"Enter size of Circular queue: ";
    cin>>size;

    CircularQueue cq(size);

    do{
        cout<<"\nCircular Queue Operations:\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";

        switch(choice){
            case 1:
                cout<<"Enter the value you want to insert:";
                cin>>value;
                cq.enqueue(value);
                break;
            case 2:
                cout<<"Enter the index from which you want to delete element:";
                cin>>value;
                value = cq.dequeue(value);
                cout<<"Deleted element is:"<<value<<endl;
                break;
            case 3:
                cq.display();  
                break;
            case 4:
                cout<<"Exiting the program"<<endl;
                exit(0);
                break;
            default:
                cout<<"Invalid choice, please try again."<<endl;  
        }
    } while(choice != 4);

        return 0;           
}
