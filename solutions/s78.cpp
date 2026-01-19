#include "lib.h"

using namespace std;

class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> iter_map;
    list<pair<int, int>> lru;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!iter_map.count(key)) return -1;
        auto it = iter_map[key];
        lru.splice(lru.begin(), lru, it);
        return it->second;
    }
    
    void put(int key, int value) {
        bool found = iter_map.count(key);
        auto it = iter_map[key];
        if (found) {
            it->second = value;
            lru.splice(lru.begin(), lru, it);
        } else {
            if (lru.size() == cap) {
                auto tail = --lru.end();
                iter_map.erase(tail->first);
                lru.erase(tail);
            }
            lru.insert(lru.begin(), {key, value});
            iter_map[key] = lru.begin();
        }
    }
};

int main() {
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
