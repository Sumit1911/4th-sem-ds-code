#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 100;

struct Book {
    char isbn[20];
    char title[100];
    char author[100];
    Book* next;

    Book(const char* i, const char* t, const char* a) : next(nullptr) {
        strncpy(isbn, i, sizeof(isbn) - 1);
        strncpy(title, t, sizeof(title) - 1);
        strncpy(author, a, sizeof(author) - 1);
        isbn[sizeof(isbn) - 1] = '\0';
        title[sizeof(title) - 1] = '\0';
        author[sizeof(author) - 1] = '\0';
    }
};

class Library {
private:
    Book* table[TABLE_SIZE];

    int hashFunction(const char* key) {
        int hash = 0;
        while (*key) {
            hash = (hash * 31 + *key) % TABLE_SIZE;
            key++;
        }
        return hash;
    }

public:
    Library() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~Library() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Book* entry = table[i];
            while (entry != nullptr) {
                Book* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
    }

    void addBook(const char* isbn, const char* title, const char* author) {
        int hashIndex = hashFunction(isbn);
        Book* newBook = new Book(isbn, title, author);
        if (table[hashIndex] == nullptr) {
            table[hashIndex] = newBook;
        } else {
            Book* entry = table[hashIndex];
            while (entry->next != nullptr) {
                entry = entry->next;
            }
            entry->next = newBook;
        }
    }

    void deleteBook(const char* isbn) {
        int hashIndex = hashFunction(isbn);
        Book* entry = table[hashIndex];
        Book* prev = nullptr;

        while (entry != nullptr && strcmp(entry->isbn, isbn) != 0) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            cout << "Book with ISBN " << isbn << " not found." << endl;
            return;
        } else {
            if (prev == nullptr) {
                table[hashIndex] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            cout << "Book with ISBN " << isbn << " deleted." << endl;
        }
    }

    void searchBook(const char* isbn) {
        int hashIndex = hashFunction(isbn);
        Book* entry = table[hashIndex];

        while (entry != nullptr) {
            if (strcmp(entry->isbn, isbn) == 0) {
                cout << "Title: " << entry->title << ", Author: " << entry->author << endl;
                return;
            }
            entry = entry->next;
        }

        cout << "Book not found." << endl;
    }
};

int main() {
    Library lib;
    lib.addBook("1234567890", "The Great Gatsby", "F. Scott Fitzgerald");
    lib.addBook("0987654321", "To Kill a Mockingbird", "Harper Lee");
    lib.addBook("5555555555", "1984", "George Orwell");

    lib.searchBook("1234567890");
    lib.searchBook("0987654321");
    lib.searchBook("5555555555");
    lib.searchBook("1111111111");

    lib.deleteBook("0987654321");
    lib.searchBook("0987654321");

    return 0;
}
