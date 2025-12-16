1class Solution {
2public:
3   vector<int> primeFactors(int n) {
4    vector<int> factors;
5
6    // Handle negative numbers by adding -1 to the factors list
7    if (n < 0) {
8        factors.push_back(-1);
9        n = -n; // Make n positive for further processing
10    }
11
12    // Check for number of 2s
13    while (n % 2 == 0) {
14        factors.push_back(2);
15        n = n / 2;
16    }
17
18    // Check for odd factors starting from 3
19    for (long long i = 3; i * i <= n; i += 2) {
20        while (n % i == 0) {
21            factors.push_back(i);
22            n = n / i;
23        }
24    }
25
26    // If n is a prime number and greater than 2
27    if (n > 2) {
28        factors.push_back(n);
29    }
30
31    return factors;
32}
33    bool isUgly(int n) {
34        if(n==pow(2,31)*-1) return false;
35        if(n==0) return false;
36       
37        vector<int> factors = primeFactors(n);
38        for (int i = 0; i < factors.size(); i++) {
39            cout << factors[i] << " ";
40            if (factors[i] != 2 && factors[i] != 3 && factors[i] != 5)
41                return false;
42        }
43        return true;
44    }
45};