#include<iostream>
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

void averageGrade() {
    if(numStudents == 0) {
        cout<<"No Students in the records."<<endl;
        return;
    }
    int total = 0;
    cout<<"-----> ";
    for(int i=0; i<numStudents; i++) {
        total += students[i].grade;
    }
    cout<<(total/numStudents)<<endl;
}

int main() {
    while (true) {
        int choice;
        cout<<"1. Add Students"<<endl<<"2. Average Grade"<<endl<<"3. Exit"<<endl;
        cout<<"Enter Choice : "; cin>>choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                averageGrade();
                break;
            case 3:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}