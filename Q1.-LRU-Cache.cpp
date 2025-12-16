1// class LRUCache {
2// private:
3//     int capacity;
4//     map<pair<int, int>, int> cache;
5
6// public:
7//     LRUCache(int capacity) { this->capacity = capacity; }
8
9//     int get(int key) {
10//         for (auto element : cache) {
11//             cout << "Visited: " << element.second << " " << "key is "
12//                  << element.first.first << " value is " << element.first.second
13//                  << endl;
14//         }
15//         cout << "ended" << endl;
16//         for (auto it = cache.begin(); it != cache.end(); ++it) {
17//             if (it->first.first == key) {
18//                 int value = it->first.second;
19//                 int freq = it->second;
20//                 cache.erase(it);
21//                 cache.insert({{key, value}, freq + 1});
22//                 return value;
23//             }
24//         }
25
26//         return -1;
27//     }
28
29//     void put(int key, int value) {
30//         for (auto it = cache.begin(); it != cache.end(); ++it) {
31//             if (it->first.first == key) {
32//                 int freq = it->second;
33//                 cache.erase(it);
34//                 cache.insert({{key, value}, freq + 1});
35//                 return;
36//             }
37//         }
38
39//         cout << "Cache size is " << cache.size() << endl;
40//         if (cache.size() < this->capacity) {
41//             // cache.erase(cache.begin()->first);
42//             cache.insert(pair(pair(key, value), 0));
43//         } else {
44//             int min = INT_MAX;
45//             auto LRU_it = cache.begin();
46//             for (auto it = cache.begin(); it != cache.end(); ++it) {
47//                 if (it->second <= min) {
48//                     min = it->second;
49//                     LRU_it = it;
50//                 }
51//             }
52//             cache.erase(LRU_it);
53
54//             cache.insert(pair(pair(key, value), 0));
55//         }
56//         // for (auto element : cache) {
57//         //     cout << "Visited: " << element.first << " " << "key is "
58//         //          << element.second.first << " value is "
59//         //          << element.second.second << endl;
60//         // }
61//         // cout<<"ended"<<endl;
62//     }
63// };
64
65/**
66 * Your LRUCache object will be instantiated and called as such:
67 * LRUCache* obj = new LRUCache(capacity);
68 * int param_1 = obj->get(key);
69 * obj->put(key,value);
70 */
71#include <unordered_map>
72#include <list>
73using namespace std;
74
75class LRUCache {
76private:
77    int capacity;
78
79    // Doubly linked list: stores keys in usage order (most recent at front)
80    list<int> usage;
81
82    // Hash map: key -> (value, iterator to usage list)
83    unordered_map<int, pair<int, list<int>::iterator>> cache;
84
85public:
86    LRUCache(int capacity) {
87        this->capacity = capacity;
88    }
89
90    int get(int key) {
91        if (cache.find(key) == cache.end())
92            return -1;
93
94        usage.erase(cache[key].second);
95        usage.push_front(key);
96        cache[key].second = usage.begin();
97
98        return cache[key].first;
99    }
100
101    void put(int key, int value) {
102        if (cache.find(key) != cache.end()) {
103            usage.erase(cache[key].second);
104        } else if (cache.size() == capacity) {
105            int lru_key = usage.back();
106            usage.pop_back();
107            cache.erase(lru_key);
108        }
109
110        usage.push_front(key);
111        cache[key] = {value, usage.begin()};
112    }
113};
114