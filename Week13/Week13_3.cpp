#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 100;
const int C1 = 1;
const int C2 = 3;

struct DNSRecord {
    char domain[100];
    char ipAddress[16];
    bool isDeleted;
    
    DNSRecord() : isDeleted(false) {
        domain[0] = '\0';
        ipAddress[0] = '\0';
    }
};

class DNSCache {
private:
    DNSRecord table[TABLE_SIZE];

    int hashFunction(const char* key) {
        int hash = 0;
        while (*key) {
            hash += *key;
            key++;
        }
        return hash % TABLE_SIZE;
    }

public:
    DNSCache() {}

    void insert(const char* domain, const char* ipAddress) {
        int hashIndex = hashFunction(domain);
        int i = 0;

        while (table[(hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE].domain[0] != '\0' &&
               !table[(hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE].isDeleted) {
            i++;
        }

        int index = (hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
        strncpy(table[index].domain, domain, sizeof(table[index].domain) - 1);
        strncpy(table[index].ipAddress, ipAddress, sizeof(table[index].ipAddress) - 1);
        table[index].isDeleted = false;
    }

    const char* lookup(const char* domain) {
        int hashIndex = hashFunction(domain);
        int i = 0;

        while (table[(hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE].domain[0] != '\0') {
            int index = (hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
            if (!table[index].isDeleted && strcmp(table[index].domain, domain) == 0) {
                return table[index].ipAddress;
            }
            i++;
        }

        return "IP address not found.";
    }

    void update(const char* domain, const char* newIpAddress) {
        int hashIndex = hashFunction(domain);
        int i = 0;

        while (table[(hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE].domain[0] != '\0') {
            int index = (hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
            if (!table[index].isDeleted && strcmp(table[index].domain, domain) == 0) {
                strncpy(table[index].ipAddress, newIpAddress, sizeof(table[index].ipAddress) - 1);
                return;
            }
            i++;
        }

        cout << "Domain not found. Cannot update IP address." << endl;
    }

    void remove(const char* domain) {
        int hashIndex = hashFunction(domain);
        int i = 0;

        while (table[(hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE].domain[0] != '\0') {
            int index = (hashIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
            if (!table[index].isDeleted && strcmp(table[index].domain, domain) == 0) {
                table[index].isDeleted = true;
                cout << "Domain " << domain << " removed." << endl;
                return;
            }
            i++;
        }

        cout << "Domain not found. Cannot remove." << endl;
    }
};

int main() {
    DNSCache dnsCache;
    dnsCache.insert("example.com", "93.184.216.34");
    dnsCache.insert("google.com", "172.217.16.196");
    dnsCache.insert("openai.com", "104.244.42.3");

    cout << "example.com: " << dnsCache.lookup("example.com") << endl;
    cout << "google.com: " << dnsCache.lookup("google.com") << endl;
    cout << "openai.com: " << dnsCache.lookup("openai.com") << endl;
    cout << "yahoo.com: " << dnsCache.lookup("yahoo.com") << endl;

    dnsCache.update("example.com", "93.184.216.35");
    cout << "example.com after update: " << dnsCache.lookup("example.com") << endl;

    dnsCache.remove("google.com");
    cout << "google.com after removal: " << dnsCache.lookup("google.com") << endl;

    return 0;
}
