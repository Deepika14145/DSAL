#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float sgpa;

      Student(int roll, string n, float sgpa){
        rollNo = roll;
        name = n;
        this->sgpa = sgpa;
    }

    Student(){
        rollNo = 0;
        name = "";
        sgpa = 0.0;
    }

    void inputStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter SGPA: ";
        cin >> sgpa;
    }

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", SGPA: " << sgpa << endl;
    }
};

class StudentDatabase {
private:
    vector<Student> students;

    void bubbleSort() {
        int n = students.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (students[j].rollNo > students[j + 1].rollNo) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    void insertionSort() {
        int n = students.size();
        for (int i = 1; i < n; i++) {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && students[j].name > key.name) {
                students[j + 1] = students[j];
                j--;
            }
            students[j + 1] = key;
        }
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        float pivot = students[high].sgpa;
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (students[j].sgpa >= pivot) {
                i++;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        return i + 1;
    }

    void binary_search(const string &key) {
        int low = 0;
        int high = students.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (students[mid].name == key) {
                while (mid >= 0 && students[mid].name == key) {
                    students[mid].display();
                    mid--;
                }
                return;
            }
            if (students[mid].name < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << key << " not found." << endl;
    }

public:
    void addStudent() {
        Student student;
        student.inputStudent();
        students.push_back(student);
    }

    void sortRoll() {
        bubbleSort();
    }

    void sortByName() {
        insertionSort();
    }

    void topten() {
        quickSort(0, students.size() - 1);
        int count = min(10, (int)students.size());
        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    void searchSGPA(float sgpa) {
        bool found = false;
        for (const Student &student : students) {
            if (student.sgpa == sgpa) {
                student.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No students found with SGPA " << sgpa << endl;
        }
    }

    void searchByName(const string &name) {
        sortByName(); 
        binary_search(name);
    }

    void displayAll() const {
        for (const Student &student : students) {
            student.display();
        }
    }
};

int main() {
    StudentDatabase db;
    int choice;

    do {
        cout << "\nStudent Database Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Sort by Roll No" << endl;
        cout << "3. Sort by Name" << endl;
        cout << "4. Find Top 10" << endl;
        cout << "5. Search by SGPA" << endl;
        cout << "6. Search by Name" << endl;
        cout << "7. Display All Students" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.addStudent();
                break;
            case 2:
                db.sortRoll();
                db.displayAll();
                break;
            case 3:
                db.sortByName();
                db.displayAll();
                break;
            case 4:
                db.topten();
                break;
            case 5: {
                float sgpa;
                cout << "Enter SGPA to search: ";
                cin >> sgpa;
                db.searchSGPA(sgpa);
                break;
            }
            case 6: {
                string name;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                db.searchByName(name);
                break;
            }
            case 7:
                db.displayAll();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 8);

    return 0;
}