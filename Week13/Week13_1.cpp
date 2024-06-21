#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

struct Contact {
    string name;
    string phoneNumber;
    bool isDeleted;
    
    Contact() : name(""), phoneNumber(""), isDeleted(false) {}
    Contact(string n, string p) : name(n), phoneNumber(p), isDeleted(false) {}
};

class PhoneBook {
private:
    vector<Contact> table;
    
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }
    
public:
    PhoneBook() {
        table.resize(TABLE_SIZE);
    }
    
    void addContact(string name, string phoneNumber) {
        int hashIndex = hashFunction(name);
        int i = 0;
        while (table[(hashIndex + i) % TABLE_SIZE].name != "" && !table[(hashIndex + i) % TABLE_SIZE].isDeleted) {
            i++;
        }
        table[(hashIndex + i) % TABLE_SIZE] = Contact(name, phoneNumber);
    }
    
    string searchContact(string name) {
        int hashIndex = hashFunction(name);
        int i = 0;
        while (table[(hashIndex + i) % TABLE_SIZE].name != "" && table[(hashIndex + i) % TABLE_SIZE].name != name) {
            i++;
            if (i >= TABLE_SIZE) return "Contact not found";
        }
        if (table[(hashIndex + i) % TABLE_SIZE].isDeleted) return "Contact not found";
        return table[(hashIndex + i) % TABLE_SIZE].name != "" ? table[(hashIndex + i) % TABLE_SIZE].phoneNumber : "Contact not found";
    }
    
    void deleteContact(string name) {
        int hashIndex = hashFunction(name);
        int i = 0;
        while (table[(hashIndex + i) % TABLE_SIZE].name != "" && table[(hashIndex + i) % TABLE_SIZE].name != name) {
            i++;
            if (i >= TABLE_SIZE) return;
        }
        if (table[(hashIndex + i) % TABLE_SIZE].name != "") {
            table[(hashIndex + i) % TABLE_SIZE].isDeleted = true;
        }
    }
};

int main() {
    PhoneBook pb;
    pb.addContact("Alice", "1234567890");
    pb.addContact("Bob", "0987654321");
    pb.addContact("Charlie", "5555555555");
    
    cout << "Alice's number: " << pb.searchContact("Alice") << endl;
    cout << "Bob's number: " << pb.searchContact("Bob") << endl;
    cout << "Charlie's number: " << pb.searchContact("Charlie") << endl;
    
    pb.deleteContact("Bob");
    cout << "Bob's number after deletion: " << pb.searchContact("Bob") << endl;
    
    return 0;
}
