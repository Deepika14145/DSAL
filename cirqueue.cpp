#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int *queue;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[size];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Enqueue Operation
    void enqueue(int item) {
        if ((rear + 1) % size == front) {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1) { // First element
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        queue[rear] = item;
    }

    // Dequeue Operation
    int dequeue() {
        if (front == -1) { // Queue is empty
            cout << "Queue underflow, cannot delete element" << endl;
            return -1;
        }

        int item = queue[front];
        if (front == rear) { // Single element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return item;
    }

    // Display Queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    char repeat;

    CircularQueue cq(size);

    do {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Insert Elements\n";
        cout << "2. Delete Elements\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int numValues;
            cout << "How many elements do you want to insert? ";
            cin >> numValues;
            cout << "Enter " << numValues << " elements: ";
            for (int i = 0; i < numValues; ++i) {
                cin >> value;
                cq.enqueue(value);
            }
            break;
        }

        case 2: {
            int numDeletions;
            cout << "How many elements do you want to delete? ";
            cin >> numDeletions;
            for (int i = 0; i < numDeletions; ++i) {
                int deletedValue = cq.dequeue();
                if (deletedValue != -1)
                    cout << "Deleted element: " << deletedValue << endl;
                else
                    break; // Stop deleting if queue is empty
            }
            break;
        }

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');

    cout << "Exiting the program." << endl;

    return 0;
}
