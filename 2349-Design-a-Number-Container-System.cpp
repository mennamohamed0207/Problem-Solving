// #include <unordered_map>
// #include <set>
// class NumberContainers {
// public:
//     vector<int> vec;
//     unordered_map<int,int>map;
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number) {
        
//         map[index]=number;
//     }
    
//     int find(int number) {
//         int minIndex=INT_MAX;
//         for(auto pair:map)
//         {
//             if(pair.second==number) 
//             {
//                 minIndex=min(minIndex,pair.first);
//             }

//         }
//         if(minIndex==INT_MAX)
//         return -1;
//         else return minIndex;
//     }
// };

// /**
//  * Your NumberContainers object will be instantiated and called as such:
//  * NumberContainers* obj = new NumberContainers();
//  * obj->change(index,number);
//  * int param_2 = obj->find(number);
//  */
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
private:
    // Maps an index to its current number.
    unordered_map<int, int> indexToNumber;
    // Maps a number to a set of indices where it appears.
    unordered_map<int, set<int>> numberToIndices;
    
public:
    NumberContainers() { }
    
    void change(int index, int number) {
        // If the index already has a number, remove it from that number's set.
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
        }
        // Update the index to the new number.
        indexToNumber[index] = number;
        // Insert the index into the set for the new number.
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        // If there are no indices for the number or the set is empty, return -1.
        if (numberToIndices.find(number) == numberToIndices.end() || numberToIndices[number].empty()) {
            return -1;
        }
        // The smallest index is the first element in the sorted set.
        return *numberToIndices[number].begin();
    }
};
