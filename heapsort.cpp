#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to sort array in descending order
void heapSortPqueueDescending(vector<int> &arr) {
    priority_queue<int> pq; // Max-heap (default)
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

// Function to sort array in ascending order
void heapSortPqueueAscending(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

int main() {
    int size;
    cout << "Enter the size of the array you want: " << endl;
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    char repeat;
    int choice;

    do {
        cout << "\nChoose sorting order: \n1. Ascending Order\n2. Descending Order\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                heapSortPqueueAscending(arr);
                cout << "Sorted array in ascending order: ";
                for (int i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                heapSortPqueueDescending(arr);
                cout << "Sorted array in descending order: ";
                for (int i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                cout << "Exiting program." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << "\nDo you want to perform any other operation (Y/N)?: ";
        cin >> repeat;

    } while (repeat == 'Y' || repeat == 'y');

    cout << "Exiting the program." << endl;
    return 0;
}
