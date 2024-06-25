/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/
class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {}

    void addNum(int num) {
        if (arr.empty())
            arr.push_back(num);
        else {
            int index = -1;
            for (int i = 0; i < arr.size(); i++) {
                if (num > arr[i]) {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                arr.push_back(num);
            else {
                arr.insert(arr.begin() + index, num); // O(n)
            }
        }
    }

    double findMedian() {
        // sort(arr.begin(), arr.end());
        int index = arr.size() / 2;
        if (arr.size() % 2 == 1) {
            return arr[arr.size() / 2];
        } else {
            return (arr[index] + arr[index - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//Second Solution to addNum function better one
 void addNum(int num) {
        auto it = std::lower_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num); // O(n) due to insertion
    }
