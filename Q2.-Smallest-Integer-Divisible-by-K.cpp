1class Solution {
2public:
3    int smallestRepunitDivByK(int k) {
4        if (k % 2 == 0 || k % 5 == 0) return -1;
5
6        int rem = 0;
7        for (int len = 1; len <= k; len++) {
8            rem = (rem * 10 + 1) % k;
9            if (rem == 0) return len;
10        }
11
12        return -1; // theoretically never reached for valid k
13    }
14};
15