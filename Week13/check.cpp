#include <iostream>
#include <string>
#define TABLE_SIZE 11 

using namespace std;

struct Product {
    int id;
    string name;
    Product(int id = -1, string name = "") : id(id), name(name) {}
};

int h1(int key) {
    return key % TABLE_SIZE;
}

int h2(int key) {
    return 1 + (key % (TABLE_SIZE - 1));
}

class HashTable {
private:
    Product* table[TABLE_SIZE];
    bool occupied[TABLE_SIZE]; // to track if a slot is occupied

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
            occupied[i] = false;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
    }

    bool addProduct(int id, const string& name) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1(id) + i * h2(id)) % TABLE_SIZE;
            if (!occupied[index]) {
                table[index] = new Product(id, name);
                occupied[index] = true;
                return true;
            }
        }
        return false; // table is full
    }

    bool removeProduct(int id) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1(id) + i * h2(id)) % TABLE_SIZE;
            if (occupied[index] && table[index]->id == id) {
                delete table[index];
                table[index] = nullptr;
                occupied[index] = false;
                return true;
            }
        }
        return false; // product not found
    }

    Product* searchProduct(int id) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1(id) + i * h2(id)) % TABLE_SIZE;
            if (occupied[index] && table[index]->id == id) {
                return table[index];
            }
        }
        return nullptr; // product not found
    }

    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i]->id << " - " << table[i]->name << endl;
            } else {
                cout << "Index " << i << ": empty" << endl;
            }
        }
    }
};

int main() {
    HashTable cart;
    cart.addProduct(1, "Apple");
    cart.addProduct(2, "Banana");
    cart.addProduct(3, "Orange");

    cout << "Cart contents after adding 3 products:" << endl;
    cart.displayTable();

    cart.removeProduct(2);

    cout << "\nCart contents after removing product with ID 2:" << endl;
    cart.displayTable();

    Product* product = cart.searchProduct(3);
    if (product != nullptr) {
        cout << "\nProduct found: " << product->id << " - " << product->name << endl;
    } else {
        cout << "\nProduct not found" << endl;
    }

    return 0;
}
