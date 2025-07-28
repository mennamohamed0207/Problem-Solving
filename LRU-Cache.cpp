// class LRUCache {
// private:
//     int capacity;
//     map<pair<int, int>, int> cache;

// public:
//     LRUCache(int capacity) { this->capacity = capacity; }

//     int get(int key) {
//         for (auto element : cache) {
//             cout << "Visited: " << element.second << " " << "key is "
//                  << element.first.first << " value is " << element.first.second
//                  << endl;
//         }
//         cout << "ended" << endl;
//         for (auto it = cache.begin(); it != cache.end(); ++it) {
//             if (it->first.first == key) {
//                 int value = it->first.second;
//                 int freq = it->second;
//                 cache.erase(it);
//                 cache.insert({{key, value}, freq + 1});
//                 return value;
//             }
//         }

//         return -1;
//     }

//     void put(int key, int value) {
//         for (auto it = cache.begin(); it != cache.end(); ++it) {
//             if (it->first.first == key) {
//                 int freq = it->second;
//                 cache.erase(it);
//                 cache.insert({{key, value}, freq + 1});
//                 return;
//             }
//         }

//         cout << "Cache size is " << cache.size() << endl;
//         if (cache.size() < this->capacity) {
//             // cache.erase(cache.begin()->first);
//             cache.insert(pair(pair(key, value), 0));
//         } else {
//             int min = INT_MAX;
//             auto LRU_it = cache.begin();
//             for (auto it = cache.begin(); it != cache.end(); ++it) {
//                 if (it->second <= min) {
//                     min = it->second;
//                     LRU_it = it;
//                 }
//             }
//             cache.erase(LRU_it);

//             cache.insert(pair(pair(key, value), 0));
//         }
//         // for (auto element : cache) {
//         //     cout << "Visited: " << element.first << " " << "key is "
//         //          << element.second.first << " value is "
//         //          << element.second.second << endl;
//         // }
//         // cout<<"ended"<<endl;
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Doubly linked list: stores keys in usage order (most recent at front)
    list<int> usage;

    // Hash map: key -> (value, iterator to usage list)
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // Move key to front (most recently used)
        usage.erase(cache[key].second);
        usage.push_front(key);
        cache[key].second = usage.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move key to front
            usage.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            // Remove least recently used key
            int lru_key = usage.back();
            usage.pop_back();
            cache.erase(lru_key);
        }

        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }
};
