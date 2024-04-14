#include<iostream>
using namespace std;

struct Book {
    string title;
    string author;
    long int ISBN;
    double price;
};

const int MAX_BOOKS = 100;
Book book[MAX_BOOKS];
int numBooks = 0;

void addBookDetails() {
    if(numBooks>=MAX_BOOKS) {
        cout<<"Maximum number of Books reached"<<endl;
    }
    Book& b = book[numBooks++];
    cout<<"Enter-> Title, Author, ISBN, Price : "<<endl;
    cin>>b.title>>b.author>>b.ISBN>>b.price;
}

void searchBook() {
    int value;
    cout<<"Enter ISBN : ";
    cin>>value;
    for(int i=0; i<numBooks; i++) {
        if(book[i].ISBN == value) {
            cout<<">---Details of Book---<"<<endl;
            cout<<book[i].title<<endl<<book[i].author<<endl<<book[i].ISBN<<endl<<book[i].price<<endl;
            return;
        }
    }
}

int main() {
    cout<<">----------------<"<<endl;
    cout<<"1. Add Book Detail"<<endl<<"2. Search Book by ISBN"<<endl<<"3. Exit"<<endl;
    while (true) {
        int choice;
        cout<<"Enter one Option : ";
        cin>>choice;
        switch(choice) {
            case 1: addBookDetails();
                    break;
            case 2: searchBook();
                    break;
            case 3: return 0;
            default: "Enter valid Option!";
        }
    }

    return 0;
}