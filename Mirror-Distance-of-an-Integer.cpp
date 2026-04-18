1class Solution {
2private:
3    int reverse(int n) {
4        vector<int> digits;
5        while (n > 0) {
6            int digit = n % 10;
7            digits.push_back(digit);
8            n = n / 10;
9        }
10        int result=0;
11        for (int i = digits.size()-1; i >=0; i--) {
12            result+=digits[i]*pow(10,digits.size()-i-1);
13        }
14        cout<<result<<endl;
15
16        return result;
17    }
18
19public:
20    int mirrorDistance(int n) { 
21        return abs(n - reverse(n)); }
22};