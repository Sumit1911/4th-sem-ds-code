#include<iostream>
#include<string>
using namespace std;

struct Student {
    int roll_number;
    string name;
    int age;
    int grade;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if(numStudents >= MAX_STUDENTS) {
        cout<<"Maximum number of students reached."<<endl;
        return;
    }
    Student& stu = students[numStudents++];
    cout<<"Enter roll_number, name, age, grade: ";
    cin>>stu.roll_number>>stu.name>>stu.age>>stu.grade;
}

void displayAllStudentsName() {
    if(numStudents == 0) {
        cout<<"No Students in the records."<<endl;
        return;
    }
    cout<<"-----> ";
    for(int i=0; i<numStudents; i++) {
        cout<<students[i].name<<" ";
    }
    cout<<endl;
}
void insertionSort() {
    if(numStudents == 0) {
        cout<<"No Students in the records."<<endl;
        return;
    }
    for(int i=1; i<numStudents; i++) {
        string key = students[i].name;
        int j = i-1;
        while (j>=0 && (key).compare(students[j].name) < 0) {
            students[j+1].name = students[j].name;
            j = j-1;
        }
        students[j+1].name = key;
    }
    cout<<"----->Sorting Completed"<<endl;
}

int main() {
    while (true) {
        int choice;
        cout<<"1. Add Students"<<endl<<"2. Display All Students Names"<<endl<<"3. Sort The Student Name"<<endl<<"4. Exit"<<endl;
        cout<<"Enter Choice : "; cin>>choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudentsName();
                break;
            case 3:
                insertionSort();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    
    return 0;
}