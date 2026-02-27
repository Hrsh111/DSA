/*
 * Consistent Hashing Implementation
 *
 * System Design Relevance: Used in distributed caching (Memcached),
 * databases (Cassandra, DynamoDB), CDNs for load distribution.
 *
 * This implementation uses virtual nodes for even distribution.
 */
#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

class ConsistentHash {
    map<size_t, string> ring;         // hash → server name
    int virtualNodes;                  // virtual nodes per server
    hash<string> hasher;

    size_t getHash(const string& key) {
        return hasher(key);
    }

public:
    ConsistentHash(int vnodes = 150) : virtualNodes(vnodes) {}

    void addServer(const string& server) {
        for (int i = 0; i < virtualNodes; i++) {
            string vnode = server + "#" + to_string(i);
            ring[getHash(vnode)] = server;
        }
        cout << "Added server: " << server << " (" << virtualNodes << " virtual nodes)" << endl;
    }

    void removeServer(const string& server) {
        for (int i = 0; i < virtualNodes; i++) {
            string vnode = server + "#" + to_string(i);
            ring.erase(getHash(vnode));
        }
        cout << "Removed server: " << server << endl;
    }

    string getServer(const string& key) {
        if (ring.empty()) return "";
        size_t h = getHash(key);
        auto it = ring.lower_bound(h);
        if (it == ring.end()) it = ring.begin(); // wrap around
        return it->second;
    }
};

int main() {
    ConsistentHash ch(3); // 3 virtual nodes for demo

    ch.addServer("Server-A");
    ch.addServer("Server-B");
    ch.addServer("Server-C");

    // Route some keys
    vector<string> keys = {"user:1", "user:2", "user:3", "post:100", "session:abc"};
    cout << "\n--- Key Routing ---" << endl;
    for (auto& key : keys) {
        cout << key << " → " << ch.getServer(key) << endl;
    }

    // Remove a server — see minimal key remapping
    cout << endl;
    ch.removeServer("Server-B");
    cout << "\n--- After removing Server-B ---" << endl;
    for (auto& key : keys) {
        cout << key << " → " << ch.getServer(key) << endl;
    }

    return 0;
}
