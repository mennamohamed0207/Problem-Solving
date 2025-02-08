class Solution {
public:
    //First Solution got TLE and passed 47/48 testcases 
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            int k = i+1;
            bool found = false;
            while (k < n) {
                if (temperatures[i] < temperatures[k]) {
                    found = true;
                    answer[i] = k - i;
                    break;
                }
                k++;
            }
            if (!found)
                answer[i] = 0;
        }
        return answer;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
    
};