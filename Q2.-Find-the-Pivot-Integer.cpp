1class Solution {
2public:
3    int pivotInteger(int n) {
4        vector<int> right(n);
5        vector<int> left(n);
6        iota(right.begin(), right.end(), 1);
7        iota(left.begin(), left.end(), 1);
8        int rsum = 0;
9        for (int i = n - 1; i >= 0; i--) {
10            rsum += right[i];
11            right[i] = rsum;
12        }
13        int lsum = 0;
14        for (int i = 0; i < n; i++) {
15            left[i] += lsum;
16            lsum = left[i];
17        }
18        for (int i = 0; i < n; i++) {
19            if (right[i] == left[i]) {
20                return i + 1;
21            }
22        }
23        return -1;
24    }
25};