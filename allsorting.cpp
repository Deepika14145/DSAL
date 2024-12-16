#include<iostream>
#include<string>
using namespace std;

int n = 10;
struct seit{
    int roll; 
    string name;
    float sgpa;
};

class students{
    struct seit stud[5];
    public:
    void input();
    void display();
    void bubble_roll();
    void binary_search_roll();
    void insertion_name();
    void binary_search_name();

void students::input(){
    cout<<"Enter Details: "<<endl;
    for(int i=0; i<10; i++){
        cout<<"Enter roll no"<<endl;
        cin>>stud[i].roll;
        cout<<"Enter Name of the student: "<<endl;
        cin>>stud[i].name;
        cout<<"Enter sgpa of student"<<endl;
        cin>>stud[i].sgpa;
    }
}

void students::display(){
    for(int a = 0; a<10; a++){
        cout<<"Roll No: "<<stud[a].roll<<" ";
        cout<<"Name: "<<stud[a].name<<" ";
        cout<<"SGPA: "<<stud[a].sgpa<<" ";
    }
}  

void students::bubble_roll(){

}

};    

   

   

int main(){
    students st;

    while(true){
        cout<<"1.Enter the details."<<endl;
        cout<<"2.Roll numbers in ascending order."<<endl;
        cout<<"3."
    }

}